/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:33:45 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/01/25 16:04:29 by hvan-hov         ###   ########.fr       */
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

void selection_sort(int *arr, int len)
{
	int i;
	int j;
	int min;
	int min_pos;
	
	i = 0;
	while (i < len)
	{
		min = 2147483647;
		j = i;
		while (j < len)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				min_pos = j;
			}
			j++;
		}
		swap(&arr[i], &arr[min_pos]);
		i++;
	}
}

int main(void)
{
	int arr[10] = {5, 9, 7, 4, 6, 3, 1, 8, 0, 2};

	for(int i = 0; i < 10; i++)
		printf("arr[%d] is now: %d\n", i, arr[i]);
	selection_sort(arr, 10);
	printf("--------\n");
	for(int i = 0; i < 10; i++)
		printf("arr[%d] is now: %d\n", i, arr[i]);
}
