/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:27:31 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/22 16:19:33 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *) b;
	while (len--)
	{
		s[i] = c;
		i++;
	}
	return (b);
}

void	*calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr != NULL)
		memset(ptr, 0, count * size);
	return (ptr);
}
