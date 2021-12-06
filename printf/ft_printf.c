/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:24:29 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/12/06 15:59:16 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printfcases(char c, va_list args)
{	
	int	ret;

	ret = 0;
	if (c == 'c')
		ret = ft_putchar(va_arg(args, int));
	else if (c == 's')
		ret = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		ret = ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ret = ft_putnbr(va_arg(args, int), ret);
	else if (c == 'u')
		ret = ft_putunbr(va_arg(args, unsigned int), ret);
	else if (c == 'x')
		ret = ft_puthex(va_arg(args, unsigned int), 0, ret);
	else if (c == 'X')
		ret = ft_puthex(va_arg(args, unsigned int), 1, ret);
	else if (c == '%')
		ret = ft_putchar('%');
	else
		ret = 0;
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (s == NULL)
		return (0);
	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			len += ft_putchar(s[i++]);
		}
		else
		{
			len += printfcases(s[++i], args);
			i++;
		}
	}
	va_end(args);
	return (len);
}

/*
int	main(void)
{
	char a = 'a';
	char b = 'b';
	int i = 1234;
	int j = 9876;
	int k = 255;
	char str1[] = "hello";
	char str2[] = "there";

	// OUR TESTS
	ft_printf("Print a char: %c\n", a);
	ft_printf("Print many chars: %c, %c\n", a, b);
	ft_printf("Print a str: %s\n", str1);
	ft_printf("Print many str: %s, %s\n", str1, str2);
	ft_printf("Print a number (d): %d\n", i);
	ft_printf("Print a number (i) : %i\n", i);
	ft_printf("Print many numbers: %d, %i\n", i, j);
	ft_printf("Print a pointer: %p\n", str1);
	ft_printf("Print many pointers: %p, %p\n", str1, str2);
	ft_printf("Print a hex lower: %x\n", k);
	ft_printf("Print a hex upper: %X\n", k);
	ft_printf("Print an unsigned number: %u\n", i);
	ft_printf("Print many unsigned numbers: %u, %u\n\n", i, j);

	// OFFICIAL TESTS
	printf("Print a char: %c\n", a);
	printf("Print many chars: %c, %c\n", a, b);
	printf("Print a str: %s\n", str1);
	printf("Print many str: %s, %s\n", str1, str2);
	printf("Print a number (d): %d\n", i);
	printf("Print a number (i) : %i\n", i);
	printf("Print many numbers: %d, %i\n", i, j);
	printf("Print a pointer: %p\n", str1);
	printf("Print many pointers: %p, %p\n", str1, str2);
	printf("Print a hex lower: %x\n", k);
	printf("Print a hex upper: %X\n", k);
	printf("Print an unsigned number: %u\n", i);
	printf("Print many unsigned numbers: %u, %u\n", i, j);
}
*/
