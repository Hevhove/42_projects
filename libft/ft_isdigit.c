/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:44:52 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/18 10:43:13 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

/*
int main(void)
{
	char a;
	char b;
	char c;
	char d;
	char e;
	char f;
	char g;

	a = '7';
	b = '2';
	c = 21;
	d = 97;
	e = ']';
	f = '"';
	g = '~';

	printf("TESTING...\n");
	printf("OUR VERSION: char '%c' is digit: %d\n", a, ft_isdigit(a));
	printf("OFF VERSION: char '%c' is digit: %d\n", a, isdigit(a));
	printf("---\n");

	printf("OUR VERSION: char '%c' is digit: %d\n", b, ft_isdigit(b));
	printf("OFF VERSION: char '%c' is digit: %d\n", b, isdigit(b));
	printf("---\n");

	printf("OUR VERSION: char '%c' is digit: %d\n", c, ft_isdigit(c));
	printf("OFF VERSION: char '%c' is digit: %d\n", c, isdigit(c));
	printf("---\n");

	printf("OUR VERSION: char '%c' is digit: %d\n", d, ft_isdigit(d));
	printf("OFF VERSION: char '%c' is digit: %d\n", d, isdigit(d));
	printf("---\n");

	printf("OUR VERSION: char '%c' is digit: %d\n", e, ft_isdigit(e));
	printf("OFF VERSION: char '%c' is digit: %d\n", e, isdigit(e));
	printf("---\n");

	printf("OUR VERSION: char '%c' is digit: %d\n", f, ft_isdigit(f));
	printf("OFF VERSION: char '%c' is digit: %d\n", f, isdigit(f));
	printf("---\n");

	printf("OUR VERSION: char '%c' is digit: %d\n", g, ft_isdigit(g));
	printf("OFF VERSION: char '%c' is digit: %d\n", g, isdigit(g));
	printf("---\n");
}
*/
