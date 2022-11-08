# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 10:33:15 by hvan-hov          #+#    #+#              #
#    Updated: 2022/11/08 12:51:56 by hvan-hov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS_DIR	= srcs
SRCS 		= $(wildcard $(SRCS_DIR)/*c)

OBJS		= ${SRCS:.c=.o}
OBJS_DIR	= objs

INCS		= includes
LIBS		=

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f
RM_DIR		= rm -rf

.PHONY: all bonus clean fclean re

all:	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -I$(INCS) -c $< -o $(<:.c=.o) 

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(NAME) $(OBJSB)
	ar rc $(NAME) $(OBJSB)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
		$(RM) $(NAME)

re:	fclean all
