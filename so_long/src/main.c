/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:18:28 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/22 09:43:52 by hvan-hov         ###   ########.fr       */
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
	data->map.content = ft_calloc(data->map.height, sizeof(char *));
	if (!data->map.content)
		error_message("Error: malloc error\n", 3, NULL, NULL);
	data->map.fd = open(data->map_path, O_RDONLY);
	if (data->map.fd < 0)
		error_message("Error: Problem with fd", 2, data->map.content, NULL);
	i = 0;
	line = get_next_line(data->map.fd);
	while (line)
	{
		data->map.content[i++] = line;
		line = get_next_line(data->map.fd);
	}
	close(data->map.fd);
}

int	extension_check(char *input)
{
	while (*input)
		input++;
	input -= 4;
	if (ft_strncmp(input, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_message("Error: wrong number of arguments", 1, NULL, NULL);
	if (!extension_check(argv[1]))
		error_message("Map error: extension is not .ber", 1, NULL, NULL);
	data.map_path = argv[1];
	map_check(argv[1], &data);
	map_alloc(&data);
	launch(&data);
	return (0);
}
