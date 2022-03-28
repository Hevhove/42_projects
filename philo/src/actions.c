/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:28:56 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/28 17:07:30 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_eat(t_philo *phil, t_philo *next_phil)
{
	// save timestamp of curtime start
	printf("%llu %d is eating\n", get_time_micros() / 1000, phil->id + 1);
	phil->times_eaten++;
	phil->last_eaten = get_time_micros();
	usleep2(phil->data->t_eat * 1000); // problem with usleep?
	drop_forks(phil, next_phil);
	phil->p_state = SLEEPING;
	printf("%llu %d is sleeping\n", get_time_micros() / 1000, phil->id + 1);
	usleep(250);
}

void	philo_sleep(t_philo *phil)
{
	// printf("%llu %d is sleeping\n", get_time_micros() / 1000, phil->id + 1);
	usleep2(phil->data->t_sleep * 1000); // protect from edge cases -> if dies while sleeping, what happens
	phil->p_state = THINKING;
	if (phil->data->state != END)
	{
		printf("%llu %d is thinking\n", get_time_micros() / 1000, phil->id + 1);
	}
	usleep2(250);
}

void	philo_think(t_philo *phil, t_philo *next_phil)
{
	(void)next_phil;
	if (grab_forks(phil, next_phil) == 1 && phil->data->state != END)
	{
		phil->p_state = EATING;
	}
	// usleep2(1000);
}

int	grab_forks(t_philo *phil, t_philo *next_phil)
{
	int ret;

	ret = 0;
	pthread_mutex_lock(&(next_phil->fork.fork_mutex));
	pthread_mutex_lock(&(phil->fork.fork_mutex));
	if (phil->fork.in_use == 0 && next_phil->fork.in_use == 0)
	{
		phil->fork.in_use = 1;
		printf("%llu %d has taken a fork\n", get_time_micros() / 1000, phil->id + 1);
		next_phil->fork.in_use = 1;
		printf("%llu %d has taken a fork\n", get_time_micros() / 1000, phil->id + 1);
		//printf("%llu %d has taken forks %d and %d\n", get_time_micros() / 1000, phil->id + 1, phil->fork.owner_id + 1, next_phil->fork.owner_id + 1);
		ret = 1;
	}
	pthread_mutex_unlock(&(phil->fork.fork_mutex));
	pthread_mutex_unlock(&(next_phil->fork.fork_mutex));
	return (ret);
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
