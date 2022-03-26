/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:57:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/26 17:34:04 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	error_message(const char *msg, int exit_code)
{
	printf("%s\n", msg);
	exit(exit_code);
}

unsigned long long get_time_ms()
{
	struct timeval		tv;
	unsigned long long	curtime;

	gettimeofday(&tv, NULL);
	curtime = (unsigned long long)((tv.tv_sec * 1000000 + tv.tv_usec) / 1000);
	return (curtime);
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
	printf("%llu: philosopher %d is thinking\n", get_time_ms(), phil->id);
	(void)next_phil;
	if (grab_forks(phil, next_phil) == 1)
	{
		printf("%llu: philosopher %d has grabbed forks %d and %d\n",
		get_time_ms(), phil->id, phil->fork.owner_id, next_phil->fork.owner_id);
		phil->p_state = EATING;
	}
}

void	drop_forks(t_philo *phil, t_philo *next_phil)
{
	// TODO
}

void	philo_eat(t_philo *phil, t_philo *next_phil)
{
	printf("%llu: philosopher %d is eating\n", get_time_ms(), phil->id);
	usleep(phil->data->t_eat * 1000);
	drop_forks(phil, next_phil);
	printf("%llu: philosopher %d has stopped eating\n", get_time_ms(), phil->id);
}

void	*routine(void *arg)
{
	int	i;
	t_philo *phil;
	t_philo	*next_phil;
	
	i = 0;
	phil = (t_philo *)arg;
	next_phil = phil->data->philos + ((phil->id + 1) % phil->data->num_phil);
	// printf("curr_phil is: %d\n", phil->id);
	// printf("next phil is: %d\n", next_phil->id);

	// while state of the program is running
	// loop philosopher actions
	while (phil->data->state == RUNNING)
	{
		// attempt to grab 2 forks
		if (phil->p_state == THINKING)
			philo_think(phil, next_phil);
		// else if (phil->p_state == SLEEPING)
		// 	philo_sleep(phil);
		else if (phil->p_state = EATING)
			phil_eat(phil, next_phil);
		// spend time eating
		// spend time sleeping
		// spend time thinking (and grab again a fork)
		usleep(1000);
	}
	// pthread_mutex_lock(&(data->mutex));
	// sleep(1);
	// printf("thread is : %p\n", data->curr_id);
	// while (1)
	// {
	// 	start_eating(data);
	// }
	// pthread_mutex_unlock(&(data->mutex));
	// printf("curr phil id is : %d\n", phil->id);
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
	philo(&data);
	printf("data check is: %d\n", data.check);
}
