/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:14:34 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/26 19:59:49 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_ppx
{
	int		infile;
	int		outfile;
	int		pipe_num;
	int		*fd;
	int		cmd_num;
	char	**paths;
	int		pid;
	char	**cmd_args;
	char	*cmd;
	int		heredoc;
}	t_ppx;

typedef struct s_i
{
	long long	i;
	long long	j;
	long long	k;
}	t_i;

char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	child(t_ppx *ppx, char **argv, char **envp, int i);
void	close_pipes(t_ppx *ppx);
void	heredoc_input(char *limiter, t_ppx *ppx);
char	*ft_strnjoin(const char *s1, char *s2, struct s_i it);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, long long n);
char	*ft_strdup(const char *s1);
void	add_store(char **result, char *buffer);
int		rd_nx(char **result, char *buf, int fd);
char	*get_next_line(int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
void	heredoc_input(char *limiter, t_ppx *ppx);
void	heredoc_arg(char *arg, int argc, t_ppx *ppx);
void	create_pipes(t_ppx *ppx);
void	close_pipes(t_ppx *ppx);
void	free_parent(t_ppx *ppx);
int		ft_printf(const char *s, ...);

#endif
