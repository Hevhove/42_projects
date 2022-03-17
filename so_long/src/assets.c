/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:08:39 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/17 17:27:41 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// void	xpm_to_image_wrapper(t_data *data, t_img *image, char *file)
// {
// 	image->img = mlx_xpm_file_to_image(data->mlx_ptr,
// 			file, &image->width, &image->height)
// }

void	load_assets(t_data *data)
{
	printf("width is: %d\n", data->empt.width);
	data->empt.img = mlx_xpm_file_to_image(data->mlx_ptr,
		 "./assets/xpm/empt.xpm", &data->empt.width, &data->empt.height);
	printf("width is: %d\n", data->empt.width);
	data->wall.img = mlx_xpm_file_to_image(data->mlx_ptr,
		 "./assets/xpm/wall.xpm", &data->wall.width, &data->wall.height);
	data->coll.img = mlx_xpm_file_to_image(data->mlx_ptr,
		 "./assets/xpm/coll.xpm", &data->coll.width, &data->coll.height);
	data->exit.img = mlx_xpm_file_to_image(data->mlx_ptr,
		 "./assets/xpm/exit.xpm", &data->exit.width, &data->exit.height);
	data->play.img = mlx_xpm_file_to_image(data->mlx_ptr,
		 "./assets/xpm/play.xpm", &data->play.width, &data->play.height);
	if (!data->empt.img || !data->wall.img || !data->coll.img
		|| !data->exit.img || !data->play.img)
		error_message("Error loading assets", 5, NULL, NULL);
}
