/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnjoin_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:01:13 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/10 17:25:27 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnjoin(const char *s1, char s2[][BUFFER_SIZE + 1], char c)
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
	(*s2)[k] = '\0';
	return (join);
}
