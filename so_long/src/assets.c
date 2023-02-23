/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:08:39 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/21 16:08:52 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_assets(t_data *data)
{
	data->empt.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/xpm/empt_64.xpm", &data->empt.width, &data->empt.height);
	data->wall.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/xpm/wall_64.xpm", &data->wall.width, &data->wall.height);
	data->coll.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/xpm/coll_64.xpm", &data->coll.width, &data->coll.height);
	data->exit.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/xpm/exit_64.xpm", &data->exit.width, &data->exit.height);
	data->play.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/xpm/play_64.xpm", &data->play.width, &data->play.height);
	if (!data->empt.img || !data->wall.img || !data->coll.img
		|| !data->exit.img || !data->play.img)
		error_message("Error loading assets", 5, NULL, NULL);
}
