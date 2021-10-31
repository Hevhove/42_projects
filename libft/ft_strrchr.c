/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:11:27 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/30 20:16:13 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	if (!s)
		return (NULL);
	if (c > 255)
		return ((char *)s);
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (s[len] == c)
			return ((char *)&s[len]);
	}
	return (NULL);
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
