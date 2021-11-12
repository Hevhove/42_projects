/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:54:46 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/11 14:42:44 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strnjoin(const char *s1, char s2[][BUFFER_SIZE + 1], struct s_i it)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(*s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (s1[++(it.i)] != '\0')
		join[(it.i)] = s1[(it.i)];
	while ((*s2)[++(it.j)] != '\0')
	{
		if ((*s2)[(it.j)] == '\n')
		{
			join[(it.i)++] = '\n';
			join[(it.i)] = '\0';
			while ((*s2)[++(it.j)] != '\0')
				(*s2)[(it.k)++] = (*s2)[(it.j)];
			(*s2)[it.k] = '\0';
			break ;
		}
		join[(it.i)++] = (*s2)[(it.j)];
		(*s2)[(it.j)] = '\0';
	}
	join[(it.i)] = '\0';
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
