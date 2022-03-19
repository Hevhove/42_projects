/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:17:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/19 20:18:08 by hvan-hov         ###   ########.fr       */
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
		
			if (data->map.content[row][col] != '1')
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

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.content != NULL)
	{
		while (data->map.content[i])
		{
			free(data->map.content[i]);
			i++;
		}
		free(data->map.content);
		// set to NULL?
	}
}

int	exit_game(t_data *data)
{
	free_data(data);
	mlx_destroy_image(data->mlx_ptr, data->empt.img);
	mlx_destroy_image(data->mlx_ptr, data->wall.img);
	mlx_destroy_image(data->mlx_ptr, data->play.img);
	mlx_destroy_image(data->mlx_ptr, data->coll.img);
	mlx_destroy_image(data->mlx_ptr, data->exit.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_printf("Congrats, you beat the game in %d\n steps", data->map.steps);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	ft_printf("Current steps: %d\n", data->map.steps);
	if (keycode == 53)
		exit_game(data);
	if (keycode == 0)
		move_left(data);
	else if (keycode == 1)
		move_down(data);
	else if (keycode == 2)
	 	move_right(data);
	else if (keycode == 13)
		move_up(data);
	if (data->map.player_exit == 1)
		return (0);
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
	data->map.player_exit = 0;
	mlx_hook(data->win_ptr, 17, (1L << 17), &exit_game, data);
	mlx_hook(data->win_ptr, 02, (1L << 2), &key_press, data);
	printf("checker\n");
	mlx_loop(data->mlx_ptr);
}
