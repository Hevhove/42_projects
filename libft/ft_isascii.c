/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:44:52 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/18 10:59:09 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

/*
int main(void)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;
	int	f;
	int	g;

	a = 'a';
	b = 'B';
	c = 27;
	d = 98;
	e = ']';
	f = -1;
	g = 256;

	printf("TESTING...\n");
	printf("OUR VERSION: char '%c' is ascii: %d\n", a, ft_isascii(a));
	printf("OFF VERSION: char '%c' is ascii: %d\n", a, isascii(a));
	printf("---\n");

	printf("OUR VERSION: char '%c' is ascii: %d\n", b, ft_isascii(b));
	printf("OFF VERSION: char '%c' is ascii: %d\n", b, isascii(b));
	printf("---\n");

	printf("OUR VERSION: char '%c' is ascii: %d\n", c, ft_isascii(c));
	printf("OFF VERSION: char '%c' is ascii: %d\n", c, isascii(c));
	printf("---\n");

	printf("OUR VERSION: char '%c' is ascii: %d\n", d, ft_isascii(d));
	printf("OFF VERSION: char '%c' is ascii: %d\n", d, isascii(d));
	printf("---\n");

	printf("OUR VERSION: char '%c' is ascii: %d\n", e, ft_isascii(e));
	printf("OFF VERSION: char '%c' is ascii: %d\n", e, isascii(e));
	printf("---\n");

	printf("OUR VERSION: char '%c' is ascii: %d\n", f, ft_isascii(f));
	printf("OFF VERSION: char '%c' is ascii: %d\n", f, isascii(f));
	printf("---\n");

	printf("OUR VERSION: char '%c' is ascii: %d\n", g, ft_isascii(g));
	printf("OFF VERSION: char '%c' is ascii: %d\n", g, isascii(g));
	printf("---\n");
}
*/
