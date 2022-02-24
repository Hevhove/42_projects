/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:20:39 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/21 17:58:12 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

// gnl struct
struct s_i
{
	long long	i;
	long long	j;
	long long	k;
};

// Add printf library header
# include "../printf/ft_printf.h"

// write, read, close, access, pipe, dup, dup2, execve, fork
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

// Function Prototypes
void	child1(int f1, char *cmd_in, int fd[2], char **envp);
void	child2(int f2, char *cmd_in, int fd[2], char **envp);
char	*find_path(char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strnjoin(const char *s1, char *s2, struct s_i i);
void	*ft_memcpy(void *dst, const void *src, long long n);
char	*ft_strchr(const char *s, int c);

#endif
