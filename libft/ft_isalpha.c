/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:44:52 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/18 10:25:36 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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
	c = 27;
	d = 98;
	e = ']';
	f = '"';
	g = '~';

	printf("TESTING...\n");
	printf("OUR VERSION: char '%c' is alpha: %d\n", a, ft_isalpha(a));
	printf("OFF VERSION: char '%c' is alpha: %d\n", a, isalpha(a));
	printf("---\n");

	printf("OUR VERSION: char '%c' is alpha: %d\n", b, ft_isalpha(b));
	printf("OFF VERSION: char '%c' is alpha: %d\n", b, isalpha(b));
	printf("---\n");

	printf("OUR VERSION: char '%c' is alpha: %d\n", c, ft_isalpha(c));
	printf("OFF VERSION: char '%c' is alpha: %d\n", c, isalpha(c));
	printf("---\n");

	printf("OUR VERSION: char '%c' is alpha: %d\n", d, ft_isalpha(d));
	printf("OFF VERSION: char '%c' is alpha: %d\n", d, isalpha(d));
	printf("---\n");

	printf("OUR VERSION: char '%c' is alpha: %d\n", e, ft_isalpha(e));
	printf("OFF VERSION: char '%c' is alpha: %d\n", e, isalpha(e));
	printf("---\n");

	printf("OUR VERSION: char '%c' is alpha: %d\n", f, ft_isalpha(f));
	printf("OFF VERSION: char '%c' is alpha: %d\n", f, isalpha(f));
	printf("---\n");

	printf("OUR VERSION: char '%c' is alpha: %d\n", g, ft_isalpha(g));
	printf("OFF VERSION: char '%c' is alpha: %d\n", g, isalpha(g));
	printf("---\n");
}
*/
