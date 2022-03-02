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

void	my_mlx_pixel_put(t_mlx *mlx, t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= mlx->win_len && y >= 0 && y <= mlx->win_width)
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_aff_window(t_mlx *mlx, t_data *data)
{
	t_img	img;

	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_len, mlx->win_width, "fdf");
	// mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 500, 500, "fdf");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_len, mlx->win_width);
	// img.img_ptr = mlx_new_image(mlx->mlx_ptr, 500, 500);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	// mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 250, 250, 0xFF5733);
	// my_mlx_pixel_put(&img, 250, 250, 0x000000FF);
	ft_draw(data, mlx, &img);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img_ptr, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 1L<<0, deal_key, mlx);
	mlx_destroy_image(mlx->mlx_ptr, img.img_ptr);

	// mlx_expose_hook(var->win, ft_expose_hook, var);
	mlx_loop(mlx->mlx_ptr);
}


int main(int ac, char **av)
{
	(void)ac;
	t_mlx mlx;
	t_data data;

	ft_read_map(av[1], &data);
	// if (!map)
	// 	ft_free_tab(map);
	printf("data : %d \n", data.tab[2][2]);
	ft_window_size(&data, &mlx);
	ft_aff_window(&mlx, &data);
	return (0);
}