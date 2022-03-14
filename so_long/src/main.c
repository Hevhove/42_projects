/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:18:28 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/14 19:53:11 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

typedef struct s_params {
	t_data	*data;
	int		x;
	int		y;
	int		color;
} t_params;

void	check_top_bot(char *line)
{
	int i;
	
	i = 0;
	while (line[i] != '\n')
	{
		if (line[i++] != '1')
		{
			printf("invalid line\n");
			free(line);
			exit(3);
		}
	}
}

void	error_message(const char *message, int error_code)
{
	printf("%s\n", message);
	exit(error_code);
}

void	line_check(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (line[i] != '1' || line[map->width - 1] != '1')
		error_message("middle line wall error", 3);
	i++;
	while (line[i] != '\n')
	{
		if (line[i] == 'E')
			map->e_count++;
		else if (line[i] == 'C')
			map->c_count++;
		else if (line[i] == 'P')
			map->p_count++;
		else if (line[i] != '0' && line[i] != '1')
			error_message("middle line middle problem\n", 3);
		i++;
	}
}

void	rect_check(int fd, t_map *map)
{
	char	*line;
	char	*prev_line;

	line = get_next_line(fd);
	check_top_bot(line);
	map->width = ft_strlen(line) - 1;
	while (1)
	{
		prev_line = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			line_check(line, map);
		else
		{
			check_top_bot(prev_line);
			break ;
		}
		if (ft_strlen(line) -  1 != map->width)
			error_message("not a rectangle", 3);
		map->height++;
	}
	if (map->height < 4 || map->width < 4)
		error_message("Map too small", 3);
}

void	map_check(char *path, t_map *map)
{
	int		fd;
	
	// Initialize map variables
	map->p_count = 0;
	map->c_count = 0;
	map->e_count = 0;
	map->height = 1;
	// Open file
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_message("Error reading file", 3);
	// Check constraints
	rect_check(fd, map);
	if (map->p_count != 1 || map->e_count < 1 || map->c_count < 1)
		error_message("Wrong resources", 3);
}

int	main(int argc, char **argv)
{
	t_map	map;
	
	if (argc != 2)
	{
		write(1, "Error!\n", 7);
		return (1);
	}
	else
	{
		// Check the map file passed
		map_check(argv[1], &map);
	}
	
	// t_vars	vars;
	// t_data	img;
	// t_params params;

	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 1920, 1080, "so_long");
	// img.img = mlx_new_image(vars.mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// draw_square(&img, 100, 100, 100, 0x00FF0000);
	// draw_circle(&img, 500, 400, 0x00FF0000);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	// params.data = &img;
	// params.x = 250;
	// params.y = 250;
	// params.color = 0x0000FF00;
	// mlx_loop(vars.mlx);

	
	//mlx_loop(vars.mlx);
}
