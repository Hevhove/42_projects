/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:11:27 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/18 12:12:21 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
	}
	return (c);
}

/*
int main(void)
{
	int a;
	int b;
	int c;
	int d;
	int e;

	a = 'A';
	b = 'B';
	c = 'c';
	d = '?';
	e = 127;

	printf("TESTING...\n");
	printf("OUR VERSION: ft_tolower(%c) is: %c\n", a, ft_tolower(a));
	printf("OFF VERSION: ft_tolower(%c) is: %c\n", a, tolower(a));
	printf("----\n");
	
	printf("OUR VERSION: ft_tolower(%c) is: %c\n", b, ft_tolower(b));
	printf("OFF VERSION: ft_tolower(%c) is: %c\n", b, tolower(b));
	printf("----\n");
	
	printf("OUR VERSION: ft_tolower(%c) is: %c\n", c, ft_tolower(c));
	printf("OFF VERSION: ft_tolower(%c) is: %c\n", c, tolower(c));
	printf("----\n");
	
	printf("OUR VERSION: ft_tolower(%c) is: %c\n", d, ft_tolower(d));
	printf("OFF VERSION: ft_tolower(%c) is: %c\n", d, tolower(d));
	printf("----\n");
	
	printf("OUR VERSION: ft_tolower(%c) is: %c\n", e, ft_tolower(e));
	printf("OFF VERSION: ft_tolower(%c) is: %c\n", e, tolower(e));
	printf("----\n");
}
*/
