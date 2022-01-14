/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:18:08 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/13 22:23:42 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **argv, int argc)
{
	int	*a;
	int	*b;

	a = (int *)malloc(argc * sizeof(int));
	b = (int *)malloc(argc * sizeof(int));
	if (!a || !b)
		return (ERROR_CODE);
	if (fill_stack(a, argv, argc))
	{
		write(1, "Error: Duplicates\n", 18);
		return (1);
	}
	if (find_lis(a, b, argc) == ERROR_CODE)
		return (ERROR_CODE);
	return (0);
}

int	main(int argc, char **argv)
{
	if (arg_check(argv + 1) || argc <= 1)
	{
		write(1, "Error: invalid ints\n", 20);
		return (ERROR_CODE);
	}
	if (argc == 2)
		return (0);
	if (push_swap(argv + 1, argc - 1) == ERROR_CODE)
		return (ERROR_CODE);
	return (0);
}
