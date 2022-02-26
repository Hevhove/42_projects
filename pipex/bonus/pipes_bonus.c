/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:40:37 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/26 19:54:05 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	create_pipes(t_ppx *ppx)
{
	int	i;

	i = 0;
	while (i < ppx->cmd_num - 1)
	{
		if (pipe(ppx->fd + 2 * i) < 0)
			free_parent(ppx);
		i++;
	}
}

void	close_pipes(t_ppx *ppx)
{
	int	i;

	i = 0;
	while (i < (ppx->pipe_num))
	{
		close(ppx->fd[i]);
		i++;
	}
}
