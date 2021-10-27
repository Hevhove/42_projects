/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:50:42 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/27 21:51:14 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static size_t	word_c(const char *str, char c)
{
	size_t count;

	count = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			while (*str != c && *str != '\0')
			{
				str++;
			}
			count++;
		}
		str++;
	}
	return (count);
}

char **ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	len;

	if ((split = (char **)malloc((word_c(s, c) + 1) * sizeof(char *))) == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			// write word function

			len = 0;
			while (s[len] != c && s[len] != '\0')
				len++;
			if ((split[i] = (char *)malloc((len + 1) * sizeof(char))) == NULL)
				return (NULL);
			j = 0;
			while (j < len)
			{
				split[i][j] = s[j];
				j++;
			}
			split[i][j] = '\0';
			s += len;
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}

int main(void)
{
	char	str1[] = "___hello_there__dude___";
	char	str2[] = "**Hello*there**friend**!!!";
	char	str3[] = "thisisatest";
	char	str4[] = "";
	char	c1 = '_';
	char	c2 = '*';

	printf("TESTING...\n");
	/*
	for (int i = 0; i < 4; i++)
		printf("splitted[%d] is: %s\n", i, ft_split(str1, c1)[i]);
	printf("---\n");
	*/
	for (int i = 0; i < 4; i++)
		printf("splitted[%d] is: %s\n", i, ft_split(str2, c2)[i]);
	printf("---\n");
	/*
	for (int i = 0; i < 3; i++)
		printf("splitted[%d] is: %s\n", i, ft_split(str3, c1)[i]);
	printf("---\n");
	for (int i = 0; i < 3; i++)
		printf("splitted[%d] is: %s\n", i, ft_split(str4, c1)[i]);
	printf("---\n");
	*/
}
