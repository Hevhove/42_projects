/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 21:39:46 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/02 16:41:26 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = tmp;
		}
	}
}

/*
int	main(void)
{
	t_list **lst;
	char	str1[] = "Hello!";
	char	str2[] = "There!";
	char	str3[] = "Baby!";

	lst = (t_list **)calloc(1, sizeof(t_list *));
	*lst = ft_lstnew(str1);
	ft_lstadd_back(lst, ft_lstnew(str2));
	ft_lstadd_back(lst, ft_lstnew(str3));

	// Testing contents of linked list
	printf("Content of Node 0: %s\n", (*lst)->content);
	printf("Content of Node 1: %s\n", (*lst)->next->content);
	printf("Content of Node 2: %s\n", (*lst)->next->next->content);
	
	// Clearing list
	ft_lstclear(lst, del);

	// Reprint the contents of the list
	printf("Content of Node 0: %s\n", (*lst)->content);
	printf("Content of Node 1: %s\n", (*lst)->next->content);
	printf("Content of Node 2: %s\n", (*lst)->next->next->content);
	
	free(lst);
}
*/
