/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:14:34 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/26 17:21:18 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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
}	t_ppx;

char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	child(t_ppx *ppx, char **argv, char **envp, int i);
size_t	ft_strlen(const char *str);
void	close_pipes(t_ppx *ppx);

