/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 09:24:34 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/21 17:16:44 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	while (dstsize--)
	{
		if (dstsize == 0 || *src == '\0')
		{
			*dst = '\0';
			break ;
		}
		*dst = *src;
		dst++;
		src++;
	}
	return (srclen);
}

/*
int main(void)
{
	char dst1[] = "destination";
	char src1[] = "src";
	char dst2[] = "destination";
	char src2[] = "src";

	// Call function and check return values;
	size_t r_val1 = ft_strlcpy(dst1, src1, 3);
	size_t r_val2 = strlcpy(dst2, src2, 3);

	printf("TESTING...\n");
	printf("OUR RETURN VAL: %zu\n", r_val1);
	printf("OFF RETURN VAL: %zu\n", r_val2);
	printf("----\n");

	// Memory layout check
	printf("OUR MEMORY LAYOUT: \n");
	for (int i = 0; i < 15; i++)
		printf("dst1[%d] is : %c\n", i, dst1[i]);
	printf("----\n");
	printf("OFF MEMORY LAYOUT: \n");
	for (int i = 0; i < 15; i++)
		printf("dst2[%d] is : %c\n", i, dst2[i]);
}
*/
