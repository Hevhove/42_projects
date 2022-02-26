/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:50:42 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/26 16:19:21 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static size_t	word_count(const char *s, char c)
{
	size_t	wc;

	if (!s || *s == '\0')
		return (0);
	else if (c == '\0')
		return (1);
	wc = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != c && *s != '\0')
				s++;
			wc++;
		}
		if (*s != '\0')
			s++;
	}
	return (wc);
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
				return (0);
			write_word(split[wc], s + i, c);
			i += len;
			wc++;
		}
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = word_count(s, c);
	split = (char **)malloc((wc + 1) * sizeof(split));
	if (split == NULL)
		return (NULL);
	if (write_split(split, s, c) == 0)
		return (NULL);
	split[wc] = NULL;
	return (split);
}

/*
int main(void)
{

	char	s1[] = "hello_word_"; 
	//char	s2[] = "**Hello*there**friend**!!!";
	//char	s3[] = "____";
	//char	s4[] = "";
	char	c1 = '_';
	//char	c2 = '*';

	printf("TESTING...\n");
	printf("The string '%s' gives: \n", s1);
	printf("splitted[0] is: %s\n",ft_split(s1, c1)[0]);
	for (int i = 0; i < 4; i++)
		printf("splitted[%d] is: %s\n", i, ft_split(s1, c1)[i]);
	printf("---\n");
	
	printf("The string '%s' gives: \n", s2);
	for (int i = 0; i < 5; i++)
		printf("splitted[%d] is: %s\n", i, ft_split(s2, c2)[i]);
	printf("---\n");
	printf("The string '%s' gives: \n", s3);
	for (int i = 0; i < 2; i++)
		printf("splitted[%d] is: %s\n", i, ft_split(s3, c1)[i]);
	printf("---\n");	
	printf("The string '%s' gives: \n", s4);
	for (int i = 0; i < 2; i++)
		printf("splitted[%d] is: %s\n", i, ft_split(s4, c1)[i]);
	printf("---\n");
}
*/
