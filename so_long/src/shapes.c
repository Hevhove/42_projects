/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:51:48 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/14 10:46:35 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_square(t_data *img, int posx, int posy, int length, int color)
{
	int i;

	my_mlx_pixel_put(img, posx, posy, color);
	i = 1;
	while (i < length)
	{
		my_mlx_pixel_put(img, posx + i, posy, color);
		my_mlx_pixel_put(img, posx, posy + i, color);
		i++;
	}
	i = 0;
	while (i < length)
	{
		my_mlx_pixel_put(img, posx + i, posy + length, color);
		my_mlx_pixel_put(img, posx + length, posy + i, color);
		i++;
	}
}

void	draw_circle(t_data *img, int posc, int r, int color)
{
	double i, angle, x1, y1;

	color = get_opposite(color);
	for (i = 0; i < 360; i += 0.1)
	{
		angle = i;
		x1 = posc + r * cos(angle * M_PI / 180);
		y1 = posc + r * sin(angle * M_PI / 180);
		my_mlx_pixel_put(img, x1, y1, color);
		// color = create_trgb(get_t(color), get_r(color) - 1, get_g(color) + 1, get_b(color));
	}
}
