/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:53:17 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/21 18:44:47 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **send, t_stack **receiv)
{
	// TOP element from sender must go to become
	// the TOP element in receiver.
	t_stack *new_head;
	t_stack *sent_head;

	new_head = (*send)->next;
	sent_head = *send;

	(*send) = new_head;
	ft_stcadd_front(receiv, sent_head);
}
