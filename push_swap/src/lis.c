/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:20:29 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/13 23:53:03 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_lis_index(int *check, int *index, int *a, int len)
{
	int	i;

	i = 1;
	check[0] = a[0];
	while (i < len)
	{
		check[i] = MAX_INT;
		index[i - 1] = 0;
		i++;
	}
	index[i - 1] = 0;
}

int	search_replace(int *check, int left, int right, int key)
{
	int	mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key < check[mid])
			right = mid - 1;
		else if (check[mid] == key)
			return (mid);
		else if (mid + 1 <= right && check[mid + 1] >= key)
		{
			check[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
	}
	if (mid == left)
	{
		check[mid] = key;
		return (mid);
	}
	check[mid + 1] = key;
	return (mid + 1);
}

int	*build_lis(int *a, int *index, int lis_len, int len)
{
	int	i;
	int	tmp;
	int	*lis;

	lis = (int *)malloc(lis_len * sizeof(int));
	if (!lis)
		return (NULL);
	tmp = lis_len;
	i = len - 1;
	while (i >= 0)
	{
		if (index[i] == tmp)
		{
			lis[tmp] = a[i];
			--tmp;
		}
		i--;
	}
	return (lis);
}

int	launch_checker(int *index, int *check, int *a, int len)
{
	int	i;
	int	lis_len;

	i = 0;
	lis_len = -1;
	while (i < len)
	{
		index[i] = search_replace(check, 0, i, a[i]);
		if (lis_len < index[i])
			lis_len = index[i];
		i++;
	}
	return (lis_len);
}

push_lis(a, b, lis)
{
	// GIVEN THE LIS, WE MUST NOW iterate over a,
	// and push into b the numbers which are not part of LIS
	// add the used actions to a list of actions -> function pointers?
	// need a struct to passa round the a, b and len_a, len_b?
	// len_a/b as statics and keep track of their lengths?
	// efficiency of our own code snippets does not matter?
	int i;

	i = 0;
	while ()
}

int	find_lis(int *a, int *b, int len)
{
	int	*lis;
	int	*check;
	int	*index;
	int	lis_len;

	check = (int *)malloc(len * sizeof(int));
	index = (int *)malloc(len * sizeof(int));
	if (!check || !index)
		return (ERROR_CODE);
	fill_lis_index(check, index, a, len);
	lis_len = launch_checker(index, check, a, len);
	lis = build_lis(a, index, lis_len, len);
	if (lis == NULL)
		return (ERROR_CODE);
	push_lis(a, b, lis);
	for (int i = 0; i < lis_len + 1; i++)
		printf("lis[%d] is: %d\n", i, lis[i]);
	free(lis);
	free(check);
	free(index);
	return (lis_len);
}
