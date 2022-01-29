/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:43:28 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/01/28 15:59:56 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_stack **s_a, t_stack **s_b, char ***comm_list)
{
	int	first;
	int	second;
	int	third;

	first = (*s_a)->num;
	second = (*s_a)->next->num;
	third = (*s_a)->next->next->num;
	if (ft_stcsize(s_a) == 2 && ft_is_sorted(s_a))
		ft_exec_oper_s(s_a, s_b, "sa", comm_list);
	if (first < second && second > third && first < third)
	{
		ft_exec_oper_rr(s_a, s_b, "rra", comm_list);
		ft_exec_oper_s(s_a, s_b, "sa", comm_list);
	}
	else if (first > second && second < third && first < third)
		ft_exec_oper_s(s_a, s_b, "sa", comm_list);
	else if (first < second && second > third && first > third)
		ft_exec_oper_rr(s_a, s_b, "rra", comm_list);
	else if (first > second && second < third && first > third)
		ft_exec_oper_r(s_a, s_b, "ra", comm_list);
	else if (first > second && second > third && third < first)
	{
		ft_exec_oper_s(s_a, s_b, "sa", comm_list);
		ft_exec_oper_rr(s_a, s_b, "rra", comm_list);
	}
}
