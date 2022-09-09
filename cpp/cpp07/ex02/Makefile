# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 17:31:17 by hvan-hov          #+#    #+#              #
#    Updated: 2022/09/09 12:32:36 by hvan-hov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLE DEFINITIONS
NAME	= array
SRC		= $(wildcard src/*.cpp)
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address
INC		= -I inc
OBJS_D	= obj
OBJ		= $(SRC:src/%.cpp=$(OBJS_D)/%.o)
UNAME	:= $(shell uname)
RM		= rm -rf

# OPERATING SYSTEM CHECK
ifeq ($(UNAME), Darwin)
	CC = clang++
else ifeq ($(UNAME), FreeBSD)
	CC = clang++
else
	CC = c++
	CFLAGS += -D LINUX
endif

# RULES
$(OBJS_D)/%.o:src/%.cpp
	@mkdir -p $(OBJS_D)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "[$(C_GREEN)======SUCCESS======$(C_END)] \n"

all:	msg $(NAME)

msg:
	@printf "[$(C_YELLOW)=====COMPILING=====$(C_END)]\n"

clean:
	@printf "[$(C_RED)===DELETING OBJS===$(C_END)]\n"
	$(RM) $(OBJS_D)

fclean:	clean
	@printf "[$(C_RED)===DELETING EXECS==$(C_END)]\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all test re

# COLOR CODES
C_BLACK		= \033[0;30m
C_RED		= \033[0;31m
C_GREEN		= \033[0;32m
C_YELLOW	= \033[0;33m
C_BLUE		= \033[0;34m
C_WHITE		= \033[0;37m
C_END		= \033[0m
