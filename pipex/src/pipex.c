/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:29:49 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/17 20:03:15 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// ALLOWED FUNCTIONS: 
// open, close, read, write, malloc, free
// perror, strerror, access, dup, dup2, execve
// exit, fork, pipe, unlink, wait, waitpid
// ft_printf

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	child1(int f1, char **argv, int fd[2], char **envp)
{
	char	**paths;
	char	**cmdargs;
	char	*cmd;
	int		i;
	
	dup2(f1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]); // do we close in this scope or in pipex scope?
	close(f1);
	// maybe still close fd[1]?
	paths = ft_split(find_path(envp), ':');
	cmdargs = ft_split(argv[2], " ");
	i = 0;
	while (paths[i])
	{
		cmd = ft_strjoin(paths[i], argv[2]); // TODO: PROTECT THIS!!
		execve(cmd, cmdargs, envp); // if this succeeds, it will take over the entire process;
		free(cmd);
	}
	return (1); // error code if we fail
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
		child1(f1, argv, fd, envp);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("Fork error: "));
	if (pid2 == 0)
		child2(f2, argv, fd, envp);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int main(int argc, char **argv, char **envp)
{
	int		f1;
	int		f2;
	// char	**paths;
	
	// ./pipex infile "ls -l" "wc -l" outfile

	// if (argc != 5)
	// {
	// 	ft_printf("Usage : .pipex infile cmd1 cmd2 outfile");
	// 	return (1);
	// }
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
	// paths = ft_split(find_path(envp), ':');
	pipex(f1, f2, argv + 1, envp);
	if (pid1 == 0) // CHILD PROCESS
	{
		if (execve("/bin/ls", argv, envp) == -1)
		{
			ft_printf("error");
			return (2);
		}
		// this process is now taken over and terminates
	}
	// no need for an else because process will be taken over
	// above and only parent will be running
	return (0);
}
