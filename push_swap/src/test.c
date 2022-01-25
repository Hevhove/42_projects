/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:22:13 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/20 17:42:40 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
#include "../libft/libft.h"

/*
	We need a bunch of functions for a circular linked list
	- ft_stcnew(int num)
*/

t_stack	*ft_stcnew(int num)
{
	t_stack	*out;

	out = (t_stack *)malloc(sizeof(t_stack));
	if (!out)
		return (NULL);
	out->num = num;
	out->next = NULL;
	return (out);
}

int ft_stcadd_back(t_stack **stc, int num)
{
	t_stack *new;
	t_stack *temp;

	// creates a new node
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (ERROR_CODE);
	new->num = num;
	new->next = NULL;
	if (stc)
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
/*
void ft_stcadd_back(t_stack **stc, t_stack *new)
{
	t_stack *temp;

	if (stc)
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
}
*/
int main(int argc, char **argv)
{
	t_stack **s_a; // pointer to the head of the linked list
	t_stack new;

	argv++;
	printf("address of head is: %p\n", s_a);
	s_a = (t_stack **)malloc(sizeof(s_a));
	printf("address of head is: %p\n", s_a);
	if (!s_a)
		return (-42);
	while (*argv)
	{
		if (ft_stcadd_back(s_a, (int)ft_atoi(*argv)) == ERROR_CODE)
		{
			write(1, "fail\n", 5);
			return (1);
		}
		argv++;
	}

	while ((*s_a)->next != NULL)
	{
		printf("current node %p is: %d\n", *s_a, (*s_a)->num);
		*s_a = (*s_a)->next;
	}
	printf("current node %p is: %d\n", *s_a, (*s_a)->num);
	printf("address of head is: %p\n", s_a);
}
