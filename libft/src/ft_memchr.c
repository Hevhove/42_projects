/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:24:40 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/30 18:40:04 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char str1[] = "Hello!";
	char c = 'l';
	size_t n = 4;

	printf("Location of '%c'
   	in string '%s' is at: %p\n", c, str1, ft_memchr(str1, c, n));
}
*/
