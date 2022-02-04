# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 15:49:47 by hvan-hov          #+#    #+#              #
#    Updated: 2022/02/04 11:52:48 by hvan-hov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	src/push_swap.c 	\
		src/ft_stcutils.c	\
		src/ft_argcheck.c	\
		src/ft_opers.c		\
		src/ft_exec_opers.c	\
		src/ft_sort3.c		\
		src/ft_sort5.c

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
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 3 1 7 4 5 8 2 6

clean:
	$(RM) $(OBJS)
	make -s clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) -R push_swap.dSYM
	make -s fclean -C $(LIBFT_DIR)

re:	fclean all
