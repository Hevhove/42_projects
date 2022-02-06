/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:15:44 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/06 15:41:03 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stcnewnode(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}

void	ft_stcadd_back(t_stack **stc, t_stack *new)
{
	t_stack	*tmp;

	if (stc)
	{
		if (*stc == NULL)
			*stc = new;
		else
		{
			tmp = *stc;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

void	ft_stcadd_front(t_stack **stc, t_stack *new)
{
	if (stc && new)
	{
		new->next = *stc;
		*stc = new;
	}
}

int	ft_stcsize(t_stack **stc)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = *stc;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	ft_stcprint(t_stack **st)
{
	t_stack	*tmp;

	if (!(*st))
		return ;
	tmp = *st;
	printf("-----\n");
	while (tmp != NULL)
	{
		printf("current node %p is: %d\n", tmp, (tmp)->num);
		tmp = (tmp)->next;
	}
	printf("-----\n");
}
