/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:27:16 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/14 16:48:36 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	add_store(char **result, char *buffer)
{
	char		*temp;
	struct s_i	iter;

	iter.i = -1;
	iter.j = -1;
	iter.k = 0;
	**result = '\0';
	if (*buffer != '\0')
	{
		temp = *result;
		*result = ft_strnjoin(*result, buffer, iter);
		free(temp);
	}
}

static int	rd_nx(char **result, char *buf, int fd)
{
	int			ret;
	char		*temp;
	struct s_i	iter;

	iter.i = -1;
	iter.j = -1;
	iter.k = 0;
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == 0 && **result != '\0')
		return (0);
	else if ((ret == 0 && **result == '\0') || ret == -1)
		return (-1);
	buf[ret] = '\0';
	temp = *result;
	*result = ft_strnjoin(*result, buf, iter);
	free(temp);
	return (1);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*result;
	int				check;

	if (read(fd, 0, 0) == -1 || fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	result = (char *)malloc(sizeof(*result));
	if (!result)
		return (NULL);
	add_store(&result, buffer);
	while (!ft_strchr(result, '\n'))
	{
		check = rd_nx(&result, buffer, fd);
		if (check == 0)
			return (result);
		if (check == -1)
		{
			free(result);
			return (NULL);
		}
	}
	return (result);
}
