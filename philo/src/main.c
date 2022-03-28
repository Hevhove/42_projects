/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:57:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/28 17:27:41 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg)
{
	int	i;
	t_philo *phil;
	t_philo	*next_phil;

	i = 0;
	phil = (t_philo *)arg;
	next_phil = phil->data->philos + ((phil->id + 1) % phil->data->num_phil);
	while (phil->data->state == RUNNING)
	{
		// need critical section here and move to 
		pthread_mutex_lock(&(phil->death_mutex));
		if (check_death(phil) == 1)
		{
			printf("%llu %d died\n", get_time_micros() / 1000, phil->id + 1); // lock, finish thread
			phil->data->state = END;
			break ;
		}
		pthread_mutex_unlock(&(phil->death_mutex));
		if (phil->p_state == THINKING)
			philo_think(phil, next_phil);
		else if (phil->p_state == SLEEPING)
			philo_sleep(phil);
		else if (phil->p_state == EATING)
			philo_eat(phil, next_phil);
	}
	return (NULL);
}

void	philo(t_data *data) // check with fsanitize
{
	int				i;

	i = 0;
	mutex_inits(data);
	while (i < data->num_phil)
	{
		if (pthread_create(&(data->philos[i].th), NULL, &routine, data->philos + i) != 0)
			error_message("failed to create threads", 2);
		i++;
	}
	if (data->must_check == 1)
	{
		while (data->state == RUNNING)
		{
			if (check_eaten(data))
				data->state = END;
		}
	}
	i = 0;
	while (data->state == RUNNING)
	{
		if (data->state == END)
		{
			while (i < data->num_phil)
			{
				if ((pthread_join(data->philos[i++].th, NULL)) != 0)
					error_message("failed to join threads", 3);
			}
		}
	}
	mutex_destroys(data);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (argc != 5 && argc != 6)
		error_message("Not enough arguments", 1);
	arg_check(argv, &data);
	data.state = RUNNING;
	data.start_time = get_time_micros();
	philo(&data);
	// free data
}
