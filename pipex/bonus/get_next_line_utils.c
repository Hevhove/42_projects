/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:54:46 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/21 18:05:55 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

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

char	*ft_strnjoin(const char *s1, char *s2, struct s_i it)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (s1[++(it.i)] != '\0')
		join[(it.i)] = s1[(it.i)];
	while ((s2)[++(it.j)] != '\0')
	{
		if ((s2)[(it.j)] == '\n')
		{
			join[(it.i)++] = '\n';
			join[(it.i)] = '\0';
			while ((s2)[++(it.j)] != '\0')
				(s2)[(it.k)++] = (s2)[(it.j)];
			(s2)[it.k] = '\0';
			break ;
		}
		join[(it.i)++] = (s2)[(it.j)];
		(s2)[(it.j)] = '\0';
	}
	join[(it.i)] = '\0';
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	long long	i;
	char		c2;

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

void	*ft_memcpy(void *dst, const void *src, long long n)
{
	long long	i;
	char		*dstptr;
	char		*srcptr;

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

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + 1;
	ptr = malloc(len * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
