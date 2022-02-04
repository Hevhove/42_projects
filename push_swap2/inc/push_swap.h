/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:47:29 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/02/03 18:32:28 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# include <stdio.h>
# include "../libft/libft.h"

// SETUP
typedef struct s_stack
{
	int				num;
	struct s_stack 	*next;
} t_stack;

int	ft_check_duplicates(char **argv);
int	ft_argcheck(char **argv);

// STACK FUNCTIONS
void	ft_swap(t_stack **stc);
void	ft_push(t_stack **send, t_stack **receiv);
void	ft_rotate(t_stack **stc);
void	ft_rev_rotate(t_stack **stc);
t_stack	*ft_stcnewnode(int num);
void	ft_stcadd_back(t_stack **stc, t_stack *new);
void	ft_stcadd_front(t_stack **stc, t_stack *new);
int	ft_stcsize(t_stack **stc);
void	ft_stcprint(t_stack **st);
void	ft_exec_oper_s(t_stack **s_a, t_stack **s_b, const char *op, char **comms);
void	ft_exec_oper_p(t_stack **s_a, t_stack **s_b, const char *op, char **comms);
void	ft_exec_oper_r(t_stack **s_a, t_stack **s_b, const char *op, char **comms);
void	ft_exec_oper_rr(t_stack **s_a, t_stack **s_b, const char *op, char **comms);

// SORTING
int	ft_is_sorted(t_stack **stc);
void	ft_sort3(t_stack **s_a, t_stack **s_b, char **comms);
void	ft_sort5(t_stack **s_a, t_stack **s_b, char **comms);

#endif
