/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:19:10 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/13 18:21:39 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
