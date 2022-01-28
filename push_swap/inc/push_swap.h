/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:42:44 by Hendrik           #+#    #+#             */
/*   Updated: 2022/01/28 11:32:03 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ERROR_CODE -42
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

// SETUP
int	ft_check_entries(char **argv);
int ft_check_dupls(int argc, char **argv);
void ft_print_comms(char **comm_list);


// STACK FUNCTIONS
void ft_swap(t_stack **stc);
void	ft_push(t_stack **send, t_stack **receiv);
void	ft_rotate(t_stack **stc);
void	ft_rev_rotate(t_stack **stc);
t_stack **ft_stcinit(t_stack **st);
int ft_stcadd_back(t_stack **stc, int num);
int	ft_stcsize(t_stack **stc);
void ft_stcadd_front(t_stack **stc, t_stack *node);
void	ft_stcprint(t_stack **st);

// SORTING FUNCTIONS
int	ft_is_sorted(t_stack **stc);
int check_3_case(t_stack **s_a);
int ft_exec_oper(t_stack **s_a, t_stack **s_b, const char *op);
int	ft_is_valid_oper(const char *op);
char **ft_add_com(const char *op, char **comm_list);
void sort_3(t_stack **s_a, t_stack **s_b, char ***comm_list);
int	push_swap(char **argv, t_stack **s_a, t_stack **s_b, char **comm_list);
void	fill_lis_index(int *check, int *index, int *a, int len);
int		search_replace(int *check, int left, int right, int key);
int		*build_lis(int *a, int *index, int lis_len, int len);
int		launch_checker(int *index, int *check, int *a, int len);
int		find_lis(int *a, int *b, int len);

#endif
