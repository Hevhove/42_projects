# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 20:02:50 by hvan-hov          #+#    #+#              #
#    Updated: 2022/01/26 12:10:48 by hvan-hov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	src/ft_argcheck.c		\
		src/ft_operations.c 	\
		src/ft_stcutils.c		\
		src/push_swap.c

NAME	= push_swap
INCS	= inc/push_swap.h
OBJS	= $(SRCS:c=o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
LIBFT = libft/libft.a
LIBFT_DIR = libft

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR) --silent
	@gcc -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft

clean:
	@$(RM) $(OBJS) $(OBJSB)
	@make -s clean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make -s fclean -C $(LIBFT_DIR)

re:	fclean all
