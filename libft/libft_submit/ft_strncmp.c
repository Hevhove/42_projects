/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:11:27 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/01 15:39:13 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((p1[i] || p2[i]) && i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/*
int main(void)
{
	char str1[] = "Hello there!";
	char str2[] = "Hello Universe!";
	char str3[] = "Foo Bar";
	char str4[] = "Foo Bar Bas";

	printf("TESTING...\n");
	printf("OUR VERS: Comp of '%s'
   	and '%s' : %d\n", str1, str2, ft_strncmp(str1, str2, 4));
	printf("OFF VERS: Comp of '%s'
   	and '%s' : %d\n", str1, str2, strncmp(str1, str2, 4));
	printf("----\n");

	printf("OUR VERS: Comp of '%s'
   	and '%s' : %d\n", str1, str2, ft_strncmp(str1, str2, 7));
	printf("OFF VERS: Comp of '%s'
   	and '%s' : %d\n", str1, str2, strncmp(str1, str2, 7));
	printf("----\n");

	printf("OUR VERS: Comp of '%s'
   	and '%s' : %d\n", str3, str4, ft_strncmp(str3, str4, 4));
	printf("OFF VERS: Comp of '%s'
   	and '%s' : %d\n", str3, str4, strncmp(str3, str4, 4));
	printf("----\n");

	printf("OUR VERS: Comp of '%s'
   	and '%s' : %d\n", str3, str4, ft_strncmp(str3, str4, 12));
	printf("OFF VERS: Comp of '%s'
   	and '%s' : %d\n", str3, str4, strncmp(str3, str4, 12));
	printf("----\n");
}
*/