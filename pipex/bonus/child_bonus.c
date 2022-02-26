/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:16:09 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/26 19:57:32 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	free_children(t_ppx *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

char	*get_cmd(char **paths, char *cmd)
{
	int		i;
	char	*inter;
	char	*cmd_path;

	i = 0;
	while (paths[i])
	{
		inter = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(inter, cmd);
		free(inter);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

// fd[0] // fd[2] // fd[4] --> reading from the prev pipe
// fd[3] // fd[5] // fd[7] --> writing to the next pipe

void	new_dup2(int i, int j)
{
	dup2(i, 0);
	dup2(j, 1);
}

void	child(t_ppx *ppx, char **argv, char **envp, int i)
{
	ppx->pid = fork();
	if (!ppx->pid)
	{
		if (i == 0)
			new_dup2(ppx->infile, ppx->fd[1]);
		else if (i == ppx->cmd_num - 1)
			new_dup2(ppx->fd[2 * i - 2], ppx->outfile);
		else
			new_dup2(ppx->fd[2 * i - 2], ppx->fd[2 * i + 1]);
		close_pipes(ppx);
		ppx->cmd_args = ft_split(argv[2 + ppx->heredoc + i], ' ');
		ppx->cmd = get_cmd(ppx->paths, ppx->cmd_args[0]);
		if (!ppx->cmd)
		{
			perror("error ");
			free_children(ppx);
			exit(1);
		}
		execve(ppx->cmd, ppx->cmd_args, envp);
	}
}
