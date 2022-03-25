/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:57:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/25 20:12:59 by hvan-hov         ###   ########.fr       */
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

void arg_check(char **argv, t_data *data)
{
	int i;

	data->num_phil = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
	{
		data->must_check = 1;
		data->must_num = ft_atoi(argv[5]);
	}
	data->philos = malloc(data->num_phil * sizeof(t_philo));
	i = 0;
	while (i < data->num_phil)
	{
		data->philos[i].id = i;
		data->philos[i].fork = 1;
		data->philos[i].state = 's';
		i++;
	}
}

void	start_eating(t_data *data)
{
	if (data->philos[data->philos->id].fork == 1 
		&& data->philos[(data->philos->id + 1) % 5].fork == 1)
		
}

void	*routine(void *arg)
{
	int	i;
	t_data *data;
	
	i = 0;
	data = (t_data *)arg;
	pthread_mutex_lock(&(data->mutex));
	while (1)
	{
		start_eating(data);
	}
	data->check++;
	pthread_mutex_unlock(&(data->mutex));
	return (NULL);
}

void	philo(t_data *data)
{
	int				i;
	int				*a;
	i = 0;
	pthread_mutex_init(&(data->mutex), NULL);
	while (i < data->num_phil)
	{
		a = malloc(sizeof(int));
		*a = i;
		data->philos[*a].id = *a;
		if (pthread_create(&(data->philos[i].th), NULL, &routine, data) != 0)
			error_message("failed to create threads", 2);
		i++;
		//printf("check\n");
	}
	i = 0;
	while (i < data->num_phil)
	{
		if ((pthread_join(data->philos[i].th, NULL)) != 0)
			error_message("failed to join threads", 3);
		//printf("check2\n");
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
	philo(&data);
	printf("data check is: %d\n", data.check);
}
