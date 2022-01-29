/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:52:01 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/01/28 17:33:09 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_sorted(t_stack **stc)
{
	t_stack	*tmp;

	tmp = *stc;
	while (tmp->next != NULL)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

char	**ft_add_com(const char *op, char **c_list)
{
	int		last_index;
	char	*str;
	char	**new_comm_list;

	last_index = 0;
	while (c_list[last_index] != NULL)
		last_index++;
	new_comm_list = (char **)realloc(c_list, (last_index + 2) * sizeof(char *));
	if (!new_comm_list)
		return (NULL);
	str = ft_strdup(op);
	if (!str)
		return (NULL);
	new_comm_list[last_index++] = str;
	new_comm_list[last_index] = NULL;
	return (new_comm_list);
}

void	ft_print_comms(char **comm_list)
{
	int	i;

	i = 0;
	while (comm_list[i])
	{
		ft_putendl_fd(comm_list[i], 1);
		i++;
	}
}

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2); // is this allowed to output to error messages?
	return (0);
}
