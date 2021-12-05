/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:24:29 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/12/05 21:14:23 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printfcases(char c, va_list args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 's')
		ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		ft_puthex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		ft_putchar('%');
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
			ft_putchar(s[i++]);
		}
		else
		{
			printfcases(s[++i], args);
			i++;
		}
		len++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	char str[] = "";

	//ft_printf(" %s ", "-");
	printf(" %s %s ", "-", "?");
}
