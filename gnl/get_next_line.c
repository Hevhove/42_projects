/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:27:16 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/10 18:34:08 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <fcntl.h>

static void	add_store(char **result, char store[][BUFFER_SIZE + 1])
{
	char	*temp;

	**result = '\0';
	if (**store != '\0')
	{
		temp = *result;
		*result = ft_strnjoin(*result, store, '\n');
		free(temp);
	}
}

static int	rd_nx(char **result, char buf[][BUFFER_SIZE + 1],
		char store[][BUFFER_SIZE + 1], int fd)
{
	int		ret;
	char	*temp;

	ret = read(fd, *buf, BUFFER_SIZE);
	if (ret == 0 && **result != '\0') // EOF - return what is currently in result
		return (0);
	else if (ret == 0 && **result == '\0') // nothing left to return or empty file
		return (-1);
	(*buf)[ret] = '\0';
	temp = *result;
	*result = ft_strnjoin(*result, buf, '\n'); // joins buffer to result until \n
	free(temp);
	ft_memcpy(*store, *buf, ft_strlen(*buf)); // memcpy the what is left in buffer to store for the read amount
	return (1);
}

char *get_next_line(int fd)
{
	static char	store[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*result;
	int			check;

	if (read(fd, 0, 0) == -1 || fd < 0 || fd > 1024)
		return (NULL);
	result = (char*)malloc((BUFFER_SIZE + 1) * sizeof(result));
	if (!result)
		return (NULL);
	*result = '\0';
	add_store(&result, &store); // 01234\n0123
	if (!ft_strchr(result, '\n'))
	{
		while (1)
		{
			check = rd_nx(&result, &buffer, &store, fd); // needs address of result to edit
			if (check == 0)
				return (result);
			if (check == -1)
			{
				free(result);
				return (NULL);
			}
			if (ft_strchr(result, '\n'))
				return (result);
		}
	}
	return (result);
}
/*
int	main(void)
{
	int		fd;
	char	str1[] = "hel\nlo"; // hell\0 --> o\nth\0 --> hello\n\0 || th\0
	char	str2[] = "the\nre";
	char	str3[] = "babies";

	// open a file and enter contents into it
	fd = open("gnlTester/files/nl", O_RDWR | O_CREAT);

	//ft_putendl_fd(str1, fd);
	//ft_putendl_fd(str2, fd);
	//ft_putendl_fd(str3, fd);
	//printf("File descriptor is: %d\n", fd);

	// call get_next_line
	printf("result is: %s\n", get_next_line(fd));
	printf("result is: %s\n", get_next_line(fd));
	printf("result is: %s\n", get_next_line(fd));
	printf("result is: %s\n", get_next_line(fd));
	printf("result is: %s\n", get_next_line(fd));
	printf("result is: %s\n", get_next_line(fd));	
	printf("result is: %s\n", get_next_line(fd));
	printf("result is: %s\n", get_next_line(fd));
	printf("result is: %s\n", get_next_line(fd));	
	printf("result is: %s\n", get_next_line(fd));
	printf("result is: %s\n", get_next_line(fd));
	printf("result is: %s\n", get_next_line(fd));
	close(fd);
}
*/
