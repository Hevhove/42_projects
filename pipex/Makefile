# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 11:48:34 by hvan-hov          #+#    #+#              #
#    Updated: 2022/02/17 11:52:23 by hvan-hov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	src/pipex.c 	\
		src/ft_putchar_fd.c	\
		src/ft_putstr_fd.c	\
		src/ft_putendl_fd.c		\
		src/ft_strncmp.c

NAME	= pipex
INCS	= inc/pipex.h
OBJS	= $(SRCS:c=o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address
RM		= rm -f
PRINTF = printf/libftprintf.a
PRINTF_DIR = PRINTF

.PHONY: all clean fclean re debug

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I$(INCS) -c $< -o ${<:.c=.o}
	 
$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) -I$(INCS) -o $(NAME) $(OBJS) $(PRINTF)

$(PRINTF):
	make -C $(PRINTF_DIR) --silent

debug: $(PRINTF)
	$(CC) -g $(CFLAGS) -I$(INCS) $(PRINTF) $(SRCS) -o $(NAME)

valgrind: 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 25 36 52 85 79 654 254 -125 4521 -5425

clean:
	$(RM) $(OBJS)
	make -s clean -C $(PRINTF_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) -R push_swap.dSYM
	make -s fclean -C $(PRINTF_DIR)

re:	fclean all
