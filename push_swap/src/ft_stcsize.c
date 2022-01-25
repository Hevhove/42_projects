/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:34:42 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/21 16:47:55 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stcsize(t_stack **stc)
{
	int size;

	size = 0;
	if (*stc)
	{
		while((*stc)->next != NULL)
		{
			size++;
			*stc = (*stc)->next;
		}
		size++;
	}
	return (size);
}
