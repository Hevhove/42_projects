/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:29:49 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/21 17:43:49 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

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
	while (smaller than amount of commands)
	{
		// all below in child function?
		pid1 = fork();
		if (pid1 == 0)
		{
			// dup2 change infile becomes stdin, stdout becomes write into pipe
		}
		else if (we are at the end of commands)
		{
			// dup2 change stdin to read from pipe, stdout to outfile
		}
		else (we are in the middle of commands)
		{
			// dup2 change stdin to read from pipe, stdout to pipe write if we are not at the end of the commands
		}
		// close the unneeded pipes
		// build paths
		// build cmdargs
		// paths[++i] function
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

void	get_infile(char **argv)
{
	if (!ft_strncmp("here_doc", argv[1], 9))
		here_doc(argv[2], );
	else
	{
		
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		f1;
	int		f2;
	int		cmd_num;
	int		here_doc;
	char	*line;

	if (argc < 5)
	{
		ft_printf("Usage : ./pipex [here_doc] infile cmd1 cmd2 ... cmdn outfile");
		return (1);
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		here_doc = 1;
	else
		here_doc = 0;
	cmd_num = argc - 3 - here_doc;
	file_permission_checks(argv[1 + here_doc], 0);
	f1 = open(argv[1 + here_doc], O_RDONLY);
	if (!file_permission_check(argv[argc - 1], 1))
		f2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (3);
	pipex(f1, f2, argv, envp);
	close(f1);
	close(f2);
	return (0);
}

// if we are in "here_doc" mode, we basically don't use an infile
// but we use the STDIN until we find a delimiter
// get_next_line?
