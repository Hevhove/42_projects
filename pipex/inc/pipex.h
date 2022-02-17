/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:20:39 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/17 19:31:38 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Add printf library header
#include "../printf/ft_printf.h"

// write, read, close, access, pipe, dup, dup2, execve, fork
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

// Function Prototypes
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);

#endif
