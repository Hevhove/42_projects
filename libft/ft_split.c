/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:50:42 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/28 15:20:27 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	free_mem(char **split, int len)
{
	while (len--)
		free(split[len]);
	return (-1);
}

static size_t	word_count(const char *str, char c)
{
	size_t	count;

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

static void	write_word(char *dst, const char *src, char c)
{
	size_t	i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static int	write_split(char **split, const char *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] != c && s[i + len] != '\0')
				len++;
			split[wc] = (char *)malloc((len + 1) * sizeof(char));
			if (split[wc] == NULL)
				return (free_mem(split, wc - 1));
			write_word(split[wc], s + i, c);
			i += len;
			wc++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	wc;

	wc = word_count(s, c);
	split = (char **)malloc((wc + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	if (write_split(split, s, c) == -1)
		return (NULL);
	split[wc] = NULL;
	return (split);
}

/*
int main(void)
{
	char	str1[] = "___hello_there__dude___";
	char	str2[] = "**Hello*there**friend**!!!";
	char	str3[] = "____";
	char	str4[] = "";
	char	c1 = '_';
	char	c2 = '*';

	printf("TESTING...\n");
	printf("The string '%s' gives: \n", str1);
	for (int i = 0; i < 4; i++)
		printf("splitted[%d] is: %s\n", i, ft_split(str1, c1)[i]);
	printf("---\n");
	printf("The string '%s' gives: \n", str2);
	for (int i = 0; i < 5; i++)
		printf("splitted[%d] is: %s\n", i, ft_split(str2, c2)[i]);
	printf("---\n");
	printf("The string '%s' gives: \n", str3);
	for (int i = 0; i < 2; i++)
		printf("splitted[%d] is: %s\n", i, ft_split(str3, c1)[i]);
	printf("---\n");	
	printf("The string '%s' gives: \n", str4);
	for (int i = 0; i < 2; i++)
		printf("splitted[%d] is: %s\n", i, ft_split(str4, c1)[i]);
	printf("---\n");
}*/
