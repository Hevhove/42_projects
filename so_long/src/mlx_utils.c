/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:23:31 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/17 16:17:07 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	win_size(t_data *data)
{
	data->win_width = data->map.width * ASSET_SIZE;
	data->win_height = data->map.height * ASSET_SIZE;
}

void	mlx_launch(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		error_message("MLX Error!\n", 4, NULL, NULL);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
	data->win_height, "so_long");
	if (data->win_ptr == NULL)
		error_message("MLX Error\n", 4, data->win_ptr, NULL);
}
