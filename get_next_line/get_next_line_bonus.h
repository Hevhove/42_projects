/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:33:27 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/16 17:57:36 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct s_i
{
	long long	i;
	long long	j;
	long long	k;
};

char	*get_next_line(int fd);
long	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strnjoin(const char *s1, char *s2, struct s_i i);
void	*ft_memcpy(void *dst, const void *src, long long n);
char	*ft_strchr(const char *s, int c);

#endif
