/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:20:52 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/22 16:46:21 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	char			*sub_return;

	if (ft_strlen(s) < start + len)
		return (NULL);
	substr = (char *)malloc(len * sizeof(char));
	sub_return = substr;
	if (!substr)
		return (NULL);
	i = 0;
	while (i < start)
	{
		s++;
		i++;
	}
	while (len--)
	{
		*substr = *s;
		substr++;
		s++;
	}
	return (sub_return);
}

/*
int main(void)
{
	char str1[] = "Hello there";
	char *substr;
	
	substr = ft_substr(str1, 3, 2);
	printf("The substring is: %s\n", substr);
}
*/
