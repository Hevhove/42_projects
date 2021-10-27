/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:08:53 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/25 14:45:21 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *str)
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

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	*get_start_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	*out;
	size_t	len;

	out = (size_t *)malloc(2 * sizeof(size_t));
	if (out == NULL)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (in_set(s1[i], set))
		i++;
	j = 0;
	while (in_set(s1[len - j - 1], set))
		j++;
	out[0] = i;
	out[1] = j;
	return (out);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trimmed;
	char		*trim_return;
	size_t		len;
	size_t		*out;

	len = ft_strlen(s1);
	if (*s1 == '\0' || *set == '\0' || s1 == NULL || set == NULL)
		return ((char *)s1);
	out = get_start_end(s1, set);
	if (len < (out[0] + out[1]))
		return ("");
	trimmed = (char *)malloc((len - out[0] - out[1]) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	trim_return = trimmed;
	while (s1[out[0] + out[1]])
	{
		*trimmed = s1[out[0]];
		trimmed++;
		s1++;
	}
	*trimmed = '\0';
	return (trim_return);
}

/*
int	main(void)
{
	char s1[] = "   xxxtest";
	char s2[] = "testxxx ";
	char s3[] = "   x  x xxxxtexstxx  x ";
	char s4[] = "hello :)";
	char s5[] = "   xxxx   ";
	char s6[] = "";
	char set1[] = " x";
	char set2[] = "";

	printf("TESTING...\n");
	printf("The trimmed string is: %s\n", ft_strtrim(s1, set1));
	printf("The trimmed string is: %s\n", ft_strtrim(s2, set1));
	printf("The trimmed string is: %s\n", ft_strtrim(s3, set1));
	printf("The trimmed string is: %s\n", ft_strtrim(s4, set1));
	printf("The trimmed string is: %s\n", ft_strtrim(s5, set1));
	printf("The trimmed string is: %s\n", ft_strtrim(s6, set1));
	printf("---\n");
	printf("The trimmed string is: %s\n", ft_strtrim(s1, set2));
	printf("The trimmed string is: %s\n", ft_strtrim(s6, set2));
}
*/
