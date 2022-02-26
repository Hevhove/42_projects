/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:07:18 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/26 19:59:08 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	heredoc_arg(char *arg, int argc, t_ppx *ppx)
{
	if (argc < 5)
	{
		ft_printf("Usage: ./pipex infile cmd_1 ... cmd_i ... cmd_n outfile");
		exit(1);
	}
	if (ft_strncmp(arg, "here_doc", 9) == 0)
		ppx->heredoc = 1;
	else
		ppx->heredoc = 0;
}

void	ft_unlink(int infile)
{
	if (infile < 0)
	{
		unlink(".heredoc_tmp");
		perror("error: ");
		exit (3);
	}
}

void	heredoc_input(char *limiter, t_ppx *ppx)
{
	int		file;
	char	*line;

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 000644);
	if (file < 0)
	{
		printf("file: %d\n", file);
		perror("error: ");
	}
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		line = get_next_line(0);
		if (!line)
			exit(1);
		if (!ft_strncmp(limiter, line, ft_strlen(limiter)))
			break ;
		write(file, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(file);
	ppx->infile = open(".heredoc_tmp", O_RDONLY);
}
