/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:38:17 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/02 19:58:37 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *) b;
	while (len--)
	{
		s[i] = c;
		i++;
	}
	return (b);
}

/*
int main(void)
{
	char str1[] = "Hello there!";
	char c = '.';

	printf("OUR VERS: '%s' becomes '%s'\n", str1, ft_memset(str1, c, 5));
	printf("OFF VERS: '%s' becomes '%s'\n", str1, memset(str1, c, 5));
}
*/
