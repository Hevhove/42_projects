/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:55:00 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/28 16:55:08 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	mutex_inits(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_phil)
	{
		pthread_mutex_init(&(data->philos[i].death_mutex), NULL);
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
		pthread_mutex_destroy(&(data->philos[i].death_mutex));
		pthread_mutex_destroy(&(data->philos[i].fork.fork_mutex));
		i++;
	}
}
