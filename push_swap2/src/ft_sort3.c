/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:33:58 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/03 18:15:03 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort3(t_stack **s_a, t_stack **s_b, char **comms)
{
	int	first;
	int	second;
	int	third;

	first = (*s_a)->num;
	second = (*s_a)->next->num;
	third = (*s_a)->next->next->num;
	if (ft_stcsize(s_a) == 2 && !ft_is_sorted(s_a))
		ft_exec_oper_s(s_a, s_b, "sa", comms);
	else if (first < second && second > third && first < third)
	{
		ft_exec_oper_rr(s_a, s_b, "rra", comms);
		ft_exec_oper_s(s_a, s_b, "sa", comms);
	}
	else if (first > second && second < third && first < third)
		ft_exec_oper_s(s_a, s_b, "sa", comms);
	else if (first < second && second > third && first > third)
		ft_exec_oper_rr(s_a, s_b, "rra", comms);
	else if (first > second && second < third && first > third)
		ft_exec_oper_r(s_a, s_b, "ra", comms);
	else if (first > second && second > third && third < first)
	{
		ft_exec_oper_s(s_a, s_b, "sa", comms);
		ft_exec_oper_rr(s_a, s_b, "rra", comms);
	}
}
