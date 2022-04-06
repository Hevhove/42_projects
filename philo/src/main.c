/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:57:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/04/06 13:51:44 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	execute_death(t_data *data, int i)
{
	pthread_mutex_lock(&(data->state_mutex));
	printf("%llu %d died\n", get_time_micros()
		/ 1000, data->philos[i].id + 1);
	data->state = END;
	pthread_mutex_unlock(&(data->state_mutex));
	usleep2(200000);
}

void	death_and_eat_check(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_phil)
	{
		if (check_death(data->philos + i) == 1)
		{
			execute_death(data, i);
			break ;
		}
		if (data->must_check == 1)
		{
			if (check_eaten(data))
			{
				pthread_mutex_lock(&(data->state_mutex));
				data->state = END;
				pthread_mutex_unlock(&(data->state_mutex));
				usleep2(300000);
				break ;
			}
		}
		i++;
	}
}

void	status_checker(t_data *data)
{
	int	i;

	while (1)
	{
		pthread_mutex_lock(&(data->state_mutex));
		if (check_data_state(data->state) != 1)
		{
			pthread_mutex_unlock(&(data->state_mutex));
			break ;
		}
		pthread_mutex_unlock(&(data->state_mutex));
		death_and_eat_check(data);
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
}

void	philo(t_data *data)
{
	int	i;

	i = 0;
	mutex_inits(data);
	while (i < data->num_phil)
	{
		if (pthread_create(&(data->philos[i].th), NULL,
				&routine, data->philos + i) != 0)
			error_message("failed to create threads", 2);
		i++;
	}
	status_checker(data);
	mutex_destroys(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		error_message("Not enough arguments", 1);
	data.start_time = get_time_micros();
	data.state = RUNNING;
	arg_check(argv, &data);
	philo(&data);
	free(data.philos);
	return (0);
}
