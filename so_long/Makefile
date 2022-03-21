SRCS =	$(wildcard src/*c)
NAME	= so_long
INCS	= inc/so_long.h
OBJS	= $(SRCS:c=o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address
RM		= rm -f
LIBFT	= libft/libft.a
LIBFT_DIR = libft

.PHONY: all clean fclean re debug

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -Imlx -I$(INCS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) --silent

debug: $(LIBFT)
	$(CC) -g $(CFLAGS) -I$(INCS) -Imlx $(LIBFT) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

valgrind:
	valgrind  --show-leak-kinds=all --leak-check=full  --track-origins=yes --track-fds=yes ./$(NAME) maps/map1.ber

clean:
	$(RM) $(OBJS)
	make -s clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make -s fclean -C $(LIBFT_DIR)

re:	fclean all
