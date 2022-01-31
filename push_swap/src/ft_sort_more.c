/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:18:59 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/01/31 19:58:07 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_min_el_arr(int *arr, int len)
{
	int	i;
	int	min;

	i = 0;
	min = MAX_INT;
	while (i < len)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

int	get_index_arr(int *arr, int len, int num)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == num)
			return (i);
	}
	return (-1); // if number not found
}

void	ft_fill_cost_b(t_cost *cost)
{
	int i;
	
	i = 0;
	while (i < (cost->len_b / 2) + 1)
	{
		cost->cost_b[i] = i;
		i++;
	}
	while (i < cost->len_b)
	{
		cost->cost_b[i] = -1 * (cost->len_b - i);
		i++;
	}
}

int	calc_best_index_dist(int best_index, int len_a)
{
	if (best_index < (len_a / 2) + 1)
		return (best_index);
	else
		return (-1 * len_a - 2);
}

void	ft_fill_cost_a(t_stack **s_a, t_stack **s_b, t_cost *cost)
{
	// 1. iterate over s_b with tmp1
	// inside loop, iterate over s_a with tmp2, find closest bigger element than current tmp->num
	// calculate the cost to rotate this this bigger element to the top
	t_stack *tmp1;
	t_stack *tmp2;
	int		i;
	int		j;
	int		best_index;
	int		diff;
	int		best_index_distance;
	
	tmp1 = *s_b;
	diff = MIN_INT;
	j = 0;
	while (tmp1->next != NULL)
	{
		tmp2 = *s_a;
		i = 0;
		while (tmp2->next != NULL)
		{
			if (tmp1->num - tmp2->num > diff && tmp1->num - tmp2->num < 0)
			{
				diff = tmp1->num - tmp2->num;
				best_index = i;
			}
			i++;
			tmp2 = tmp2->next;
		} // also consider the last element of tmp2 here
		if (tmp1->num - tmp2->num > diff && tmp1->num - tmp2->num < 0)
		{
			diff = tmp1->num - tmp2->num;
			best_index = i;
		}
		best_index_distance = calc_best_index_dist(best_index, ft_stcsize(s_a));
		cost->cost_a[j] = best_index_distance;
		j++;
		tmp1 = tmp1->next;
	}
	best_index_distance = calc_best_index_dist(best_index, ft_stcsize(s_a));
	cost->cost_a[j] = best_index_distance;
}

void	sort_more(t_stack **s_a, t_stack **s_b, char ***comm_list)
{
	t_cost	*cost;
	
	cost = (t_cost *)malloc(1 * sizeof(cost));
	// 1. Optionally push first the numbers below the current mean of s_a
	while (ft_stcsize(s_a) != 3)
		ft_exec_oper_p(s_a, s_b, "pb", comm_list);
	// 2. sort the 3 remaining numbers
	sort_3(s_a, s_b, comm_list);
	// 3. inject into the correct positions
	while (ft_stcsize(s_b) != 0)
	{
		cost->len_a = ft_stcsize(s_b);
		cost->cost_a = (int *)calloc(cost->len_b, sizeof(int));
		cost->len_b = ft_stcsize(s_b);
		cost->cost_b = (int *)calloc(cost->len_b, sizeof(int));
		// ADD PROTECTION
		// if (!(cost->cost_a) || !(cost->cost_b))
		//	return (ERROR_CODE);
		ft_fill_cost_b(cost); // iterate over s_b, calculate the moves required to move particular element to top
		ft_fill_cost_a(s_a, s_b, cost);
		// iterate over s_b, determine which element in s_a is closest to current iteration of s_b and calc moves required to move this el to top
		// for the index with the lowest cost, determine which operations to perform && perform them / optimize for rrr and rr
		// ft_determine_ops(s_a, s_b, cost, comm_list); // how to pass the comm_list?
		for (int i = 0; i < 5; i++)
			printf("cost_a[%d] is now: %d\n", i, cost->cost_a[i]);
		break ;
	}
	// ft_stcprint(s_a);
	// ft_stcprint(s_b);
}
