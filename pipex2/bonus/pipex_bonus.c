/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:06:29 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/26 17:19:01 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

// int	perm_check(char *file, int mode)
// {
// 	if (mode == 0 && !access(file, F_OK | R_OK))
// 		return (1);
// 	else if (mode == 1 && !access(file, F_OK | W_OK))
// 		return (1);
// 	else
// 		return (0);
// }

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] && str2[i] && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i < n)
		return (str1[i] - str2[i]);
	return (0);
}



void	open_files(t_ppx *ppx, int argc, char **argv)
{
	if (access(argv[1], F_OK | R_OK))
	{
		printf("Can't write to infile\n");
		exit(1);
	}
	ppx->infile = open(argv[1], O_RDONLY);
	if (!access(argv[argc - 1], F_OK) && access(argv[argc - 1], W_OK))
	{
		printf("Can't write to outfile\n");
		exit(2);
	}
	ppx->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (ppx->infile < 0 || ppx->outfile < 0)
	{
		printf("Problem with creating file descriptors\n");
		exit(3);
	}
}

void	free_parent(t_ppx *ppx)
{
	int i;

	i = 0;
	close(ppx->infile);
	close(ppx->outfile);
	while(ppx->paths[i])
	{
		free(ppx->paths[i]);
		i++;
	}
	free(ppx->paths);
	free(ppx->fd);
}

void	create_pipes(t_ppx *ppx, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < ppx->cmd_num - 1)
	{
		if (pipe(ppx->fd + 2 * i) < 0)
			free_parent(ppx);	// basically this creates a pipe in spot 0 and 1, then in 2 and 3
		i++;
	}
}

void	close_pipes(t_ppx *ppx)
{
	int i;
	
	i = 0;
	while (i < (ppx->pipe_num))
	{
		close(ppx->fd[i]);
		i++;
	}
}

char *find_path(char **envp)
{
	while(ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_ppx ppx;
	int		i;
	
	// if (argc < 5)
	// {
	// 	printf("Usage: ./pipex infile cmd_1 ... cmd_i ... cmd_n outfile");	
	// 	exit(1);
	// }
	ppx.cmd_num = argc - 3;
	ppx.pipe_num = 2 * (ppx.cmd_num - 1);
	ppx.fd = (int *)malloc(ppx.pipe_num * sizeof(int));
	if (!ppx.fd)
		return (10);
	// open the files
	open_files(&ppx, argc, argv);
	// create some pipes
	create_pipes(&ppx, argc, argv);
	// find the paths in envp
	ppx.paths = ft_split(find_path(envp), ':');
	if (!ppx.paths)
		return (10);
	i = -1;
	while (++i < ppx.cmd_num)
		child(&ppx, argv, envp, i);
	close_pipes(&ppx);
	waitpid(-1, NULL, 0); // this waits for all child processes to finish
	free_parent(&ppx);
	return (0);
}
