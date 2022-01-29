/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcutils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:46:53 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/01/29 20:49:11 by hvan-hov         ###   ########.fr       */
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
	while (tmp->next != NULL)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	if (tmp->num < min)
		min = tmp->num;
	return (min);
}

int	get_el_index(t_stack **s_a, int num)
{
	int		index;
	t_stack	*tmp;

	tmp = *s_a;
	index = 0;
	while (tmp->next != NULL)
	{
		if (tmp->num == num)
			return (index);
		index++;
		tmp = tmp->next;
	}
	if (tmp->num == num)
		return (index);
	return (-1);
}
