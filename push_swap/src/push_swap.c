/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:18:08 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/14 18:02:46 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	push_swap(char **argv, int argc)
{
	int	*a;
	int	*b;

	a = (int *)malloc(argc * sizeof(int));
	b = (int *)malloc(argc * sizeof(int));
	if (!a || !b)
		return (ERROR_CODE);
	if (fill_stack(a, argv, argc))
		return (ERROR_CODE);
	if (find_lis(a, b, argc) == ERROR_CODE)
		return (ERROR_CODE);
	return (0);
}

int	main(int argc, char **argv)
{
	if (arg_check(argv + 1) || argc <= 1)
	{
		ft_error();
		return (ERROR_CODE);
	}
	if (argc == 2)
		return (0);
	if (push_swap(argv + 1, argc - 1) == ERROR_CODE)
	{
		ft_error;
		return (ERROR_CODE);
	}
	return (0);
}
