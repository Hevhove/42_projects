/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:41:49 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/02 20:11:32 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	long	mc;

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
