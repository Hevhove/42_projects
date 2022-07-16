/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:20:47 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/01 19:18:29 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int i)
{
	size_t	len;

	len = 0;
	while (i > 9 || i < -9)
	{
		i /= 10;
		len++;
	}
	return (len + 1);
}

static char	*itoa_write(char *dst, int n, int len, int offset)
{
	while (n > 9)
	{
		dst[len + offset - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	dst[len + offset - 1] = n + '0';
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		offset;

	len = int_len(n);
	offset = 0;
	if (n < 0)
		offset = 1;
	result = (char *)malloc((len + offset + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n == -2147483648)
	{
		result[1] = '2';
		n = -147483648;
	}
	if (n < 0)
	{
		result[0] = '-';
		n = n * -1;
	}
	result = itoa_write(result, n, len, offset);
	result[len + offset] = '\0';
	return (result);
}
/*
int	main(void)
{

	int	i = 0;
	int j = -1234;
	int k = -42;
	int l = 2147483647;
	int m = -2147483648;

	for (int z = 0; z < 5; z++)
		printf("The result for %d is: %c\n", i, ft_itoa(i)[z]);
	printf("The result of %d in itoa is: %s\n",i ,ft_itoa(i));
	printf("The result of %d in itoa is: %s\n",j ,ft_itoa(j));
	printf("The result of %d in itoa is: %s\n",k ,ft_itoa(k));
	printf("The result of %d in itoa is: %s\n",l ,ft_itoa(l));
	printf("The result of %d in itoa is: %s\n",m ,ft_itoa(m));
}
*/
