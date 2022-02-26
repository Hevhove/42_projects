# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 11:48:34 by hvan-hov          #+#    #+#              #
#    Updated: 2022/02/26 19:48:48 by hvan-hov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	src/pipex.c 			\
		src/child.c				\
		src/ft_putchar_fd.c		\
		src/ft_putstr_fd.c		\
		src/ft_putendl_fd.c		\
		src/ft_strjoin.c		\
		src/ft_split.c			\
		src/ft_strncmp.c

SRCS_B = 	bonus/pipex_bonus.c 			\
			bonus/child_bonus.c				\
			bonus/ft_strjoin_bonus.c		\
			bonus/ft_split_bonus.c			\
			bonus/ft_strncmp_bonus.c		\
			bonus/get_next_line.c			\
			bonus/get_next_line_utils.c		\
			bonus/heredoc_bonus.c			\
			bonus/pipes_bonus.c
			
NAME	= pipex
INCS	= inc/pipex.h
INCS_B	= inc/pipex_bonus.h
OBJS	= $(SRCS:c=o)
OBJS_B	= $(SRCS_B:c=o)
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

bonus: $(OBJS_B) $(PRINTF)
	$(CC) $(CFLAGS) -I$(INCS_B) -o $(NAME) $(OBJS_B) $(PRINTF)

debug: $(PRINTF)
	$(CC) -g $(CFLAGS) -I$(INCS) $(PRINTF) $(SRCS) -o $(NAME)

b_debug: $(PRINTF)
	$(CC) -g $(CFLAGS) -I$(INCS_B) $(PRINTF) $(SRCS_B) -o $(NAME)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME) infile "cat" "grep 12" "bc" outfile

clean:
	$(RM) $(OBJS) $(OBJS_B)
	make -s clean -C $(PRINTF_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) -R pipex.dSYM
	make -s fclean -C $(PRINTF_DIR)

re:	fclean all
