/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:18:08 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/28 12:05:15 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

char **ft_add_com(const char *op, char **comm_list)
{
	int last_index;
	char *str;
	char **new_comm_list;
	
	last_index = 0;
	while (comm_list[last_index] != NULL)
		last_index++;
	new_comm_list = (char **)realloc(comm_list, (last_index + 2) * sizeof(char *));
	if (!new_comm_list)
		return (NULL);
	str = ft_strdup(op);
	if (!str)
		return (NULL);
	new_comm_list[last_index++] = str;
	new_comm_list[last_index] = NULL;

	return (new_comm_list);
}

void ft_print_comms(char **comm_list)
{
	int	i;

	i = 0;
	while (comm_list[i])
	{
		ft_putendl_fd(comm_list[i], 1);
		i++;
	}
}

int	push_swap(char **argv, t_stack **s_a, t_stack **s_b, char **comm_list)
{
	int i;
	int len;
	
	i = 0;
	if (ft_fillstack(argv, s_a))
		return (ERROR_CODE);
	len = ft_stcsize(s_a);
	if (len == 3)
	{
		sort_3(s_a, s_b, &comm_list);
	}
	ft_print_comms(comm_list);
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
	char	**comm_list;
	
	s_a = (t_stack **)malloc(sizeof(s_a));
	s_b = (t_stack **)malloc(sizeof(s_b));
	comm_list = (char **)malloc(sizeof(comm_list));
	if (!s_a || !s_b || !comm_list)
		ft_error();
	// s_a = ft_stcinit(s_a);
	// s_b = ft_stcinit(s_b);
	if (argc > 2 && (ft_check_entries(argv + 1)
	|| ft_check_dupls(argc, argv)
	|| push_swap(argv + 1, s_a, s_b, comm_list) == ERROR_CODE))
	{
		ft_error();
		return (ERROR_CODE);
	}
	return (0);
}
