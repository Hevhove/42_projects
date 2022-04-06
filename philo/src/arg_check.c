/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:32:41 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/04/04 10:30:00 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void arg_check(char **argv, t_data *data)
{
	int i;

	data->num_phil = ft_atoi(argv[1]);
	data->t_die = (unsigned long long)ft_atoi(argv[2]);
	data->t_eat = (unsigned long long)ft_atoi(argv[3]);
	data->t_sleep = (unsigned long long)ft_atoi(argv[4]);
	if (data->num_phil < 1 || data->t_die < 1
		|| data->t_eat < 1 || data->t_sleep < 1)
		error_message("Inputs must be greater than 1", 4);
	if (argv[5] != NULL)
	{
		data->must_check = 1;
		data->must_num = ft_atoi(argv[5]);
	}
	else
	{
		data->must_check = 0;
		data->must_num = 0;
	}
	data->philos = malloc(data->num_phil * sizeof(t_philo));
	i = 0;
	while (i < data->num_phil)
	{
		data->philos[i].id = i;
		data->philos[i].fork.owner_id = i;
		data->philos[i].fork.in_use = 0;
		data->philos[i].p_state = THINKING;
		data->philos[i].times_eaten = 0;
		data->philos[i].data = data;
		data->philos[i].last_eaten = data->start_time;
		// printf("%llu phil_%d last eaten\n", data->philos[i].last_eaten, data->philos[i].id + 1);
		i++;
	}
}
