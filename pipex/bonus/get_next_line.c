/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:27:16 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/21 18:06:32 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"
#include <sys/types.h>
#include <fcntl.h>

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

/*
int	main(void)
{
	//int		fd;
	//char	*line1;
	//char	*line2;

	//char	str1[] = "hel\nlo"; // hell\0 --> o\nth\0 --> hello\n\0 || th\0
	//char	str2[] = "the\nre";
	//char	str3[] = "babies";

	// open a file and enter contents into it
	//fd = open("gnlTester/files/41_no_nl", O_RDWR | O_CREAT);
	//ft_putendl_fd(str1, fd);
	//ft_putendl_fd(str2, fd);
	//ft_putendl_fd(str3, fd);
	//printf("File descriptor is: %d\n", fd);

	// call get_next_line
	//line1 = get_next_line(fd);
	//free(line1);
	//line2 = get_next_line(fd);
	//free(line2);
	
	char	*line = NULL;
	while ((line = get_next_line(0)) != NULL)
		printf("%s", line);

	//while ((line1 = get_next_line(0)) != NULL)
	//	printf("%s", line1);
		
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
