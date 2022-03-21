/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:47:12 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/21 17:30:50 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_top_bot(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		error_message("Map error: empty", 2, NULL, NULL);
	while (line[i] != '\n')
	{
		if (line[i++] != '1')
			error_message("Map error: top/bottom wall error\n", 2, line, NULL);
	}
}

void	line_check(char *line, char *prev_line, t_map *map, int line_count)
{
	int	i;

	i = 0;
	if (line[i] != '1' || line[map->width - 1] != '1')
		error_message("Map error: incorrect walls", 2, line, prev_line);
	else if (ft_strlen(line) - 1 != map->width)
		error_message("Map error: not rectangular", 2, line, prev_line);
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
			error_message("Map error: unknown elements\n", 2, line, prev_line);
		i++;
	}
}

void	rect_check(int fd, t_map *map, int line_count)
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
			line_check(line, prev_line, map, ++line_count);
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
	if (map->height < 3 || map->width < 3)
		error_message("Map error: too small", 2, NULL, NULL);
}

void	map_check(char *path, t_data *data)
{
	int	line_count;

	line_count = 1;
	data->map.p_count = 0;
	data->map.c_count = 0;
	data->map.e_count = 0;
	data->map.height = 1;
	data->map.steps = 0;
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd < 0)
		error_message("Map error: error reading file", 2, NULL, NULL);
	rect_check(data->map.fd, &(data->map), line_count);
	if (data->map.p_count != 1
		|| data->map.e_count < 1 || data->map.c_count < 1)
		error_message("Map error: wrong resources", 2, NULL, NULL);
	close(data->map.fd);
}
