/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortmore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:32:35 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/06 15:39:57 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_sorted(t_stack **stc)
{
	t_stack	*tmp;

	tmp = *stc;
	while (tmp->next != NULL)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_calc_lowest_cost(int *cost_a, int *cost_b, int len)
{
	int	*cost_tot;
	int	i;
	int	best_index;

	cost_tot = (int *)malloc(len * sizeof(int));
	i = 0;
	while (i < len)
	{
		if (cost_a[i] > 0 && cost_b[i] > 0)
			cost_tot[i] = get_max(cost_a[i], cost_b[i]);
		else if (cost_a[i] < 0 && cost_b[i] < 0)
			cost_tot[i] = ft_abs(get_min(cost_a[i], cost_b[i]));
		else
			cost_tot[i] = ft_abs(cost_a[i]) + ft_abs(cost_b[i]);
		i++;
	}
	best_index = ft_find_best_index(cost_tot, len);
	free(cost_tot);
	return (best_index);
}

void	ft_exec_moves(t_stack **s_a, t_stack **s_b, t_costs cost, char **comms)
{
	while (cost.a > 0)
	{
		ft_exec_oper_r(s_a, s_b, "ra", comms);
		cost.a--;
	}
	while (cost.a < 0)
	{
		ft_exec_oper_rr(s_a, s_b, "rra", comms);
		cost.a++;
	}
	while (cost.b > 0)
	{
		ft_exec_oper_r(s_a, s_b, "rb", comms);
		cost.b--;
	}
	while (cost.b < 0)
	{
		ft_exec_oper_rr(s_a, s_b, "rrb", comms);
		cost.b++;
	}
	ft_exec_oper_p(s_a, s_b, "pa", comms);
}

void	ft_finalsort(t_stack **s_a, t_stack **s_b, char **comms)
{
	while (!ft_is_sorted(s_a))
	{
		if (get_min_index(s_a) < (ft_stcsize(s_a) / 2) + 1)
			ft_exec_oper_r(s_a, s_b, "ra", comms);
		else
			ft_exec_oper_rr(s_a, s_b, "rra", comms);
	}
}

void	ft_sortmore(t_stack **s_a, t_stack **s_b, char **comms)
{
	int		*cost_a;
	int		*cost_b;
	int		len;
	int		best_index;
	t_costs	cost_index;

	while (ft_stcsize(s_a) != 3)
		ft_exec_oper_p(s_a, s_b, "pb", comms);
	ft_sort3(s_a, s_b, comms);
	while (ft_stcsize(s_b) != 0)
	{
		len = ft_stcsize(s_b);
		cost_a = (int *)malloc(len * sizeof(int));
		cost_b = (int *)malloc(len * sizeof(int));
		ft_calc_costs_b(cost_b, len);
		ft_calc_costs_a(s_a, s_b, cost_a);
		best_index = ft_calc_lowest_cost(cost_a, cost_b, len);
		cost_index.a = cost_a[best_index];
		cost_index.b = cost_b[best_index];
		ft_exec_moves(s_a, s_b, cost_index, comms);
		free(cost_a);
		free(cost_b);
	}
	ft_finalsort(s_a, s_b, comms);
}
