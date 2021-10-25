/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:44:52 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/18 10:49:01 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
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
	c = '2';
	d = '0';
	e = 99;
	f = '"';
	g = '~';

	printf("TESTING...\n");
	printf("OUR VERSION: char '%c' is alnum: %d\n", a, ft_isalnum(a));
	printf("OFF VERSION: char '%c' is alnum: %d\n", a, isalnum(a));
	printf("---\n");

	printf("OUR VERSION: char '%c' is alnum: %d\n", b, ft_isalnum(b));
	printf("OFF VERSION: char '%c' is alnum: %d\n", b, isalnum(b));
	printf("---\n");

	printf("OUR VERSION: char '%c' is alnum: %d\n", c, ft_isalnum(c));
	printf("OFF VERSION: char '%c' is alnum: %d\n", c, isalnum(c));
	printf("---\n");

	printf("OUR VERSION: char '%c' is alnum: %d\n", d, ft_isalnum(d));
	printf("OFF VERSION: char '%c' is alnum: %d\n", d, isalnum(d));
	printf("---\n");

	printf("OUR VERSION: char '%c' is alnum: %d\n", e, ft_isalnum(e));
	printf("OFF VERSION: char '%c' is alnum: %d\n", e, isalnum(e));
	printf("---\n");

	printf("OUR VERSION: char '%c' is alnum: %d\n", f, ft_isalnum(f));
	printf("OFF VERSION: char '%c' is alnum: %d\n", f, isalnum(f));
	printf("---\n");

	printf("OUR VERSION: char '%c' is alnum: %d\n", g, ft_isalnum(g));
	printf("OFF VERSION: char '%c' is alnum: %d\n", g, isalnum(g));
	printf("---\n");
}
*/
