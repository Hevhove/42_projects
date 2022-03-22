/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:02:54 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/21 18:45:15 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ASSET_SIZE 64
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf.h"

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_map {
	size_t	height;
	size_t	width;
	size_t	e_count;
	size_t	c_count;
	size_t	p_count;
	size_t	c_coll;
	int		fd;
	char	**content;
	int		steps;
	int		p_x;
	int		p_y;
	int		player_exit;
}	t_map;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map_path;
	t_map	map;
	int		win_width;
	int		win_height;
	t_img	empt;
	t_img	wall;
	t_img	coll;
	t_img	exit;
	t_img	play;
}	t_data;

int		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	check_top_bot(char *line);
void	line_check(char *line, char *prev_line, t_map *map, int line_count);
void	rect_check(int fd, t_map *map, int line_count);
void	map_check(char *path, t_data *data);
void	error_message(const char *m, int error_code, void *ptr1, void *ptr2);
void	win_size(t_data *data);
void	mlx_launch(t_data *data);
void	launch(t_data *data);
void	load_assets(t_data *data);
void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_up(t_data *data);
int		exit_game(t_data *data, int exit_mode);

#endif
