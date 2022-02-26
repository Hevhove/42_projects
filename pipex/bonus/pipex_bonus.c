/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:06:29 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/26 19:54:43 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	open_files(t_ppx *ppx, int ac, char **argv)
{
	if (ppx->heredoc == 0 && !access(argv[1], F_OK | R_OK))
		ppx->infile = open(argv[1], O_RDONLY);
	else if (ppx->heredoc == 0 && access(argv[1], F_OK | R_OK))
	{
		ft_printf("Can't write to infile\n");
		exit(1);
	}
	else
		heredoc_input(argv[2], ppx);
	if (!access(argv[ac - 1], F_OK) && access(argv[ac - 1], W_OK))
	{
		ft_printf("Can't write to outfile\n");
		exit(2);
	}
	if (ppx->heredoc == 0)
		ppx->outfile = open(argv[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		ppx->outfile = open(argv[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (ppx->infile < 0 || ppx->outfile < 0)
	{
		ft_printf("Problem with creating file descriptors\n");
		exit(3);
	}
}

void	free_parent(t_ppx *ppx)
{
	int	i;

	i = 0;
	close(ppx->infile);
	close(ppx->outfile);
	if (ppx->heredoc)
		unlink(".heredoc_tmp");
	while (ppx->paths[i])
	{
		free(ppx->paths[i]);
		i++;
	}
	free(ppx->paths);
	free(ppx->fd);
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int ac, char **argv, char **envp)
{
	t_ppx	ppx;
	int		i;

	heredoc_arg(argv[1], ac, &ppx);
	ppx.cmd_num = ac - 3 - ppx.heredoc;
	ppx.pipe_num = 2 * (ppx.cmd_num - 1);
	ppx.fd = (int *)malloc(ppx.pipe_num * sizeof(int));
	if (!ppx.fd)
		return (10);
	open_files(&ppx, ac, argv);
	create_pipes(&ppx);
	ppx.paths = ft_split(find_path(envp), ':');
	if (!ppx.paths)
		return (10);
	i = -1;
	while (++i < ppx.cmd_num)
		child(&ppx, argv, envp, i);
	close_pipes(&ppx);
	waitpid(-1, NULL, 0);
	free_parent(&ppx);
	return (0);
}
