/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinebascunana <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:22:53 by marinebas         #+#    #+#             */
/*   Updated: 2022/02/07 14:23:31 by marinebas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx_linux/mlx.h"
# include "./minilibx_macos/mlx.h"
# include <stdio.h>
# include <unistd.h>       
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>


typedef struct  s_data
{
	int **tab;
	int	col;
	int	line;
	int x;
	int y;
	int z;
}   t_data;

typedef struct s_map
{
	int x;
	int	y;
	int x1;
	int y1;
	int x2;
	int y2;
	int z;
	int space;
	int step_x;
	int step_y;
	int dx;
	int dy;
	int e;
	int e2;
	int rx;
	int ry;
	int rz;
}	t_map;

typedef struct	s_img {
	void 	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_color 
{
	int red; 
	int green;
	int blue;
	int color;
	int	z_min;
	int	z_max;
	int	c_max;
	int	c_min;
	int	c_half;
	int	c_third;
	int	c_fourth;
	int	c_start;
	int next;
}	t_color;

typedef struct  s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	int	win_len;
	int	win_width;
	int pad_left_right;
	int pad_top_bot;
	int	altitude;
	double x_angle;
	t_data	data;
	t_img	img;
	t_map 	map;
	t_color	color;
}   t_mlx;


/*****FREE.C*****/
void	ft_free_map(t_mlx *mlx);
int	ft_exit_win(t_mlx *mlx);
void	ft_free_tab(int **tab);

/*****MLX_WINDOW.C*****/
void	ft_create_window(t_mlx *mlx);
int ft_print_window(t_mlx *mlx);

/*****DRAW.C*****/
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y);
void	ft_line(t_mlx *mlx);
void	ft_col(t_mlx *mlx);
void	ft_draw(t_mlx *mlx);

/*****SETUP.C*****/
void	ft_window_size(t_mlx *mlx);
void	ft_padding(t_mlx *mlx);
void	ft_space(t_mlx *mlx);

/*****COLORS.C*****/
void	ft_setup_colors(t_mlx *mlx);
double		ft_lint(double start, double end, double percent);
int	ft_colors(t_mlx *mlx);
void	ft_change_color(int key, t_mlx *mlx);

/*****BRESENHAM.C*****/
void ft_bresenham(t_mlx *mlx);

/*****MAP.C*****/
void    ft_read_map(int fd, t_mlx *mlx);
int **ft_init_tab(t_mlx *mlx);
int ft_fill_tab(char *file, t_mlx *mlx);

/*****EVENT.C*****/
void	ft_altitude(int key, t_mlx *mlx);
void	ft_zoom(int key, t_mlx *mlx);
void	ft_change_color(int key, t_mlx *mlx);
int		deal_key(int key, t_mlx *mlx);
void	ft_set_angle(int key, t_mlx *mlx);
void	ft_move_mouse(int key, t_mlx *mlx);
int mouse_hook(int key, t_mlx *mlx);

void		rotate(t_mlx *mlx);
void	rot_x(t_mlx *mlx, double ang);
void	ft_move(int key, t_mlx *mlx);

#endif
