/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:00:13 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/23 19:02:46 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	is_space(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	mc;

	result = 0;
	mc = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		mc = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0' && *str <= '9' && *str >= '0')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * mc);
}
