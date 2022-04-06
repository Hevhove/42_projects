/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:51:37 by Hendrik           #+#    #+#             */
/*   Updated: 2022/04/06 13:51:57 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_loop(t_philo *phil, t_philo *next_phil)
{
	while (1)
	{
		pthread_mutex_lock(&(phil->data->state_mutex));
		if (check_data_state(phil->data->state) != 1)
		{
			pthread_mutex_unlock(&(phil->data->state_mutex));
			break ;
		}
		pthread_mutex_unlock(&(phil->data->state_mutex));
		if (phil->p_state == THINKING)
			philo_think(phil, next_phil);
		else if (phil->p_state == SLEEPING)
			philo_sleep(phil);
		else if (phil->p_state == EATING)
			philo_eat(phil, next_phil);
	}
}

void	*routine(void *arg)
{
	int		i;
	t_philo	*phil;
	t_philo	*next_phil;

	i = 0;
	phil = (t_philo *)arg;
	if (phil->data->num_phil > 1)
	{
		next_phil = phil->data->philos
			+ ((phil->id + 1) % phil->data->num_phil);
		philo_loop(phil, next_phil);
	}
	else
	{
		usleep2(phil->data->t_die);
		pthread_mutex_lock(&(phil->data->state_mutex));
		phil->data->state = END;
		pthread_mutex_unlock(&(phil->data->state_mutex));
		printf("%llu %d died\n", get_time_micros() / 1000, phil->id + 1);
	}
	return (NULL);
}
