/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:43:37 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/14 16:36:00 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	s(int *a, int len)
{
	int	tmp;

	if (len <= 1)
		return ;
	else
	{
		tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
	}
}

void	r(int *a, int len)
{
	int	tmp;
	int	i;

	if (len <= 1)
		return ;
	else
	{
		i = 0;
		tmp = a[0];
		while (i < len - 1)
		{
			a[i] = a[i + 1];
			i++;
		}
		a[len - 1] = tmp;
	}
}

void	rr(int *a, int len)
{
	int	tmp;
	int	i;

	if (len <= 1)
		return ;
	i = 1;
	tmp = a[len - 1];
	while (i < len)
	{
		a[len - i] = a[len - i - 1];
		i++;
	}
	a[0] = tmp;
}

// function to execute operations
// function to track operations

// 5 2 3 4 1 --> 5 is bottom of the stack

// BOTH STACKS GROWING FROM THE RIGHT?
// The first argument should be at the top of the stack (be careful about the order)
void	p(int *a, int *b, int len_a, int len_b)
{
	int	i;
	int	tmp;

	if (len_a == 0)
		return ;
	i = 0;
	tmp = a[0];
	while (i < len_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	i = 0;
	while (i < len_b)
	{
		b[len_b - i] = b[len_b - i - 1];
		i++;
	}
	b[0] = tmp;
}

/*
// TESTING OF ABOVE
int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {1, 2, 3, 4};

	p(a, b, 5, 4);
	for (int i = 0; i < 4; i++)
	{
		printf("a[%d] is: %d\n", i, a[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		printf("b[%d] is: %d\n", i, b[i]);
	}
}
*/
