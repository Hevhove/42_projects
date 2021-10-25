/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:11:27 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/18 15:29:34 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char	*ft_strrchr(char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s != '\0')
	{
		if (c == *s)
		{
			ptr = s;
		}
		s++;
	}
	return (ptr);
}

/*
int main(void)
{
	char s1[] = "Hello there!";
	char s2[] = "Another test";
	char a = 'e';
	char b = 'f';
	char c = 'Q';
	char d = '!';

	printf("TESTING...\n");
	printf("OUR VERS: addr of '%c' in '%s' at: %p\n", a, s1, ft_strrchr(s1, a));
	printf("OFF VERS: addr of '%c' in '%s' at: %p\n", a, s1, strrchr(s1, a));
	printf("----\n");

	printf("OUR VERS: addr of '%c' in '%s' at: %p\n", a, s2, ft_strrchr(s2, a));
	printf("OFF VERS: addr of '%c' in '%s' at: %p\n", a, s2, strrchr(s2, a));
	printf("----\n");

	printf("OUR VERS: addr of '%c' in '%s' at: %p\n", b, s1, ft_strrchr(s1, a));
	printf("OFF VERS: addr of '%c' in '%s' at: %p\n", b, s1, strrchr(s1, a));
	printf("----\n");

	printf("OUR VERS: addr of '%c' in '%s' at: %p\n", c, s1, ft_strrchr(s1, a));
	printf("OFF VERS: addr of '%c' in '%s' at: %p\n", c, s1, strrchr(s1, a));
	printf("----\n");

	printf("OUR VERS: addr of '%c' in '%s' at: %p\n", d, s1, ft_strrchr(s1, a));
	printf("OFF VERS: addr of '%c' in '%s' at: %p\n", d, s1, strrchr(s1, a));
	printf("----\n");

	printf("OUR VERS: addr of '%c' in '%s' at: %p\n", d, s2, ft_strrchr(s2, a));
	printf("OFF VERS: addr of '%c' in '%s' at: %p\n", d, s2, strrchr(s2, a));
	printf("----\n");
}
*/
