/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_opers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:34:26 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/08 15:40:15 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_ex_op_s(t_stack **s_a, t_stack **s_b, const char *op, char **c)
{
	char	*tmp;

	tmp = *c;
	if (ft_strncmp(op, "ss", 2) == 0)
	{
		ft_swap(s_a);
		ft_swap(s_b);
		*c = ft_strjoin(*c, "ss\n");
		free(tmp);
	}
	else if (ft_strncmp(op, "sa", 2) == 0)
	{
		ft_swap(s_a);
		*c = ft_strjoin(*c, "sa\n");
		free(tmp);
	}
	else if (ft_strncmp(op, "sb", 2) == 0)
	{
		ft_swap(s_b);
		*c = ft_strjoin(*c, "sb\n");
		free(tmp);
	}
}

void	ft_ex_op_p(t_stack **s_a, t_stack **s_b, const char *op, char **c)
{
	char	*tmp;

	tmp = *c;
	if (ft_strncmp(op, "pa", 2) == 0)
	{
		ft_push(s_b, s_a);
		*c = ft_strjoin(*c, "pa\n");
		free(tmp);
	}
	else if (ft_strncmp(op, "pb", 2) == 0)
	{
		ft_push(s_a, s_b);
		*c = ft_strjoin(*c, "pb\n");
		free(tmp);
	}
}

void	ft_ex_op_r(t_stack **s_a, t_stack **s_b, const char *op, char **c)
{
	char	*tmp;

	tmp = *c;
	if (ft_strncmp(op, "rr", 2) == 0)
	{
		ft_rotate(s_a);
		ft_rotate(s_b);
		*c = ft_strjoin(*c, "rr\n");
	}
	else if (ft_strncmp(op, "ra", 2) == 0)
	{
		ft_rotate(s_a);
		*c = ft_strjoin(*c, "ra\n");
	}
	else if (ft_strncmp(op, "rb", 2) == 0)
	{
		ft_rotate(s_b);
		*c = ft_strjoin(*c, "rb\n");
	}
	free(tmp);
}

void	ft_ex_op_rr(t_stack **s_a, t_stack **s_b, const char *op, char **c)
{
	char	*tmp;

	tmp = *c;
	if (ft_strncmp(op, "rrr", 3) == 0)
	{
		ft_rev_rotate(s_a);
		ft_rev_rotate(s_b);
		*c = ft_strjoin(*c, "rrr\n");
		free(tmp);
	}
	else if (ft_strncmp(op, "rra", 3) == 0)
	{
		ft_rev_rotate(s_a);
		*c = ft_strjoin(*c, "rra\n");
		free(tmp);
	}
	else if (ft_strncmp(op, "rrb", 3) == 0)
	{
		ft_rev_rotate(s_b);
		*c = ft_strjoin(*c, "rrb\n");
		free(tmp);
	}
}
