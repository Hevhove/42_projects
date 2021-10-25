/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:47:01 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/19 17:32:41 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*p1;
	char	*p2;

	p1 = (char *)s1;
	p2 = (char *)s2;
	while (n-- && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}

/*
int	main(void)
{
	char str1[] = "test1";
	char str2[] = "test5";

	printf("The memcmp is: %d\n", memcmp(str1, str2, 5));
}
*/
