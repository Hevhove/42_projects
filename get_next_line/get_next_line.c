/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:52:31 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/09 17:19:17 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 42
#endif

static int	trim_buff(char *buff, char *strg) // make sure buff always ends in '\0'
{
	int	i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (buff[i] != '\0') // hell o\nth\0
	{
		if (buff[i] == '\n')
		{
			k = i + 1; // k = 2
			i++;
			while (buff[i] != '\0') // buff[2]
			{
				strg[j] = buff[i];
				j++;
				i++;
			}
			strg[j] = '\0'; // th\0
			buff[k] = '\0'; // o\n\0
			break ;
		}
		i++;
	}
	return (i);
}

void	reset_storage(char *input)
{
	while (*input)
	{
		*input = '\0';
		input++;
	}
}

char *get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1]; // fixed size char array of size BUFFER SIZE (+1?)
	char		*result;
	static int	offset;
	int			read_out;
	char		*temp;
	static char	strg[BUFFER_SIZE + 1]; // this means we don't need to malloc, can max be buffer size

	// CHECK THE INPUTS
	if ((read(fd, 0, 0) == -1) || fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	// STRJOIN THE INITIAL MALLOC WITH THE BUFFER
	// AFTER STRJOIN, FREE THE OLD RETURN - FOR THIS, WE NEED THE OLD RETURN IN A TEMP VAR
	result = (char *)malloc((BUFFER_SIZE  + 1) * sizeof(char));
	if (!result)
		return (NULL);
	*result = '\0';
	// NEED FUNCTION HERE THAT COPIES INTO RESULT FROM STORAGE ONLY UNTIL FIRST \N
	// and leaves strg intact after removing that \n
	// strg = cpy_strg(result, strg); // hello\nthere\n BUFFER SIZE = 7 --> hello\nt\0
	if (*strg != '\0')
	{
		temp = result;
		result = ft_strnjoin(result, &strg, '\n'); // strg = ft_memcpy(strg + i) 
		if (!ft_strchr(result, '\n') && *result != '\0')
			reset_storage(strg); // we need to reset the storage after copying it into result
		free(temp); // \n\n\n\n
	}
	while (1)
	{
		// READ THE CURRENT BUFFER SIZE INTO BUFF
		read_out = read(fd, buff, BUFFER_SIZE); // 
		//printf("read_out is: %d\n", read_out);
		// IF ERROR, RETURN NULL
		if (read_out == 0 && *strg != '\0') // we are at EOF, keep printing from storage tho
		{
			return (result);
		}
		else if (read_out == 0 && *result != '\0')
			return (result);
		else if (read_out == 0)
		{
			free(result);
			return (NULL);
		}
		//	return (result);
		// what to do if error? also end of file when read_out = 0
		// APPEND A NULL TO THE END OF THE BUFF, this makes it a string
		buff[read_out] = '\0'; // watch out for the case at end of string. Empty bits will read
		//printf("current buffer is: %s\n", buff);
		// INCREASE THE (STATIC) OFFSET
		offset += read_out; //
		// TRIM BUFFER AND COPY NEW BUFFER INTO RESULT
		trim_buff(buff, strg); // hello\n\0 || t\0
		temp = ft_strjoin(result, buff); // check malloc output? what if returns NULL
		free(result);
		result = temp;
		//printf("current result: %s\n", result);
		if (ft_strchr(result, '\n'))
			break;
	}
	return (result);
}

int	main(void)
{
	int		fd;
	//char	str1[] = "hello"; // hell\0 --> o\nth\0 --> hello\n\0 || th\0 
	//char	str2[] = "there";
	//char	str3[] = "babies";

	// open a file and enter contents into it
	fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDWR | O_CREAT);
	
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
	close(fd);
}
