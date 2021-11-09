/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:53:22 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/09 15:38:16 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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
char	*ft_strnjoin(const char *s1, char s2[][7], char c)
{
	int		i;
	int 	j;
	int		k;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(*s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while ((*s2)[j] != '\0')
	{
		if ((*s2)[j] == c)
		{
			join[i] = c;
			i++;
			join[i] = '\0'; // aaxxx
			j++;
			k = 0;
			while ((*s2)[j] != '\0')
			{
				(*s2)[k] = (*s2)[j];
				k++;
				j++;
			}
			(*s2)[k] = '\0';
			break ;
		}
		join[i] = (*s2)[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

/*
char	*ft_strnjoin(char const *s1, char const *s2, char c)
{
	char	*join;
	char	*join_start;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	join_start = join;
	while (*s1)
	{
		*join = *s1;
		join++;
		s1++;
	}
	while (*s2)
	{
		if (*s2 == c)
		{
			*join = c;
			join++;
			*join = '\0';
			s2++;
			break ;
		}
		*join = *s2;
		join++;
		s2++;
	}
	*join = '\0';
	return (join_start);
}
*/
int	main(void)
{
	char *result;
	char strg[] = "xaaxxx";
/*
	strg = malloc(100);
	for (int i = 0; i < 2; i++)
		strg[i] = 'a';
	for (int i = 2; i < 5; i++)
		strg[i] = 'x';
*/
	result = malloc(100);

	printf("The result is now: %s\n", result);
	printf("The strg is now: %s\n", strg);

	result = ft_strnjoin(result, &strg, 'x');

	printf("The result is now: %s\n", result);
	printf("The strg is now: %s\n", strg);
}
