/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:17:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/17 19:17:31 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_map(t_data *data)
{
	size_t	row;
	size_t	col;
	t_img	*tile;

	row = -1;
	printf("test\n");
	while (++row < data->map.height)
	{
		col = -1;
		while (++col < data->map.width)
		{
			if (data->map.content[row][col] == '0')
				tile = &data->empt;
			else if (data->map.content[row][col] == '1')
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

exit_game(t_data *data)
{
	// do some stuff to exit the game;
}

void	key_press(t_data *data, int keycode)
{
	// if (keycode == 53)
	// 	exit_game(data);
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		make_move(data, keycode);
}

void	launch(t_data *data)
{
	win_size(data);
	// ft_printf("\e[H\e[2J\e[3J");
	ft_printf("Number of steps: %d\n", data->map.steps);
	mlx_launch(data);
	load_assets(data);
	draw_map(data);
	mlx_hook(data->win_ptr, 02, 1L << 2, &key_press, data);
	mlx_loop(data->mlx_ptr);
}
