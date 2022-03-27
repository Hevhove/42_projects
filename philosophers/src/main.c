/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:57:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/27 14:51:26 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	error_message(const char *msg, int exit_code)
{
	printf("%s\n", msg);
	exit(exit_code);
}

unsigned long long get_time_micros()
{
	struct timeval		tv;
	unsigned long long	curtime;

	gettimeofday(&tv, NULL);
	curtime = (unsigned long long)((tv.tv_sec * 1000000 + tv.tv_usec));
	return (curtime); // in microseconds
}

int	grab_forks(t_philo *phil, t_philo *next_phil)
{
	int ret;

	ret = 0;
	pthread_mutex_lock(&(phil->fork.fork_mutex));
	pthread_mutex_lock(&(next_phil->fork.fork_mutex));
	if (phil->fork.in_use == 0 && next_phil->fork.in_use == 0)
	{
		phil->fork.in_use = 1;
		next_phil->fork.in_use = 1;
		ret = 1;
	}
	pthread_mutex_unlock(&(phil->fork.fork_mutex));
	pthread_mutex_unlock(&(next_phil->fork.fork_mutex));
	return (ret);
}

void	philo_think(t_philo *phil, t_philo *next_phil)
{
	(void)next_phil;
	if (grab_forks(phil, next_phil) == 1)
	{
		printf("%llu: philosopher %d has grabbed forks %d and %d\n",
		get_time_micros() / 1000, phil->id + 1, phil->fork.owner_id + 1, next_phil->fork.owner_id + 1);
		phil->p_state = EATING;
	}
}

void	drop_forks(t_philo *phil, t_philo *next_phil)
{
	pthread_mutex_lock(&(phil->fork.fork_mutex));
	pthread_mutex_lock(&(next_phil->fork.fork_mutex));
	if (phil->fork.in_use == 1 && next_phil->fork.in_use == 1)
	{
		phil->fork.in_use = 0;
		next_phil->fork.in_use = 0;
	}
	pthread_mutex_unlock(&(phil->fork.fork_mutex));
	pthread_mutex_unlock(&(next_phil->fork.fork_mutex));
}

void	philo_eat(t_philo *phil, t_philo *next_phil)
{
	printf("%llu: philosopher %d is eating\n", get_time_micros() / 1000, phil->id + 1);
	phil->times_eaten++;
	phil->last_eaten = get_time_micros();
	usleep(phil->data->t_eat * 1000);
	drop_forks(phil, next_phil);
	printf("%llu: philosopher %d has stopped eating\n", get_time_micros() / 1000, phil->id + 1);
	phil->p_state = SLEEPING;
}

void	philo_sleep(t_philo *phil)
{
	printf("%llu: philosopher %d is sleeping\n", get_time_micros() / 1000, phil->id + 1);
	usleep(phil->data->t_sleep * 1000);
	phil->p_state = THINKING;
	printf("%llu: philosopher %d is thinking\n", get_time_micros() / 1000, phil->id + 1);
}

int	check_eaten(t_data *data)
{
	int	i;
	int check;

	i = 0;
	check = 1;
	while (i < data->num_phil)
	{
		if (data->philos[i].times_eaten < data->must_num)
			return (0);
		i++;
	}
	return (1);
}

int	check_death(t_philo *phil)
{
	if (phil->times_eaten != 0)
	{
		printf("phil %d: diff is %llu\n", phil->id + 1, get_time_micros() - phil->last_eaten);
		printf("last eaten time is: %llu\n", phil->last_eaten);
		if (get_time_micros() - phil->last_eaten > (phil->data->t_die * 1000))
		{
			return (1);
		}
	}
	else
	{
		if (get_time_micros() - phil->data->start_time > (phil->data->t_die * 1000))
			return (1);
	}
	return (0);
}

void	*routine(void *arg)
{
	int	i;
	t_philo *phil;
	t_philo	*next_phil;

	i = 0;
	phil = (t_philo *)arg;
	next_phil = phil->data->philos + ((phil->id + 1) % phil->data->num_phil);
	while (phil->data->state == RUNNING)
	{
		if (check_death(phil) == 1)
		{
			printf("philo %d has died!\nSimulation stopped!\n", phil->id + 1);
			exit(5);
		}
		if (phil->p_state == THINKING)
			philo_think(phil, next_phil);
		else if (phil->p_state == SLEEPING)
			philo_sleep(phil);
		else if (phil->p_state == EATING)
			philo_eat(phil, next_phil);
		if (phil->data->must_check == 1)
		{
			if (check_eaten(phil->data))
			{
				for (int i = 0; i < 5; i++)
					printf("philo %d eaten times: %d\n", phil->data->philos[i].id, phil->data->philos[i].times_eaten);
				printf("simulation stopped!\n");
				exit(6);
			}
		}
	}
	return (NULL);
}

void	philo(t_data *data)
{
	int				i;

	i = 0;
	pthread_mutex_init(&(data->mutex), NULL);
	while (i < data->num_phil)
	{
		if (pthread_create(&(data->philos[i].th), NULL, &routine, data->philos + i) != 0)
			error_message("failed to create threads", 2);
		i++;
	}
	i = 0;
	while (i < data->num_phil)
	{
		if ((pthread_join(data->philos[i].th, NULL)) != 0)
			error_message("failed to join threads", 3);
		i++;
	}
	pthread_mutex_destroy(&(data->mutex));
}

int	main(int argc, char **argv)
{
	t_data data;

	data.check = 0;
	if (argc != 5 && argc != 6)
		error_message("Not enough arguments", 1);
	arg_check(argv, &data);
	data.state = RUNNING;
	data.start_time = get_time_micros();
	philo(&data);
	printf("data check is: %d\n", data.check);
}
