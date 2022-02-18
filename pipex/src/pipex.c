/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:29:49 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/18 11:51:34 by hvan-hov         ###   ########.fr       */
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
	close(fd[0]); // do we close in this scope or in pipex scope?
	close(f1);
	// maybe still close fd[1]?
	paths = ft_split(find_path(envp), ':');
	cmdargs = ft_split(cmd_in, ' ');
	i = -1;
	while (paths[++i])
	{
		inter = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(inter, cmdargs[0]); // TODO: PROTECT THIS!!
		free(inter);
		// ft_printf("Currently checking: %s\n", cmd);
		execve(cmd_path, cmdargs, envp); // if this succeeds, it will take over the entire process;
		free(cmd_path);
	}
	exit(1); // error code if we fail
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
	close(fd[1]); // do we close in this scope or in pipex scope?
	close(f2);
	// maybe still close fd[1]?
	paths = ft_split(find_path(envp), ':');
	cmdargs = ft_split(cmd_in, ' ');
	i = -1;
	while (paths[++i])
	{
		inter = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(inter, cmdargs[0]); // TODO: PROTECT THIS!!
		free(inter);
		execve(cmd_path, cmdargs, envp); // if this succeeds, it will take over the entire process;
		free(cmd_path);
	}
	exit(1); // error code if we fail
}

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
	{
		perror("Error: ");
		exit(1);
	}
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork error: "));
	if (pid1 == 0)
		child1(f1, argv[2], fd, envp);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("Fork error: "));
	if (pid2 == 0)
		child2(f2, argv[3], fd, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int main(int argc, char **argv, char **envp)
{
	int		f1;
	int		f2;
	
	if (argc != 5)
	{
		ft_printf("Usage : .pipex infile cmd1 cmd2 outfile");
		return (1);
	}
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
	pipex(f1, f2, argv, envp);
	return (0);
}
