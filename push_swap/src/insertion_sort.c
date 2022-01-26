/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:06:21 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/01/25 16:51:38 by hvan-hov         ###   ########.fr       */
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

void insertion_sort(int *arr, int len)
{
	int i;
	int j;
	int key;

	i = 1;
	while (i < len)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

int main(void)
{
	int arr[10] = {5, 9, 7, 4, 6, 3, 1, 8, 0, 2};

	for(int i = 0; i < 10; i++)
		printf("arr[%d] is now: %d\n", i, arr[i]);
	insertion_sort(arr, 10);
	printf("--------\n");
	for(int i = 0; i < 10; i++)
		printf("arr[%d] is now: %d\n", i, arr[i]);
}
