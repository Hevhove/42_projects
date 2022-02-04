/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:47:01 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/30 19:08:27 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	if (s1 == s2 || n == 0)
		return (0);
	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		if (n != 0)
		{
			p1++;
			p2++;
		}
	}
	return (0);
}

/*
int	main(void)
{
	char str1[] = {-128, 0, 127, 0};
	char str2[] = {0, 0, 127, 0};

	printf("OUR VERS: %d\n", ft_memcmp(str1, str2, 4));
	printf("OFF VERS: %d\n", memcmp(str1, str2, 4));
}
*/
