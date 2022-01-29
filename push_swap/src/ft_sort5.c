/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:50:43 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/01/29 20:47:09 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_determine_rot(t_stack **s_a, t_stack **s_b, char ***comm_list)
{
	int		pos;
	t_stack	*tmp;

	tmp = *s_a;
	pos = 1;
	while (tmp->next != NULL)
	{
		if ((*s_b)->num > tmp->num && (*s_b)->num < tmp->next->num)
			break ;
		pos++;
		tmp = tmp->next;
	}
	if (pos == 1)
		ft_exec_oper_r(s_a, s_b, "ra", comm_list);
	else if (pos == 2)
	{
		ft_exec_oper_r(s_a, s_b, "ra", comm_list);
		ft_exec_oper_r(s_a, s_b, "ra", comm_list);
	}
	else if (pos == 3)
		ft_exec_oper_rr(s_a, s_b, "rra", comm_list);
}

void	rotate_min_on_top(t_stack **s_a, t_stack **s_b, char ***comm_list)
{
	int	min_ind;

	min_ind = get_el_index(s_a, get_min_el(s_a));
	while (min_ind != 0)
	{
		if (min_ind < ft_stcsize(s_a) / 2)
			ft_exec_oper_r(s_a, s_b, "ra", comm_list);
		else
			ft_exec_oper_rr(s_a, s_b, "rra", comm_list);
		min_ind = get_el_index(s_a, get_min_el(s_a));
	}
}

void	sort_5(t_stack **s_a, t_stack **s_b, char ***comm_list)
{
	if (ft_stcsize(s_a) == 5)
		ft_exec_oper_p(s_a, s_b, "pb", comm_list);
	ft_exec_oper_p(s_a, s_b, "pb", comm_list);
	sort_3(s_a, s_b, comm_list);
	while (ft_stcsize(s_b) != 0)
	{
		if ((*s_b)->num < get_min_el(s_a) || (*s_b)->num > get_max_el(s_a))
		{
			if (get_el_index(s_a, get_min_el(s_a)) != 0)
				rotate_min_on_top(s_a, s_b, comm_list);
			ft_exec_oper_p(s_a, s_b, "pa", comm_list);
		}
		else
		{
			ft_determine_rot(s_a, s_b, comm_list);
			ft_exec_oper_p(s_a, s_b, "pa", comm_list);
		}
	}
	rotate_min_on_top(s_a, s_b, comm_list);
}
