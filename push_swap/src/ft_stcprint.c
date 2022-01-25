/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:11:47 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/21 19:06:19 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stcprint(t_stack **st)
{
	t_stack *tmp;

	tmp = *st;
	while ((tmp)->next != NULL)
	{
		printf("current node %p is: %d\n", tmp, (tmp)->num);
		tmp = (tmp)->next;
	}
	printf("current node %p is: %d\n", tmp, (tmp)->num);
}
