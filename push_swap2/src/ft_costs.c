/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:28:42 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/06 15:30:00 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_calc_costs_b(int *cost_b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (i < (len / 2) + 1)
			cost_b[i] = i;
		else
			cost_b[i] = (i - len);
		i++;
	}
}

int	find_best_index_a(t_stack **s_a, t_stack *tmp1)
{
	t_stack	*tmp2;
	int		i;
	int		diff;
	int		best_index;

	tmp2 = *s_a;
	diff = MIN_INT;
	i = 0;
	while (tmp2 != NULL)
	{
		if (tmp1->num < get_min_el(s_a) || tmp1->num > get_max_el(s_a))
			best_index = get_min_index(s_a);
		else if (tmp1->num - tmp2->num > diff && tmp1->num - tmp2->num < 0)
		{
			diff = tmp1->num - tmp2->num;
			best_index = i;
		}
		i++;
		tmp2 = tmp2->next;
	}
	return (best_index);
}

void	ft_calc_costs_a(t_stack **s_a, t_stack **s_b, int *cost_a)
{
	t_stack	*tmp1;
	int		best_index;
	int		i;

	tmp1 = *s_b;
	i = 0;
	while (tmp1 != NULL)
	{
		best_index = find_best_index_a(s_a, tmp1);
		cost_a[i] = refactor_index(best_index, ft_stcsize(s_a));
		tmp1 = tmp1->next;
		i++;
	}
}

int	ft_find_best_index(int *cost_tot, int len)
{
	int	min_cost;
	int	i;
	int	best_index;

	min_cost = MAX_INT;
	i = 0;
	while (i < len)
	{
		if (cost_tot[i] <= min_cost)
		{
			min_cost = cost_tot[i];
			best_index = i;
		}
		i++;
	}
	return (best_index);
}

int	refactor_index(int best_index, int len)
{
	if (best_index < (len / 2) + 1)
		return (best_index);
	else
		return (best_index - len);
}
