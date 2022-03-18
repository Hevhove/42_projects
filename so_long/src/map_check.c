/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:47:12 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/18 17:31:36 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_top_bot(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		error_message("Empty map", 2, NULL, NULL);
	while (line[i] != '\n')
	{
		if (line[i++] != '1')
			error_message("invalid line\n", 2, line, NULL);
	}
}

void	line_check(char *line, char *prev_line, t_map *map, int line_count)
{
	int	i;

	i = 0;
	if (line[i] != '1' || line[map->width - 1] != '1')
		error_message("middle line wall error", 2, line, prev_line);
	else if (ft_strlen(line) - 1 != map->width)
		error_message("not a rectangle", 2, line, prev_line);
	i++;
	while (line[i] != '\n')
	{
		if (line[i] == 'E')
			map->e_count++;
		else if (line[i] == 'C')
			map->c_count++;
		else if (line[i] == 'P')
		{
			map->p_count++;
			map->p_x = i;
			map->p_y = line_count - 1;
		}
		else if (line[i] != '0' && line[i] != '1')
			error_message("middle line middle problem\n", 2, line, prev_line);
		i++;
	}
}

void	rect_check(int fd, t_map *map)
{
	char	*line;
	char	*prev_line;
	int		line_count;

	line_count = 1;
	line = get_next_line(fd);
	check_top_bot(line);
	map->width = ft_strlen(line) - 1;
	while (1)
	{
		prev_line = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
		{
			line_count++;
			line_check(line, prev_line, map, line_count);
		}
		else
		{
			check_top_bot(prev_line);
			free(prev_line);
			break ;
		}
		free(prev_line);
		map->height++;
	}
	free(line);
	if (map->height < 4 || map->width < 4)
		error_message("Map too small", 2, NULL, NULL);
}

void	map_check(char *path, t_data *data)
{
	int		fd;

	data->map.p_count = 0;
	data->map.c_count = 0;
	data->map.e_count = 0;
	data->map.height = 1;
	data->map.steps = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_message("Error reading file", 2, NULL, NULL);
	data->map.fd = fd;
	rect_check(data->map.fd, &(data->map));
	if (data->map.p_count != 1
		|| data->map.e_count < 1 || data->map.c_count < 1)
		error_message("Wrong resources", 2, NULL, NULL);
	ft_printf("Valid map!\n");
	printf("player pos is x: %d, y: %d\n", data->map.p_x, data->map.p_y);
	close(data->map.fd);
}
