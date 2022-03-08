/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinebascunana <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:20:18 by marinebas         #+#    #+#             */
/*   Updated: 2022/02/08 12:02:10 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y)
{
	if (x >= 0 && x <= mlx->win_len && y >= 0 && y <= mlx->win_width)
	{
		mlx->img.addr[(y * mlx->img.line_length + x * (mlx->img.bits_per_pixel / 8))] = mlx->color.blue;
		mlx->img.addr[(y * mlx->img.line_length + x * (mlx->img.bits_per_pixel / 8) + 1)] = mlx->color.green;
		mlx->img.addr[(y * mlx->img.line_length + x * (mlx->img.bits_per_pixel / 8) + 2)] = mlx->color.red;
	}	
}


int ft_print_window(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_len, mlx->win_width);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	ft_draw(mlx);
	// rotate(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	return (0);
}

void	ft_create_window(t_mlx *mlx)
{
	printf("aff_window : data->line : %d\n", mlx->data.line);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_len, mlx->win_width, "fdf");
	mlx_key_hook(mlx->win_ptr, deal_key, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_hook, mlx);
	ft_print_window(mlx);
	mlx_loop(mlx->mlx_ptr);
}

void	ft_setup_colors(t_mlx *mlx)
{
	mlx->color.red = 94;
	mlx->color.green = 100;
	mlx->color.blue = 114;
	mlx->color.next_x = 0;
	mlx->color.next_y = 0;
	mlx->color.next_diago = 0;
	mlx->color.before = 0;
}

int main(int ac, char **av)
{
	(void)ac;
	t_mlx mlx;


	ft_read_map(av[1], &mlx.data);
	// if (!map)
	// 	ft_free_tab(map);
	printf("main : data->col : %d\n", mlx.data.col);
	mlx.altitude = 1;
	mlx.x_angle = 0.0;
	ft_window_size(&mlx);
	ft_padding(&mlx);
	ft_space(&mlx);
	ft_create_window(&mlx);
	ft_setup_colors(&mlx);
	// mlx.color.before = 0;
	// ft_colors(&mlx);
	return (0);
}