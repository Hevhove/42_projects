/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:57:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/04/06 12:18:45 by Hendrik          ###   ########.fr       */
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

void	philo(t_data *data)
{
	int	i;

	i = 0;
	mutex_inits(data);
	while (i < data->num_phil)
	{
		if (pthread_create(&(data->philos[i].th), NULL, &routine, data->philos + i) != 0)
			error_message("failed to create threads", 2);
		i++;
	}
	while (1)
	{
		pthread_mutex_lock(&(data->state_mutex));
		if (check_data_state(data->state) != 1)
		{
			pthread_mutex_unlock(&(data->state_mutex));
			break ;
		}
		pthread_mutex_unlock(&(data->state_mutex));
		i = 0;
		while (i < data->num_phil)
		{
			if (check_death(data->philos + i) == 1)
			{
				pthread_mutex_lock(&(data->state_mutex));
				printf("%llu %d died\n", get_time_micros() / 1000, data->philos[i].id + 1);
				data->state = END;
				pthread_mutex_unlock(&(data->state_mutex));
				usleep2(200000);
				break ;
			}
			if (data->must_check == 1)
			{
				if (check_eaten(data))
				{
					// printf("passed here!\n");
					pthread_mutex_lock(&(data->state_mutex));
					// printf("philos have eaten %d times\n", data->philos->times_eaten);
					data->state = END;
					pthread_mutex_unlock(&(data->state_mutex));
					usleep2(300000);
					break ;
				}
			}
			i++;
		}
		pthread_mutex_lock(&(data->state_mutex));
		if (data->state == END)
		{
			i = 0;
			while (i < data->num_phil)
			{
				if ((pthread_join(data->philos[i].th, NULL)) != 0)
					error_message("failed to join threads", 3);
				i++;
			}
		}
		pthread_mutex_unlock(&(data->state_mutex));
	}
	mutex_destroys(data);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (argc != 5 && argc != 6)
		error_message("Not enough arguments", 1);
	data.start_time = get_time_micros();
	data.state = RUNNING;
	arg_check(argv, &data);
	philo(&data);
	free(data.philos);
	return (0);
}
