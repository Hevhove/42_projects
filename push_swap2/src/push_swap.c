/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:51:56 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/08 12:40:30 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_fillstack(t_stack **s_a, char **argv)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > MAX_INT || ft_atol(argv[i]) < MIN_INT)
			return (0);
		new = ft_stcnewnode(ft_atoi(argv[i]));
		if (!new)
			return (0);
		ft_stcadd_back(s_a, new);
		i++;
	}
	return (1);
}

void	free_all(t_stack **s_a, t_stack **s_b, char *comms)
{
	t_stack	*tmp;

	while (*s_a != NULL)
	{
		tmp = *s_a;
		(*s_a) = (*s_a)->next;
		free(tmp);
	}
	while (*s_b != NULL)
	{
		tmp = *s_b;
		(*s_b) = (*s_b)->next;
		free(tmp);
	}
	free(s_a);
	free(s_b);
	free(comms);
}

int	push_swap(t_stack **s_a, t_stack **s_b, char **comms)
{
	int	len;

	if (ft_is_sorted(s_a))
		return (0);
	len = ft_stcsize(s_a);
	if (len <= 3)
		ft_sort3(s_a, s_b, comms);
	else
		ft_sortmore(s_a, s_b, comms);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**s_a;
	t_stack	**s_b;
	char	*comms;

	if (argc > 1)
	{
		s_a = (t_stack **)malloc((1) * sizeof(t_stack **));
		s_b = (t_stack **)malloc((1) * sizeof(t_stack **));
		if (!s_a || !s_b)
			return (1);
		*s_a = NULL;
		*s_b = NULL;
		comms = ft_strdup("");
		if (!ft_argcheck(argv + 1) || !ft_fillstack(s_a, argv + 1))
		{
			ft_putendl_fd("Error", 1);
			free_all(s_a, s_b, comms);
			return (1);
		}
		push_swap(s_a, s_b, &comms);
		ft_putstr_fd(comms, 1);
		free_all(s_a, s_b, comms);
	}
	return (0);
}
