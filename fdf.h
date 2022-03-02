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
# include "./minilibx_x11/mlx.h"
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
}	t_map;


typedef struct  s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	int	win_len;
	int	win_width;
}   t_mlx;

typedef struct	s_img {
	void 	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;


int main(int ac, char **av);

/*****MAP.C*****/
t_data   *ft_read_map(char *file, t_data *data);
int	count_words(char const *s, char c);
int   **ft_init_map(int fd, t_data *data);
void   ft_fill_map(t_data **matrix, int y, char *line);
void	**ft_free_tab(int **tab);

void ft_bresenham(t_mlx *mlx, t_map *map, t_img *img);
void	my_mlx_pixel_put(t_mlx *mlx, t_img *img, int x, int y, int color);


/*****DRAW.C*****/
void	li_pt_begin(t_map *map);
void	li_pt_next(t_map *map);
void	ft_draw_one_li(t_mlx *mlx, t_map *map, t_data *data, t_img *img);
void	ft_draw(t_data *data, t_mlx *mlx, t_img *img);

/*****SETUP.C*****/
void	ft_window_size(t_data *data, t_mlx *mlx);

/*****EVENT.C*****/
int deal_key(int key, t_mlx *mlx);


#endif
