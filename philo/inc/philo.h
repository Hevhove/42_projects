/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:12:39 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/26 20:01:49 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HEADERS
#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

// STRUCTS

typedef enum	e_status
{
	SLEEPING,
	EATING,
	THINKING,
	RUNNING,
	END
}	t_status;

typedef struct	s_fork {
	int				owner_id;
	int				in_use;
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef struct s_philo {
	int					id;
	t_fork				fork;
	pthread_t			th;
	struct s_data		*data;
	t_status			p_state;
	int					times_eaten;
	unsigned long long	last_eaten;
}	t_philo;

typedef struct s_data {
	int 				num_phil;
	unsigned long long 	t_die; // in milliseconds
	unsigned long long 	t_eat; // in milliseconds
	unsigned long long	t_sleep; // in milliseconds
	int					must_check;
	int 				must_num;
	int					id_pass;
	t_philo				*philos;
	pthread_mutex_t		mutex;
	int					check;
	int					*curr_id;
	t_status			state;
	unsigned long long	start_time;
}	t_data;

// FUNCTION PROTOTYPES
int	ft_atoi(const char *str);
void arg_check(char **argv, t_data *data);
void	error_message(const char *msg, int exit_code);

#endif
