/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:08:53 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/01 15:36:30 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_in_set(s1[end - 1], set))
		end--;
	trim = (char *)malloc((end - start + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	i = 0;
	while (start < end)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}

/*
int	main(void)
{
	char s1[] = "tripouille   xxx";
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
