SRCS =	$(wildcard src/*c)
NAME	= philo
INCS	= inc/philo.h
OBJS	= $(SRCS:c=o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=thread -g
RM		= rm -f

.PHONY: all clean fclean re debug

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I$(INCS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

debug:
	$(CC) -g $(CFLAGS) -I$(INCS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) -R $(NAME).dSYM

re:	fclean all

