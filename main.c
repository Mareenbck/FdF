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

void	my_mlx_pixel_put(t_mlx *mlx, t_img *img, int x, int y, t_color *color)
{
	if (x >= 0 && x <= mlx->win_len && y >= 0 && y <= mlx->win_width)
	{
		img->addr[(y * img->line_length + x * (img->bits_per_pixel / 8))] = color->red;
		img->addr[(y * img->line_length + x * (img->bits_per_pixel / 8) + 1)] = color->green;
		img->addr[(y * img->line_length + x * (img->bits_per_pixel / 8) + 2)] = color->blue;
	}	
}


// int ft_expose_hook(t_mlx *mlx, t_data *data)
// {
// 	t_img	img;
	
// 	img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_len, mlx->win_width);
// 	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	ft_draw(data, mlx, &img);
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img_ptr, 0, 0);
// 	mlx_destroy_image(mlx->mlx_ptr, img.img_ptr);
// 	return (0);
// }

void	ft_aff_window(t_mlx *mlx, t_data *data, t_map *map)
{
	t_img	img;

	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_len, mlx->win_width, "fdf");

	img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_len, mlx->win_width);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_draw(data, mlx, &img, map);
	mlx_key_hook(mlx->win_ptr, deal_key, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img_ptr, 0, 0);
	
	mlx_destroy_image(mlx->mlx_ptr, img.img_ptr);

	mlx_loop(mlx->mlx_ptr);
}


int main(int ac, char **av)
{
	(void)ac;
	t_mlx mlx;
	t_data data;
	t_map map;

	ft_read_map(av[1], &data);
	// if (!map)
	// 	ft_free_tab(map);
	printf("data : %d \n", data.tab[2][2]);
	ft_window_size(&data, &mlx);
	ft_padding(&mlx);
	ft_space(&map, &data);
	ft_aff_window(&mlx, &data, &map);
	return (0);
}