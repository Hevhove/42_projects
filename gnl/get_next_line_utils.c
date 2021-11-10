/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:54:46 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/10 18:30:15 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

char	*ft_strnjoin(const char *s1, char s2[][BUFFER_SIZE + 1], char c)
{
	int		i;
	int 	j;
	int		k;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(*s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while ((*s2)[j] != '\0')
	{
		if ((*s2)[j] == c)
		{
			join[i] = c;
			i++;
			join[i] = '\0'; // aaxxx
			j++;
			k = 0;
			while ((*s2)[j] != '\0')
			{
				(*s2)[k] = (*s2)[j];
				k++;
				j++;
			}
			(*s2)[k] = '\0';
			break ;
		}
		// if we dont encounter the char yet, we keep iterating and adding in the join
		join[i] = (*s2)[j];
		(*s2)[j] = '\0';
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c2;

	c2 = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c2)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c2)
		return ((char *)(s + i));
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*dstptr;
	char	*srcptr;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dstptr = (char *)dst;
	srcptr = (char *)src;
	while (n--)
	{
		dstptr[i] = srcptr[i];
		i++;
	}
	return (dst);
}

