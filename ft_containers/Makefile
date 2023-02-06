# VARIABLE DEFINITIONS
NAME			= containers

SRCS_DIR		= srcs
SRCS			:= $(shell find $(SRCS_DIR) -name "*.cpp")

OBJS_DIR		= objs
OBJS			:= $(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

CFLAGS			= -Wall -Wextra -Werror -std=c++98 -fsanitize=address #-g
INCLUDES		= -Iincludes
UNAME			:= $(shell uname)

RM				= rm -rf

# OPERATING SYSTEM CHECK
ifeq ($(UNAME), Darwin)
	CC = c++
else ifeq ($(UNAME), FreeBSD)
	CC = clang++
else
	CC = c++
	CFLAGS += -D LINUX
endif

# RULES
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@printf "[$(C_YELLOW)======LINKING======$(C_END)]\n"
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@printf "[$(C_GREEN)======SUCCESS======$(C_END)] \n"

all: compile_msg $(NAME)

compile_msg:
	@printf "[$(C_YELLOW)=====COMPILING=====$(C_END)]\n"

del_msg:
	@printf "[$(C_RED)======DELETING=====$(C_END)]\n"

clean: del_msg
	$(RM) $(OBJS_DIR)

fclean:	clean
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
