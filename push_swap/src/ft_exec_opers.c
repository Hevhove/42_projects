/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_opers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:26:38 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/01/28 16:11:20 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_exec_oper_s(t_stack **s_a, t_stack **s_b, const char *op, char ***c)
{
	if (ft_strncmp(op, "ss", 2) == 0)
	{
		ft_swap(s_a);
		ft_swap(s_b);
		*c = ft_add_com("ss", *c);
	}
	else if (ft_strncmp(op, "sa", 2) == 0)
	{
		ft_swap(s_a);
		*c = ft_add_com("sa", *c);
	}
	else if (ft_strncmp(op, "sb", 2) == 0)
	{
		ft_swap(s_b);
		*c = ft_add_com("sb", *c);
	}
}

void	ft_exec_oper_p(t_stack **s_a, t_stack **s_b, const char *op, char ***c)
{
	if (ft_strncmp(op, "pa", 2) == 0)
	{
		ft_push(s_b, s_a);
		*c = ft_add_com("pa", *c);
	}
	else if (ft_strncmp(op, "pb", 2) == 0)
	{
		ft_push(s_a, s_b);
		*c = ft_add_com("pb", *c);
	}
}

void	ft_exec_oper_r(t_stack **s_a, t_stack **s_b, const char *op, char ***c)
{
	if (ft_strlen(op) == 2 && ft_strncmp(op, "rr", 2) == 0)
	{
		ft_rotate(s_a);
		ft_rotate(s_b);
		*c = ft_add_com("rr", *c);
	}
	else if (ft_strlen(op) == 2 && ft_strncmp(op, "ra", 2) == 0)
	{
		ft_rotate(s_a);
		*c = ft_add_com("ra", *c);
	}
	else if (ft_strlen(op) == 2 && ft_strncmp(op, "rb", 2) == 0)
	{
		ft_rotate(s_b);
		*c = ft_add_com("rb", *c);
	}
}

void	ft_exec_oper_rr(t_stack **s_a, t_stack **s_b, const char *op, char ***c)
{
	if (ft_strlen(op) == 3 && ft_strncmp(op, "rrr", 3) == 0)
	{
		ft_rev_rotate(s_a);
		ft_rev_rotate(s_b);
		*c = ft_add_com("rrr", *c);
	}
	else if (ft_strlen(op) == 3 && ft_strncmp(op, "rra", 3) == 0)
	{
		ft_rev_rotate(s_a);
		*c = ft_add_com("rra", *c);
	}
	else if (ft_strlen(op) == 3 && ft_strncmp(op, "rrb", 3) == 0)
	{
		ft_rev_rotate(s_b);
		*c = ft_add_com("rrb", *c);
	}
}
