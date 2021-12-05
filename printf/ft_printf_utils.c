/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:51:27 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/12/05 20:59:29 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_puthex(size_t dec, int mode)
{
	if (dec < 16)
	{
		if (mode == 0)
			ft_putchar(HEXLOWER[dec]);
		else
			ft_putchar(HEXUPPER[dec]);
	}
	else
	{
		ft_puthex(dec / 16, mode);
		if (mode == 0)
			ft_putchar(HEXLOWER[dec % 16]);
		else
			ft_putchar(HEXUPPER[dec % 16]);
	}
}

void	ft_putptr(void *p)
{
	size_t	i;

	i = (size_t)p;
	ft_putstr("0x");
	ft_puthex(i, 0);
}

void	ft_putnbr(int i)
{
	if (i == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else
	{
		if (i < 0)
		{
			ft_putchar('-');
			i *= -1;
		}
		if (i > 9)
		{
			ft_putnbr(i / 10);
		}
		ft_putchar(i % 10 + '0');
	}
}

/*
int main(void)
{
    char *s = "hello";
    
    //ft_putchar('a');
    //ft_putstr("hello!");
    //ft_putnbr(-256345);
    ft_putptr(s);
}
*/
