/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:42:44 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/13 22:38:18 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ERROR_CODE -42
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str);
int		arg_check(char **argv);
int		fill_stack(int *st, char **argv, int argc);
void	fill_lis_index(int *check, int *index, int *a, int len);
int		search_replace(int *check, int left, int right, int key);
int		*build_lis(int *a, int *index, int lis_len, int len);
int		launch_checker(int *index, int *check, int *a, int len);
int		find_lis(int *a, int *b, int len);
int		push_swap(char **argv, int argc);

#endif
