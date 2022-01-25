/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:19:10 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/21 17:03:46 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack **ft_stcinit(t_stack **st)
{
	st = (t_stack **)malloc(sizeof(st));
	if (!st)
		return (NULL);
	return (st);
}

t_stack *ft_stcnew(int num)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->num = num;
	return (new);
}

int ft_stcadd_back(t_stack **stc, int num)
{
	t_stack *new;
	t_stack *temp;

	new = ft_stcnew(num);
	if (stc)
	{
		if (*stc == NULL)
			*stc = new;
		else
		{
			temp = *stc;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
	}
	else
		return (ERROR_CODE);
	return (0);
}

int	ft_check_entries(char **argv)
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

int ft_check_dupls(int argc, char **argv)
{
	int i;
	int j;

	argv++;
	i = 0;
	while (i < argc - 2)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (ft_atoi((argv)[j++]) == ft_atoi((argv)[i]))
				return (1);
		}
		i++;
	}
	return (0);
}
