/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:00:17 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/01/25 15:32:34 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *x, int *y)
{
	int tmp;
	
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void bubble_sort(int *arr, int len)
{
	int i;
	int j;
	int swapcount;

	i = 0;
	while (i < len)
	{
		j = 0;
		swapcount = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapcount++;
			}
			j++;
		}
		if (swapcount == 0)
			return ;
		i++;
	}
}

int main(void)
{
	int arr[10] = {5, 9, 7, 4, 6, 3, 1, 8, 0, 2};

	for(int i = 0; i < 10; i++)
		printf("arr[%d] is now: %d\n", i, arr[i]);
	bubble_sort(arr, 10);
	printf("--------\n");
	for(int i = 0; i < 10; i++)
		printf("arr[%d] is now: %d\n", i, arr[i]);
}
