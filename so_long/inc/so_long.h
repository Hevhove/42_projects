/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:02:54 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/03/14 18:43:35 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int 	endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_map {
	size_t	height;
	size_t	width;
	size_t	e_count;
	size_t	c_count;
	size_t	p_count;
} t_map;

int	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_square(t_data *img, int posx, int posy, int length, int color);
void	draw_circle(t_data *img, int posc, int r, int color);
int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char get_r(int trgb);
unsigned char get_g(int trgb);
unsigned char get_b(int trgb);
int	add_shade(double distance, int color);
int get_opposite(int color);
int win_close(int keycode, t_vars *vars);
int	key_hook(int keycode, t_vars *vars);
int	mouse_hook(int mousecode, t_vars *vars);

#endif
