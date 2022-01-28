/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:05:27 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/27 16:03:49 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack *ft_stcnew(int num)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->num = num;
	return (new);
}

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

int	ft_stcsize(t_stack **stc)
{
	int size;
	t_stack *tmp;

	tmp = *stc;
	size = 0;
	if (tmp)
	{
		while(tmp->next != NULL)
		{
			size++;
			tmp = tmp->next;
		}
		size++;
	}
	return (size);
}

void ft_stcadd_front(t_stack **stc, t_stack *node)
{
	node->next = (*stc);
	*stc = node;
}

int ft_stcadd_back(t_stack **stc, int num)
{
	t_stack *new;
	t_stack *temp;

	new = ft_stcnew(num);
	if (stc && new)
	{
		if (*stc == NULL)
			*stc = new;
		else
		{
			temp = *stc;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
	}
	else
		return (ERROR_CODE);
	return (0);
}
