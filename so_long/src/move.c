/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:50:50 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/19 20:07:13 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	valid_move(t_data *data, char next_tile)
{
	// spot to the left is not a wall
	if (next_tile == '1')
		return (0);
	// move to exit but not all collectibles collected
	if (next_tile == 'E' && data->map.c_coll != data->map.c_count)
		return (0);
	return (1);
}

void	move_left(t_data *data)
{
	// check if the move is valid
	if (valid_move(data, data->map.content[data->map.p_y][data->map.p_x - 1]))
	{
		if (data->map.content[data->map.p_y][data->map.p_x - 1] == 'C')
			data->map.c_coll++;
		else if (data->map.content[data->map.p_y][data->map.p_x - 1] == 'E')
			data->map.player_exit = 1;
		// set the previous tile
		data->map.content[data->map.p_y][data->map.p_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empt.img, 
		data->map.p_x * ASSET_SIZE, data->map.p_y * ASSET_SIZE);
		// set the next tile
		data->map.content[data->map.p_y][data->map.p_x - 1] = 'P';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empt.img, 
			(data->map.p_x - 1) * ASSET_SIZE, data->map.p_y * ASSET_SIZE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->play.img, 
		(data->map.p_x - 1) * ASSET_SIZE, data->map.p_y * ASSET_SIZE);
		data->map.p_x--;
		data->map.steps++;		
		// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->play.img, 
		// (data->map.p_x - 1) * ASSET_SIZE, data->map.p_y * ASSET_SIZE);
		// 	time = 0;
		// 	while (time++ < 100000000000)
		// 		;
		// 	exit_game(data);
	}
}

void	move_down(t_data *data)
{
	// check if the move is valid
	if (valid_move(data, data->map.content[data->map.p_y + 1][data->map.p_x]))
	{
		if (data->map.content[data->map.p_y + 1][data->map.p_x] == 'C')
			data->map.c_coll++;
		else if (data->map.content[data->map.p_y + 1][data->map.p_x] == 'E')
		{
			data->map.content[data->map.p_y + 1][data->map.p_x] = 'P';
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->play.img, 
			(data->map.p_x) * ASSET_SIZE, (data->map.p_y + 1) * ASSET_SIZE);
			sleep(1);
			exit_game(data);
		}
		// set the previous tile
		data->map.content[data->map.p_y][data->map.p_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empt.img, 
		data->map.p_x * ASSET_SIZE, data->map.p_y * ASSET_SIZE);
		// set the next tile
		data->map.content[data->map.p_y + 1][data->map.p_x] = 'P';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->play.img, 
		(data->map.p_x) * ASSET_SIZE, (data->map.p_y + 1) * ASSET_SIZE);
		data->map.p_y++;
		data->map.steps++;
	}
}

void	move_right(t_data *data)
{
	// check if the move is valid
	if (valid_move(data, data->map.content[data->map.p_y][data->map.p_x + 1]))
	{
		if (data->map.content[data->map.p_y][data->map.p_x + 1] == 'C')
			data->map.c_coll++;
		else if (data->map.content[data->map.p_y][data->map.p_x + 1] == 'E')
		{
			data->map.content[data->map.p_y][data->map.p_x + 1] = 'P';
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->play.img, 
			(data->map.p_x + 1) * ASSET_SIZE, (data->map.p_y) * ASSET_SIZE);
			sleep(1);
			exit_game(data);
		}
		// set the previous tile
		data->map.content[data->map.p_y][data->map.p_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empt.img, 
		data->map.p_x * ASSET_SIZE, data->map.p_y * ASSET_SIZE);
		// set the next tile
		data->map.content[data->map.p_y][data->map.p_x + 1] = 'P';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->play.img, 
		(data->map.p_x + 1) * ASSET_SIZE, data->map.p_y * ASSET_SIZE);
		data->map.p_x++;
		data->map.steps++;
	}
}

void	move_up(t_data *data)
{
	// check if the move is valid
	if (valid_move(data, data->map.content[data->map.p_y - 1][data->map.p_x]))
	{
		if (data->map.content[data->map.p_y - 1][data->map.p_x] == 'C')
			data->map.c_coll++;
		else if (data->map.content[data->map.p_y - 1][data->map.p_x] == 'E')
		{
			data->map.content[data->map.p_y - 1][data->map.p_x] = 'P';
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->play.img, 
			(data->map.p_x) * ASSET_SIZE, (data->map.p_y - 1) * ASSET_SIZE);
			sleep(1);
			exit_game(data);
		}
		// set the previous tile
		data->map.content[data->map.p_y][data->map.p_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empt.img, 
		data->map.p_x * ASSET_SIZE, data->map.p_y * ASSET_SIZE);
		// set the next tile
		data->map.content[data->map.p_y - 1][data->map.p_x] = 'P';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->play.img, 
		(data->map.p_x) * ASSET_SIZE, (data->map.p_y - 1) * ASSET_SIZE);
		data->map.p_y--;
		data->map.steps++;
	}
}
