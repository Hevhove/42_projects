/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:18:08 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/26 12:14:02 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	ft_fillstack(char **argv, t_stack **s_a)
{
	while (*argv)
	{
		if (ft_stcadd_back(s_a, (int)ft_atoi(*argv)))
			return (ERROR_CODE);
		argv++;
	}
	return (0);
}

int	push_swap(char **argv, int argc, t_stack **s_a, t_stack **s_b)
{
	int i;

	if (!s_a || !s_b)
		return (ERROR_CODE);
	i = 0;
	if (ft_fillstack(argv, s_a))
		return (ERROR_CODE);
	printf("argc is: %d\n", argc);
	// ft_stcprint(s_a);
	// printf("---\n");
	// ft_swap(s_a);
	// ft_stcprint(s_a);
	// printf("---\n");
	// ft_push(s_a, s_b);
	// ft_stcprint(s_a);
	// printf("---\n");
	// ft_rotate(s_a);
	// ft_stcprint(s_a);
	// printf("---\n");
	// ft_push(s_a, s_b);
	// ft_push(s_a, s_b);
	// ft_stcprint(s_b);
	// printf("---\n");
	// ft_rev_rotate(s_b);
	// ft_stcprint(s_b);

	printf("stack size is now: %d\n",ft_stcsize(s_b));
	// if (find_lis(a, b, argc) == ERROR_CODE)
	// 	return (ERROR_CODE);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack **s_a;
	t_stack **s_b;

	s_a = (t_stack **)malloc(sizeof(s_a));
	s_b = (t_stack **)malloc(sizeof(s_b));
	// s_a = ft_stcinit(s_a);
	// s_b = ft_stcinit(s_b);
	if (argc > 2 && (ft_check_entries(argv + 1)
	|| ft_check_dupls(argc, argv)
	|| push_swap(argv + 1, argc - 1, s_a, s_b) == ERROR_CODE))
	{
		ft_error();
		return (ERROR_CODE);
	}
	return (0);
}
