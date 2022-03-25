/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:12:39 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/23 20:33:21 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HEADERS
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

// STRUCTS
typedef struct s_data {
	int num_phil;
	int t_die; // in microseconds
	int t_eat; // in microseconds
	int t_sleep; // in microseconds
	int	must_check;
	int must_num;
}	t_data;

typedef struct s_philo {
	int		id;
	int		fork;
	char	state;
}	t_philo;

// FUNCTION PROTOTYPES
int	ft_atoi(const char *str);
