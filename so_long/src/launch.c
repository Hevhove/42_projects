/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:17:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/22 09:35:03 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_map(t_data *data, size_t row, size_t col)
{
	t_img	*tile;

	row = -1;
	while (++row < data->map.height)
	{
		col = -1;
		while (++col < data->map.width)
		{
			tile = &data->empt;
			if (data->map.content[row][col] != '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					tile->img, col * ASSET_SIZE, row * ASSET_SIZE);
			if (data->map.content[row][col] == '1')
				tile = &data->wall;
			else if (data->map.content[row][col] == 'C')
				tile = &data->coll;
			else if (data->map.content[row][col] == 'E')
				tile = &data->exit;
			else if (data->map.content[row][col] == 'P')
				tile = &data->play;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				tile->img, col * ASSET_SIZE, row * ASSET_SIZE);
		}
	}
}

void	free_data(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->map.content != NULL)
	{
		while (i < data->map.height)
		{
			free(data->map.content[i]);
			i++;
		}
		free(data->map.content);
	}
}

int	exit_game(t_data *data, int exit_mode)
{
	free_data(data);
	mlx_destroy_image(data->mlx_ptr, data->empt.img);
	mlx_destroy_image(data->mlx_ptr, data->wall.img);
	mlx_destroy_image(data->mlx_ptr, data->play.img);
	mlx_destroy_image(data->mlx_ptr, data->coll.img);
	mlx_destroy_image(data->mlx_ptr, data->exit.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (exit_mode == 0)
		ft_printf("Congrats, you beat the game in %d steps\n",
			data->map.steps + 1);
	else
		ft_printf("Thanks for playing! Stay lit!\n");
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 53)
		exit_game(data, 1);
	if (keycode == 0)
		move_left(data);
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
	mlx_launch(data);
	load_assets(data);
	draw_map(data, 1, 1);
	mlx_hook(data->win_ptr, 17, (1L << 17), &exit_game, data);
	mlx_hook(data->win_ptr, 02, (1L << 2), &key_press, data);
	mlx_loop(data->mlx_ptr);
}
