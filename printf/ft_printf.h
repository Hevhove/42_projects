/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:51:17 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/12/06 15:46:32 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXUPPER "0123456789ABCDEF"
# define HEXLOWER "0123456789abcdef"
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define LONG_MIN -9223372036854775808
# define LONG_MAX +9223372036854775807
# define UINT_MAX 4294967295
# define ULONG_MAX 18446744073709551615

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_puthex(size_t dec, int mode, int count);
int		ft_putptr(void *p);
int		ft_putnbr(int i, int ret);
int		ft_putunbr(size_t i, int ret);
int		ft_printf(const char *s, ...);

#endif
