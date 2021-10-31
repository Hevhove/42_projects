# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 10:33:15 by hvan-hov          #+#    #+#              #
#    Updated: 2021/10/30 18:13:59 by hvan-hov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./ft_atoi.c		\
	./ft_isalnum.c		\
  	./ft_isprint.c		\
	./ft_memcpy.c		\
	./ft_strchr.c		\
	./ft_strlcpy.c		\
	./ft_strnstr.c		\
	./ft_tolower.c		\
	./ft_atoi.c			\
	./ft_isalpha.c		\
	./ft_itoa.c			\
	./ft_memmove.c		\
	./ft_strdup.c		\
	./ft_strlen.c		\
	./ft_strrchr.c		\
	./ft_toupper.c		\
	./ft_bzero.c		\
	./ft_isascii.c		\
	./ft_memchr.c		\
	./ft_memset.c		\
	./ft_strjoin.c		\
	./ft_strmapi.c		\
	./ft_strtrim.c		\
	./ft_calloc.c		\
	./ft_isdigit.c		\
	./ft_memcmp.c		\
	./ft_split.c		\
	./ft_strlcat.c		\
	./ft_strncmp.c		\
	./ft_substr.c

INCS	= ./libft.h
OBJS	= $(SRCS:c=o)
NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.PHONY: all

all:	$(NAME)

#%.c: %.o 
#	$(CC) -I$(INCS) -o $@ -c $? $(CFLAGS)	

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
