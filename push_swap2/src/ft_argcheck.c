/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:16:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/03 16:16:24 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_duplicates(char **argv)
{
	int	i;
	int	j;
	
	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_argcheck(char **argv)
{
	int	i;
	int j;
	
	i = 0;
	while (argv[i])
	{
		j = 0;
		if ((argv[i][0] < '0' || argv[i][0] > '9') && argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	if (!ft_check_duplicates(argv))
		return (0);
	return (1);
}
