/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:55:00 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/29 12:39:58 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	mutex_inits(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_phil)
	{
		//pthread_mutex_init(&(data->philos[i].eat_mutex), NULL);
		pthread_mutex_init(&(data->state_mutex), NULL);
		pthread_mutex_init(&(data->die_mutex), NULL);
		pthread_mutex_init(&(data->eat_mutex2), NULL);
		pthread_mutex_init(&(data->philos[i].fork.fork_mutex), NULL);
		i++;
	}
}

void	mutex_destroys(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_phil)
	{
		//pthread_mutex_destroy(&(data->philos[i].eat_mutex));
		pthread_mutex_destroy(&(data->state_mutex));
		pthread_mutex_destroy(&(data->die_mutex));
		pthread_mutex_destroy(&(data->eat_mutex2));
		pthread_mutex_destroy(&(data->philos[i].fork.fork_mutex));
		i++;
	}
}
