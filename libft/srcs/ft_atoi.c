/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:25:36 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/10/31 13:48:45 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	mc;

	result = 0;
	mc = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		mc = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0' && *str <= '9' && *str >= '0')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * mc);
}

/*
int	main(void)
{
	char str1[] = "  1234";
	char str2[] = "-1234";
	char str3[] = "+-125";
	char str4[] = "-123.32";
	char str5[] = "+--+-";
	char str6[] = "+--6788ib889";
	char str7[] = "qwer1234qwer";
	char str8[] = "";
	
	printf("TESTING...\n");
	printf("OUR OUTPUT FOR '%s' is: %d\n", str1, ft_atoi(str1));
	printf("OFF OUTPUT FOR '%s' is: %d\n", str1, atoi(str1));
	printf("----\n");
	
	printf("OUR OUTPUT FOR '%s' is: %d\n", str2, ft_atoi(str2));
	printf("OFF OUTPUT FOR '%s' is: %d\n", str2, atoi(str2));
	printf("----\n");

	printf("OUR OUTPUT FOR '%s' is: %d\n", str3, ft_atoi(str3));
	printf("OFF OUTPUT FOR '%s' is: %d\n", str3, atoi(str3));
	printf("----\n");

	printf("OUR OUTPUT FOR '%s' is: %d\n", str4, ft_atoi(str4));
	printf("OFF OUTPUT FOR '%s' is: %d\n", str4, atoi(str4));
	printf("----\n");

	printf("OUR OUTPUT FOR '%s' is: %d\n", str5, ft_atoi(str5));
	printf("OFF OUTPUT FOR '%s' is: %d\n", str5, atoi(str5));
	printf("----\n");
	
	printf("OUR OUTPUT FOR '%s' is: %d\n", str6, ft_atoi(str6));
	printf("OFF OUTPUT FOR '%s' is: %d\n", str6, atoi(str6));
	printf("----\n");

	printf("OUR OUTPUT FOR '%s' is: %d\n", str7, ft_atoi(str7));
	printf("OFF OUTPUT FOR '%s' is: %d\n", str7, atoi(str7));
	printf("----\n");

	printf("OUR OUTPUT FOR '%s' is: %d\n", str8, ft_atoi(str8));
	printf("OFF OUTPUT FOR '%s' is: %d\n", str8, atoi(str8));
	printf("----\n");
}
*/
