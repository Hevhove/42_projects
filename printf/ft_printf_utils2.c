/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:28:42 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/12/05 20:31:22 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(size_t i)
{
	if (i > 9)
	{
		ft_putunbr(i / 10);
	}
	ft_putchar(i % 10 + '0');
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
