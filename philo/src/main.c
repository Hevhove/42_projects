/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:57:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/28 19:24:34 by hvan-hov         ###   ########.fr       */
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
	if (phil->data->num_phil > 1)
	{
		next_phil = phil->data->philos + ((phil->id + 1) % phil->data->num_phil);
		//pthread_mutex_lock(&(phil->data->die_mutex));
		while (phil->data->state == RUNNING)
		{
			// need critical section here and move to 
			// pthread_mutex_lock(&(phil->death_mutex));
			// if (check_death(phil) == 1)
			// {
			// 	printf("%llu %d died\n", get_time_micros() / 1000, phil->id + 1); // lock, finish thread
			// 	phil->data->state = END;
			// 	break ;
			// }
			// pthread_mutex_unlock(&(phil->death_mutex));
			if (phil->p_state == THINKING)
				philo_think(phil, next_phil);
			else if (phil->p_state == SLEEPING)
				philo_sleep(phil);
			else if (phil->p_state == EATING)
				philo_eat(phil, next_phil);
		}
		//pthread_mutex_unlock(&(phil->data->die_mutex));
	}
	else
	{
		usleep2(phil->data->t_die);
		phil->data->state = END;
		printf("%llu %d died\n", get_time_micros() / 1000, phil->id + 1);
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
			{
				pthread_mutex_lock(&(data->state_mutex));
				data->state = END;
				pthread_mutex_unlock(&(data->state_mutex));
			}

		}
	}
	i = 0;
	while (data->state == RUNNING)
	{
		while (i < data->num_phil)
		{
			// single mutex?
			// pthread_mutex_lock(&(data->philos[i].death_mutex));
			//pthread_mutex_lock(&(data->die_mutex));
			if (check_death(data->philos + i) == 1)
			{
				printf("%llu %d died\n", get_time_micros() / 1000, data->philos[i].id + 1); // lock, finish thread
				// mutex needed here?
				pthread_mutex_lock(&(data->state_mutex));
				data->state = END;
				pthread_mutex_unlock(&(data->state_mutex));
				// pthread_mutex_unlock(&(data->die_mutex));
				// pthread_mutex_unlock(&(data->philos[i].death_mutex));
				break ;
			}
			pthread_mutex_unlock(&(data->die_mutex));
			//pthread_mutex_unlock(&(data->philos[i].death_mutex));
			i++;
		}
		i = 0;
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
	free(data.philos);
	return (0);
}
