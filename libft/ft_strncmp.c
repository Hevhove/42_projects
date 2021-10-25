/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:11:27 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/18 15:38:05 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	int	i;

	i = 0;
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && i < (int) n)
	{
		s1++;
		s2++;
		i++;
	}	
	return (*s1 - *s2);
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
