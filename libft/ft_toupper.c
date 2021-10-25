/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:11:27 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/18 12:12:44 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
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

	a = 'a';
	b = 'b';
	c = 'C';
	d = '?';
	e = 127;

	printf("TESTING...\n");
	printf("OUR VERSION: ft_toupper(%c) is: %c\n", a, ft_toupper(a));
	printf("OFF VERSION: ft_toupper(%c) is: %c\n", a, toupper(a));
	printf("----\n");
	
	printf("OUR VERSION: ft_toupper(%c) is: %c\n", b, ft_toupper(b));
	printf("OFF VERSION: ft_toupper(%c) is: %c\n", b, toupper(b));
	printf("----\n");
	
	printf("OUR VERSION: ft_toupper(%c) is: %c\n", c, ft_toupper(c));
	printf("OFF VERSION: ft_toupper(%c) is: %c\n", c, toupper(c));
	printf("----\n");
	
	printf("OUR VERSION: ft_toupper(%c) is: %c\n", d, ft_toupper(d));
	printf("OFF VERSION: ft_toupper(%c) is: %c\n", d, toupper(d));
	printf("----\n");
	
	printf("OUR VERSION: ft_toupper(%c) is: %c\n", e, ft_toupper(e));
	printf("OFF VERSION: ft_toupper(%c) is: %c\n", e, toupper(e));
	printf("----\n");
}
*/
