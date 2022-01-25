/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:10:10 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/21 19:08:53 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_stack **stc)
{
	t_stack *curr_head;
	t_stack *new_head;

	curr_head = *stc;
	new_head = (*stc)->next;
	curr_head->next = new_head->next;
	new_head->next = curr_head;
	*stc = new_head;
}
