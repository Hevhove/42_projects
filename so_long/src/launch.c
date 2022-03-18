/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:17:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/18 17:40:06 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_map(t_data *data)
{
	size_t	row;
	size_t	col;
	t_img	*tile;

	row = -1;
	while (++row < data->map.height)
	{
		col = -1;
		while (++col < data->map.width)
		{
		
			if (data->map.content[row][col] == '0' || data->map.content[row][col] != '1')
			{
				tile = &data->empt;
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, tile->img, col * ASSET_SIZE, row * ASSET_SIZE);
			}
			if (data->map.content[row][col] == '1')
				tile = &data->wall;
			else if (data->map.content[row][col] == 'C')
				tile = &data->coll;
			else if (data->map.content[row][col] == 'E')
				tile = &data->exit;
			else if (data->map.content[row][col] == 'P')
				tile = &data->play;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, tile->img, col * ASSET_SIZE, row * ASSET_SIZE);
		}
	}
}

// exit_game(t_data *data)
// {
// 	// do some stuff to exit the game;
// }

int	key_press(int keycode, t_data *data)
{
	// if (keycode == 53)
	// 	exit_game(data);
	if (keycode == 0)
	{
		move_left(data);
		printf("received\n");
	}
	else if (keycode == 1)
		move_down(data);
	else if (keycode == 2)
	 	move_right(data);
	else if (keycode == 13)
		move_up(data);
	return (0);
}

void	launch(t_data *data)
{
	win_size(data);
	// ft_printf("\e[H\e[2J\e[3J");
	ft_printf("Number of steps: %d\n", data->map.steps);
	mlx_launch(data);
	load_assets(data);
	draw_map(data);
	mlx_hook(data->win_ptr, 02, (1L << 2), &key_press, data);
	printf("checker\n");
	mlx_loop(data->mlx_ptr);
}
