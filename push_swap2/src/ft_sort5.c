/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:32:35 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/05 12:59:02 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_max_el(t_stack **s_a)
{
	t_stack	*tmp;
	int		max;

	tmp = *s_a;
	max = MIN_INT;
	while (tmp->next != NULL)
	{
		if (tmp->num > max)
			max = tmp->num;
		tmp = tmp->next;
	}
	if (tmp->num > max)
		max = tmp->num;
	return (max);
}

int	get_min_el(t_stack **s_a)
{
	t_stack	*tmp;
	int		min;

	tmp = *s_a;
	min = MAX_INT;
	while (tmp!= NULL)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_calc_costs_b(int *cost_b, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (i  < (len / 2) + 1)
			cost_b[i] = i;
		else
			cost_b[i] = (i - len);
		i++;
	}
}

int	refactor_index(int best_index, int len)
{
	if (best_index < (len / 2) + 1)
		return (best_index);
	else
		return (best_index - len);
}

int	get_min_index(t_stack **s_a)
{
	t_stack	*tmp;
	int		min;
	int		i;
	int		min_index;

	tmp = *s_a;
	min = MAX_INT;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->num < min)
		{
			min = tmp->num;
			min_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_index);
}

void	ft_calc_costs_a(t_stack **s_a, t_stack **s_b, int *cost_a)
{
	t_stack *tmp1;
	t_stack	*tmp2;
	int		diff;
	int		best_index;
	int		i;
	int		j;
	
	tmp1 = *s_b;
	j = 0;
	while (tmp1 != NULL)
	{
		i = 0;
		tmp2 = *s_a;
		diff = MIN_INT;
		while (tmp2 != NULL)
		{
			if (tmp1->num < get_min_el(s_a) || tmp1->num > get_max_el(s_a))
				best_index = get_min_index(s_a); // when smaller / bigger than all, need to push on top of the smallest element
			else if (tmp1->num - tmp2->num > diff && tmp1->num - tmp2->num < 0)
			{
				diff = tmp1->num - tmp2->num;
				best_index = i;
			}
			i++;
			tmp2 = tmp2->next;
		}
		cost_a[j] = refactor_index(best_index, ft_stcsize(s_a));
		tmp1 = tmp1->next;
		j++;
	}
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_calc_lowest_cost(int *cost_a, int *cost_b, int len)
{
	int	*cost_tot;
	int i;
	int	min_cost;
	int	best_index;
	
	cost_tot = (int *)malloc(len * sizeof(int));
	i = 0;
	while (i < len)
	{
		// printf("cost_a[%d] is: %d\n", i, cost_a[i]);
		// printf("cost_b[%d] is: %d\n", i, cost_b[i]);
		if (cost_a[i] > 0 && cost_b[i] > 0)
			cost_tot[i] = get_max(cost_a[i], cost_b[i]);
		else if (cost_a[i] < 0 && cost_b[i] < 0)
			cost_tot[i] = ft_abs(get_min(cost_a[i], cost_b[i]));
		else
			cost_tot[i] = ft_abs(cost_a[i]) + ft_abs(cost_b[i]);
		// printf("cost_tot[%d] is: %d\n", i, cost_tot[i]);
		i++;
	}
	min_cost = MAX_INT;
	i = 0;
	while (i < len)
	{
		if (cost_tot[i] < min_cost)
		{
			min_cost = cost_tot[i];
			best_index = i;
		}
		i++;
	}
	free(cost_tot);
	return (best_index);
}

void	ft_exec_moves(t_stack **s_a, t_stack **s_b, int a, int b, char **comms)
{
	while (a > 0)
	{
		ft_exec_oper_r(s_a, s_b, "ra", comms);
		a--;
	}
	while (a < 0)
	{
		ft_exec_oper_rr(s_a, s_b, "rra", comms);
		a++;
	}
	while (b > 0)
	{
		ft_exec_oper_r(s_a, s_b, "rb", comms);
		b--;
	}
	while (b < 0)
	{
		ft_exec_oper_rr(s_a, s_b, "rrb", comms);
		b++;
	}
	ft_exec_oper_p(s_a, s_b, "pa", comms);
}

void	ft_sort5(t_stack **s_a, t_stack **s_b, char **comms)
{
	int *cost_a;
	int	*cost_b;
	int	len;
	int best_index;

	while (ft_stcsize(s_a) != 3)
		ft_exec_oper_p(s_a, s_b, "pb", comms);
	ft_sort3(s_a, s_b, comms);
	while (ft_stcsize(s_b) != 0)
	{
		len = ft_stcsize(s_b);
		cost_a = (int *)malloc(len * sizeof(int));
		cost_b = (int *)malloc(len * sizeof(int)); // check the returns of mallocs
		// printf("len is: %d\n", len);
		ft_calc_costs_b(cost_b, len);
		// for (int i = 0; i < len; i++)
		// 	printf("cost_b[%d] is: %d\n", i, cost_b[i]);
		ft_calc_costs_a(s_a, s_b, cost_a);
		// for (int i = 0; i < len; i++)
		// 	printf("cost_a[%d] is: %d\n", i, cost_a[i]);
		best_index = ft_calc_lowest_cost(cost_a, cost_b, len); // select minimum cost element
		ft_exec_moves(s_a, s_b, cost_a[best_index], cost_b[best_index], comms);
		// printf("stack A is: \n");
		// ft_stcprint(s_a);
		// printf("stack B is: \n");
		// ft_stcprint(s_b);		
		// printf("----\n");
		free(cost_a);
		free(cost_b);
	}
	while (!ft_is_sorted(s_a))
	{
		if (get_min_index(s_a) < (ft_stcsize(s_a) / 2) + 1)
			ft_exec_oper_r(s_a, s_b, "ra", comms);
		else
			ft_exec_oper_rr(s_a, s_b, "rra", comms);
	}
	// ft_stcprint(s_a);
	// printf("comms is now: %s\n", *comms);
}
