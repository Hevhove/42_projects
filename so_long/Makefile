SRCS =	$(wildcard src/*c)
NAME	= so_long
MLX_DIR = minilibx_mms
MLX_LIB = -lmlx
INCLUDES	= -Iincludes -Ilibft -I$(MLX_DIR)
LIBRARIES = -L$(MLX_DIR) $(MLX_LIB)
OBJS	= $(SRCS:c=o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address
RM		= rm -f
LIBFT	= libft/libft.a
LIBFT_DIR = libft

.PHONY: all clean fclean re debug

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS) $(LIBFT)
	make -C $(MLX_DIR)
	cp $(MLX_DIR)/libmlx.dylib ./
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(LIBRARIES) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) --silent

debug: $(LIBFT)
	$(CC) -g $(CFLAGS) -I$(INCLUDES) -Imlx $(LIBFT) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

valgrind:
	valgrind   --show-leak-kinds=all --leak-check=full --track-origins=yes --track-fds=yes ./$(NAME) maps/map1.ber

clean:
	$(RM) $(OBJS)
	make -s clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) -R $(NAME).dSYM
	make -s fclean -C $(LIBFT_DIR)

re:	fclean all
