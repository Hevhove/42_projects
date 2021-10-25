/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:42:41 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/19 15:13:57 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *) s;
	while (n--)
	{
		p[i] = '\0';
		i++;
	}
}

/*
int main(void)
{
	char str1[] = "Hello there!";
	char str2[] = "Hello there!";
	// size_t n1 = 3;
	size_t n2 = 15;

	printf("Our Test: '%s'\n", str1);
	ft_bzero(str1, n2);
	
	for (int i = 0; i < 50; i++)
		printf("Test: '%c'\n", str1[i]);
	printf("---\n");

	printf("Official Test: '%s'\n", str2);
	bzero(str2, n2);
	printf("Test: '%c'\n", str2[0]);
	printf("Test: '%c'\n", str2[1]);
	printf("Test: '%c'\n", str2[2]);
	printf("Test: '%c'\n", str2[3]);
	printf("Test: '%c'\n", str2[4]);
}
*/
