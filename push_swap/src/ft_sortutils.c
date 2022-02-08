/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:23:25 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/06 15:24:58 by hvan-hov         ###   ########.fr       */
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
	while (tmp != NULL)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
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
