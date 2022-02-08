# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 15:49:47 by hvan-hov          #+#    #+#              #
#    Updated: 2022/02/06 15:27:57 by hvan-hov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	src/push_swap.c 	\
		src/ft_stcutils.c	\
		src/ft_argcheck.c	\
		src/ft_opers.c		\
		src/ft_exec_opers.c	\
		src/ft_sortutils.c	\
		src/ft_costs.c		\
		src/ft_sort3.c		\
		src/ft_sortmore.c

NAME	= push_swap
INCS	= inc/push_swap.h
OBJS	= $(SRCS:c=o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address
RM		= rm -f
LIBFT = libft/libft.a
LIBFT_DIR = libft

.PHONY: all clean fclean re debug

all: $(NAME)

.c.o: 
	$(CC) $(CFLAGS) -I$(INCS) -c $< -o ${<:.c=.o}
	 
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR) --silent

debug: $(LIBFT)
	$(CC) -g $(CFLAGS) -I$(INCS) $(LIBFT) $(SRCS) -o $(NAME)

valgrind: 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 25 36 52 85 79 654 254 -125 4521 -5425

clean:
	$(RM) $(OBJS)
	make -s clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) -R push_swap.dSYM
	make -s fclean -C $(LIBFT_DIR)

re:	fclean all
