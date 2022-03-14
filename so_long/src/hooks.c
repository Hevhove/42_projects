/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:52:19 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/14 15:40:38 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("Hello from key_hook: %d\n", keycode);
	return (0);
}

int	mouse_hook(int mousecode, t_vars *vars)
{
	(void)vars;
	(void)mousecode;
	printf("check\n");
	return (0);
}

// int	render_next_frame()
