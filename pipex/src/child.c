/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:38:34 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/26 19:50:05 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	child1(int f1, char *cmd_in, int fd[2], char **envp)
{
	char	**paths;
	char	**cmdargs;
	char	*cmd_path;
	char	*inter;
	int		i;

	dup2(f1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(f1);
	paths = ft_split(find_path(envp), ':');
	cmdargs = ft_split(cmd_in, ' ');
	i = -1;
	while (paths[++i])
	{
		inter = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(inter, cmdargs[0]);
		if (!cmd_path || !inter)
			exit(1);
		if (access(cmd_path, F_OK | X_OK) == 0)
			execve(cmd_path, cmdargs, envp);
	}
	perror("error");
	exit(2);
}

void	child2(int f2, char *cmd_in, int fd[2], char **envp)
{
	char	**paths;
	char	**cmdargs;
	char	*cmd_path;
	char	*inter;
	int		i;

	dup2(fd[0], STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);
	close(fd[1]);
	close(f2);
	paths = ft_split(find_path(envp), ':');
	cmdargs = ft_split(cmd_in, ' ');
	i = -1;
	while (paths[++i])
	{
		inter = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(inter, cmdargs[0]);
		if (!cmd_path || !inter)
			exit(1);
		if (access(cmd_path, F_OK | X_OK) == 0)
			execve(cmd_path, cmdargs, envp);
	}
	perror("error");
	exit(2);
}
