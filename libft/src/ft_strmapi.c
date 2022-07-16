/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:59:25 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/01 15:43:22 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
char test_func(unsigned int i, char c) // increases every element by its index
{
	return (c + i);
}

int	main(void)
{
	char	str1[] = "abc";
	char	(*f)(unsigned int, char) = &test_func;

	printf("Mapped str1 is: %s", ft_strmapi(str1, (f)));
}
*/
