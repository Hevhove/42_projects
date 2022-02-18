/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:29:49 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/18 17:41:29 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
	{
		perror("Error: ");
		exit(4);
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

int	file_permission_check(char *f1_name, int mode)
{
	if (mode == 0)
	{
		if (access(f1_name, F_OK | R_OK) != 0)
		{
			ft_printf("permission denied: %s\n", f1_name);
			exit(2);
		}
	}
	else
	{
		if (access(f1_name, F_OK) == 0 && access(f1_name, W_OK) < 0)
		{
			ft_printf("permission denied: %s\n", f1_name);
			exit(2);
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		f1;
	int		f2;

	if (argc != 5)
	{
		ft_printf("Usage : .pipex infile cmd1 cmd2 outfile");
		return (1);
	}
	file_permission_check(argv[1], 0);
	f1 = open(argv[1], O_RDONLY);
	if (!file_permission_check(argv[4], 1))
		f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (3);
	pipex(f1, f2, argv, envp);
	close(f1);
	close(f2);
	return (0);
}
