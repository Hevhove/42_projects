/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:18:08 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/13 12:01:52 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
#define MAX_INT 2147483647
#define MIN_INT -2147483648

int	arg_check(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][0] != '-')
				return (1);
			if (argv[i][j] == '-' && argv[i][j + 1] == '\0')
				return (1);
			j++;
		}
		if (ft_atoi(argv[i]) > MAX_INT || ft_atoi(argv[i]) < MIN_INT)
			return (1);
		i++;
	}
	return (0);
}

int	fill_stack(int *st, char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		st[i++] = ft_atoi(*argv);
		argv++;
	}
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (st[j++] == st[i])
				return (1);
		}
		i++;
	}
	return (0);
}

void	fill_lis_index(int *lis, int *index, int len, int number)
{
	int	i;

	i = 1;
	while (i < len)
	{
		lis[i] = MAX_INT;
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

void	find_lis(int *lis, int *a, int *b, int len)
{
	int	check[len];
	int	index[len];
	int	lis_len;
	int	tmp;
	int	i;

	check[0] = a[0];
	fill_lis_index(check, index, len, MAX_INT);
	lis_len = -1;
	while (i < len)
	{
		index[i] = search_replace(check, 0, i, a[i]);
		if (lis_len < index[i])
			lis_len = index[i++];
	}
	tmp = lis_len;
	i = len - 1;
	while (i >= 0)
	{
		if (index[i] == tmp)
		{
			lis[tmp] = a[i--];
			--tmp;
		}
	}
}

int	push_swap(char **argv, int argc)
{
	int	sa[argc - 2];
	int	sb[argc - 2];
	int	lis[argc - 2];

	if (fill_stack(sa, argv, argc))
	{
		write(1, "Error: Duplicates\n", 18);
		return (1);
	}
	find_lis(lis, sa, sb, argc);
	/*for (int i = 0; i < 5; i++)
		printf("lis[%d] is: %d\n", i, lis[i]);
	return (0);*/
}

int	main(int argc, char **argv)
{
	if (arg_check(argv + 1) || argc <= 1)
	{
		write(1, "Error: invalid ints\n", 20);
		return (1);
	}
	if (argc == 2)
		return (0);
	push_swap(argv + 1, argc - 1);
	return (0);
}
