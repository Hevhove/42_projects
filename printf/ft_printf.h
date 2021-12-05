/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:51:17 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/12/05 20:40:59 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXUPPER "0123456789ABCDEF"
# define HEXLOWER "0123456789abcdef"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_puthex(size_t dec, int mode);
void	ft_putptr(void *p);
void	ft_putnbr(int i);
void	ft_putunbr(size_t i);
int		ft_printf(const char *s, ...);

#endif
