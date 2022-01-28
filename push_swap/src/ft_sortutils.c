/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:26:38 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/01/27 19:37:45 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_sorted(t_stack **stc)
{
	t_stack *tmp;

	tmp = *stc;
	while (tmp->next != NULL)
	{
		if (tmp->num > tmp->next->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_is_valid_oper(const char *op)
{
	if (ft_strncmp(op, "sa", 2) == 0
		|| ft_strncmp(op, "sb", 2) == 0
		|| ft_strncmp(op, "ss", 2) == 0
		|| ft_strncmp(op, "pa", 2) == 0
		|| ft_strncmp(op, "pb", 2) == 0
		|| ft_strncmp(op, "ra", 2) == 0
		|| ft_strncmp(op, "rb", 2) == 0
		|| ft_strncmp(op, "rr", 2) == 0
		|| ft_strncmp(op, "rra", 3) == 0
		|| ft_strncmp(op, "rrb", 3) == 0
		|| ft_strncmp(op, "rrr", 3) == 0)
		return (1);
	return (0);
}

int ft_exec_oper(t_stack **s_a, t_stack **s_b, const char *op)
{
	if (!ft_is_valid_oper(op))
		return (ERROR_CODE);
	if (ft_strncmp(op, "sa", 2) == 0 || ft_strncmp(op, "ss", 2) == 0)
		ft_swap(s_a);
	if (ft_strncmp(op, "sb", 2) == 0 || ft_strncmp(op, "ss", 2) == 0)
		ft_swap(s_b);
	if (ft_strncmp(op, "pa", 2) == 0)
		ft_push(s_b, s_a);
	if (ft_strncmp(op, "pb", 2) == 0)
		ft_push(s_a, s_b);
	if (ft_strlen(op) == 2 && (ft_strncmp(op, "ra", 2) == 0 || ft_strncmp(op, "rr", 2) == 0))
		ft_rotate(s_a);
	if (ft_strlen(op) == 2 && (ft_strncmp(op, "rb", 2) == 0 || ft_strncmp(op, "rr", 2) == 0))
		ft_rotate(s_b);
	if (ft_strncmp(op, "rra", 3) == 0 || ft_strncmp(op, "rrr", 3) == 0)
		ft_rev_rotate(s_a);
	if (ft_strncmp(op, "rrb", 3) == 0 || ft_strncmp(op, "rrr", 3) == 0)
		ft_rev_rotate(s_b);
	return (0);
}
