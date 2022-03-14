/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:33:53 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/14 15:39:38 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

int	add_shade(double distance, int color)
{
	unsigned char t;
	
	
	if (distance <= 1 && distance >= 0)
	{
		t = 255 * distance;
	}
	else
		return (1);
	return (create_trgb(t, get_r(color), get_g(color), get_b(color)));
}

int get_opposite(int color)
{
	unsigned char r, g, b;
	
	r = 255 - get_r(color);
	g = 255 - get_g(color);
	b = 255 - get_b(color);
	return (create_trgb(get_t(color), r, g, b));
}
