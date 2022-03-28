/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:31:18 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/28 16:31:28 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
		// printf("phil %d: diff is %llu\n", phil->id + 1, (get_time_micros() - phil->last_eaten) / 1000);
		// printf("last eaten time is: %llu\n", phil->last_eaten);
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
