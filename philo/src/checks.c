/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:31:18 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/04/05 11:22:25 by Hendrik          ###   ########.fr       */
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
		pthread_mutex_lock(&(data->eat_mutex2));
		if (data->philos[i].times_eaten < data->must_num)
		{
			pthread_mutex_unlock(&(data->eat_mutex2));
			return (0);
		}
		pthread_mutex_unlock(&(data->eat_mutex2));
		i++;
	}
	return (1);
}

int	check_death(t_philo *phil)
{
	pthread_mutex_lock(&(phil->data->eat_mutex2));
	if (phil->times_eaten != 0)
	{
		//printf("phil %d: diff is %llu\n", phil->id + 1, (get_time_micros() - phil->last_eaten) / 1000);
		//printf("last eaten time is: %llu\n", phil->last_eaten);
		//printf("%d death check: %llu vs t_die: %llu\n", phil->id, get_time_micros() - phil->last_eaten, phil->data->t_die * 1000);
		if (get_time_micros() - phil->last_eaten > (phil->data->t_die * 1000))
			return (1);
	}
	else
	{
		if (get_time_micros() - phil->data->start_time > (phil->data->t_die * 1000))
			return (1);
	}
	pthread_mutex_unlock(&(phil->data->eat_mutex2));
	return (0);
}

int check_data_state(t_status status)
{
	if (status == RUNNING)
		return (1);
	else
		return (0);
}
