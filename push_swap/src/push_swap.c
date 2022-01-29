/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:18:08 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/29 20:53:49 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_swap(char **argv, t_stack **s_a, t_stack **s_b, char **comm_list)
{
	int	i;
	int	len;

	i = 0;
	if (ft_fillstack(argv, s_a))
		return (ERROR_CODE);
	if (ft_is_sorted(s_a))
		return (0);
	len = ft_stcsize(s_a);
	// ft_stcprint(s_a);
	if (len <= 3)
		sort_3(s_a, s_b, &comm_list);
	else if (len <= 5)
		sort_5(s_a, s_b, &comm_list);
	// NOW FOR THE BIG FINALE : SORT THE BIG LIST --> TO FIGURE OUR SUNDAY / MONDAY
	
	// ft_stcprint(s_a);
	// ft_stcprint(s_b);
	// printf("-----");
	ft_print_comms(comm_list);
	// else
	// 	sort_more(s_a, s_b, &comm_list);
	// ft_print_comms(comm_list);
	// for (int i = 0; i < 3; i++)
	// 	printf("com_list[%d] is: %s\n", i, comm_list[i]);
	// printf("double check\n");
	// ft_print_comms(comm_list);
	//ft_is_sorted(s_a);
	// ft_stcprint(s_a);
	//if (ft_stcsize(s_a) == 3)
	//sort_3(s_a);
	// NOW WE NEED TO  BUILD THE SORTING ALGORITHMS...
	// if (ft_stcsize(s_a) <= 5)
	// 	sort5(s_a, s_b);
	// else
	// 	sort_more(s_a, s_b);
	// ft_stcprint(s_a);
	// printf("---\n");
	// ft_swap(s_a);
	// ft_stcprint(s_a);
	// printf("---\n");
	// ft_push(s_a, s_b);
	// ft_stcprint(s_a);
	// printf("----\n");
	// ft_stcprint(s_b);
	// ft_push(s_b, s_a);
	// printf("----\n");
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
	// printf("stack size is now: %d\n",ft_stcsize(s_b));
	// if (find_lis(a, b, argc) == ERROR_CODE)
	// 	return (ERROR_CODE);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**s_a;
	t_stack	**s_b;
	char	**comm_list;

	s_a = (t_stack **)malloc(sizeof(s_a));
	s_b = (t_stack **)malloc(sizeof(s_b));
	comm_list = (char **)malloc(sizeof(comm_list));
	if (!s_a || !s_b || !comm_list)
		ft_error();
	if (argc > 2 && (ft_check_entries(argv + 1)
			|| ft_check_dupls(argc, argv)
			|| push_swap(argv + 1, s_a, s_b, comm_list) == ERROR_CODE))
	{
		ft_error();
		return (ERROR_CODE);
	}
	return (0);
}
