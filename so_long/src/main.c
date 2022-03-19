/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:18:28 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/19 18:34:48 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
// ERROR_CODES
// 01: Input error
// 02: Map error
// 03: Malloc error
// 04: MLX Error
// 05: Assets error
*/

#include "../inc/so_long.h"

void	error_message(const char *msg, int error_code, void *ptr1, void *ptr2)
{
	ft_printf("%s\n", msg);
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	exit(error_code);
}

void	map_alloc(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	data->map.content = ft_calloc(data->map.height, data->map.width);
	if (!data->map.content)
		error_message("malloc error\n", 3, NULL, NULL);
	data->map.fd = open(data->map_path, O_RDONLY);
	if (data->map.fd < 0)
		error_message("Problem with file descriptor", 2, data->map.content, NULL);
	i = 0;
	line = get_next_line(data->map.fd);
	while (line)
	{
		data->map.content[i++] = line;
		line = get_next_line(data->map.fd);
	}
	close(data->map.fd);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_message("Error\n", 1, NULL, NULL);
	// check for valid extensions .ber
	data.map_path = argv[1];
	map_check(argv[1], &data);
	map_alloc(&data);
	launch(&data);
	// don't forget to close all fds
	return (0);
}
