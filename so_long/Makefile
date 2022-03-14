SRCS =	src/main.c		\
		src/shapes.c	\
		src/colors.c	\
		src/events.c	\
		src/hooks.c		\
		src/loops.c

NAME	= so_long
INCS	= inc/so_long.h
OBJS	= $(SRCS:c=o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
LIBFT	= libft/libft.a
LIBFT_DIR = libft

.PHONY: all clean fclean re debug

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -Imlx -I$(INCS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) --silent

clean:
	$(RM) $(OBJS)
	make -s clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make -s fclean -C $(LIBFT_DIR)

re:	fclean all
