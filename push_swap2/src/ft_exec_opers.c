/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_opers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:34:26 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/04 10:26:39 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_exec_oper_s(t_stack **s_a, t_stack **s_b, const char *op, char **comms)
{
	char *tmp;

	tmp = *comms;
	if (ft_strncmp(op, "ss", 2) == 0)
	{
		ft_swap(s_a);
		ft_swap(s_b);
		*comms = ft_strjoin(*comms, "ss\n");
		free(tmp);
	}
	else if (ft_strncmp(op, "sa", 2) == 0)
	{
		ft_swap(s_a);
		*comms = ft_strjoin(*comms, "sa\n");
		free(tmp);
	}
	else if (ft_strncmp(op, "sb", 2) == 0)
	{
		ft_swap(s_b);
		*comms = ft_strjoin(*comms, "sb\n");
		free(tmp);
	}
}

void	ft_exec_oper_p(t_stack **s_a, t_stack **s_b, const char *op, char **comms)
{
	char *tmp;

	tmp = *comms;
	if (ft_strncmp(op, "pa", 2) == 0)
	{
		ft_push(s_b, s_a);
		*comms = ft_strjoin(*comms, "pa\n");
		free(tmp);
	}
	else if (ft_strncmp(op, "pb", 2) == 0)
	{
		ft_push(s_a, s_b);
		*comms = ft_strjoin(*comms, "pb\n");
		free(tmp);
	}
}

void	ft_exec_oper_r(t_stack **s_a, t_stack **s_b, const char *op, char **comms)
{
	char *tmp;

	tmp = *comms;
	if (ft_strncmp(op, "rr", 2) == 0)
	{
		ft_rotate(s_a);
		ft_rotate(s_b);
		*comms = ft_strjoin(*comms, "rr\n");
	}
	else if (ft_strncmp(op, "ra", 2) == 0)
	{
		ft_rotate(s_a);
		*comms = ft_strjoin(*comms, "ra\n");
	}
	else if (ft_strncmp(op, "rb", 2) == 0)
	{
		ft_rotate(s_b);
		*comms = ft_strjoin(*comms, "rb\n");
	}
	free(tmp);
}

void	ft_exec_oper_rr(t_stack **s_a, t_stack **s_b, const char *op, char **comms)
{
	char *tmp;

	tmp = *comms;
	if (ft_strncmp(op, "rrr", 3) == 0)
	{
		ft_rev_rotate(s_a);
		ft_rev_rotate(s_b);
		*comms = ft_strjoin(*comms, "rrr\n");
		free(tmp);
	}
	else if (ft_strncmp(op, "rra", 3) == 0)
	{
		ft_rev_rotate(s_a);
		*comms = ft_strjoin(*comms, "rra\n");
		free(tmp);
	}
	else if (ft_strncmp(op, "rrb", 3) == 0)
	{
		ft_rev_rotate(s_b);
		*comms = ft_strjoin(*comms, "rrb\n");
		free(tmp);
	}
}
