/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:44:52 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/18 11:09:32 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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

	a = 'a';
	b = 'B';
	c = 24;
	d = 98;
	e = ']';
	f = '"';
	g = 127;

	printf("TESTING...\n");
	printf("OUR VERSION: char '%c' is print: %d\n", a, ft_isprint(a));
	printf("OFF VERSION: char '%c' is print: %d\n", a, isprint(a));
	printf("---\n");

	printf("OUR VERSION: char '%c' is print: %d\n", b, ft_isprint(b));
	printf("OFF VERSION: char '%c' is print: %d\n", b, isprint(b));
	printf("---\n");

	printf("OUR VERSION: char '%c' is print: %d\n", c, ft_isprint(c));
	printf("OFF VERSION: char '%c' is print: %d\n", c, isprint(c));
	printf("---\n");

	printf("OUR VERSION: char '%c' is print: %d\n", d, ft_isprint(d));
	printf("OFF VERSION: char '%c' is print: %d\n", d, isprint(d));
	printf("---\n");

	printf("OUR VERSION: char '%c' is print: %d\n", e, ft_isprint(e));
	printf("OFF VERSION: char '%c' is print: %d\n", e, isprint(e));
	printf("---\n");

	printf("OUR VERSION: char '%c' is print: %d\n", f, ft_isprint(f));
	printf("OFF VERSION: char '%c' is print: %d\n", f, isprint(f));
	printf("---\n");

	printf("OUR VERSION: char '%c' is print: %d\n", g, ft_isprint(g));
	printf("OFF VERSION: char '%c' is print: %d\n", g, isprint(g));
	printf("---\n");
}
*/
