/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:39:41 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/31 17:22:40 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	if (size < destlen)
		srclen += size;
	else
		srclen += destlen;
	i = 0;
	while (src[i] != '\0' && (destlen + i) < size - 1)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (srclen);
}

/*
int main(void)
{
	char dst1[20] = "destination";
	char src1[] = "src";
	char dst2[20] = "destination";
	char src2[] = "src";

	// Call function and check return values;
	size_t r_val1 = ft_strlcat(dst1, src1, 14);
	size_t r_val2 = strlcat(dst2, src2, 14);

	printf("TESTING...\n");
	printf("OUR RETURN VAL: %zu\n", r_val1);
	printf("OFF RETURN VAL: %zu\n", r_val2);
	printf("----\n");

	// Memory layout check
	printf("OUR MEMORY LAYOUT: \n");
	for (int i = 0; i < 16; i++)
		printf("dst1[%d] is : %c\n", i, dst1[i]);
	printf("----\n");
	printf("OFF MEMORY LAYOUT: \n");
	for (int i = 0; i < 16; i++)
		printf("dst2[%d] is : %c\n", i, dst2[i]);
}
*/
