/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:57:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/23 20:42:58 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

unsigned long long get_time_ms()
{
	struct timeval		tv;
	unsigned long long	curtime;

	gettimeofday(&tv, NULL);
	curtime = (unsigned long long)((tv.tv_sec * 1000000 + tv.tv_usec) / 1000);
	return (curtime);
}

void arg_check(char **argv, t_data *data, t_philo **philos)
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
	*philos = malloc(data->num_phil * sizeof(t_philo));
	i = 0;
	while (i < data->num_phil)
	{
		(*philos)[i].id = i;
		(*philos)[i].fork = 1;
		(*philos)[i].state = 's';
		i++;
	}
}

void	philo(t_data *data, t_philo philos)
{
	
}

int	main(int argc, char **argv)
{
	t_data data;
	t_philo *philos;
	if (argc != 5 && argc != 6)
		printf("Not enough arguments\n");
	arg_check(argv, &data, &philos);
	philo(&data, &philos);
	
}
