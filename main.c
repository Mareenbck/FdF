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

//appelee avec numero de touche et void * transmis dans le main
//utiliser un putnbr pour recuperer le numero dela touche et adapter comportement en fonction de la touche
int deal_key(int key, t_mlx *mlx)
{
	if (key == 0x71)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		return (0);
	}
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void ft_line(int x1, int y1, t_mlx *mlx)
{
	// x1 = 0;
	// x2 = 10;
	// y1 = 2;
	// y2 = 2;
	// (void)data;
	printf("x1 = %d", x1);
	// printf("x2 = %d", x2);
	printf("y1 = %d", y1);
	// printf("y2 = %d", y2);
	int y2 = y1;
	int x2 = x1 + 20;
	int	dx = x2 - x1;
	int	dy = y2 - y1;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	int e = x2 - x1;
	// e = dy / dx;
  	// printf("e = %d\n", e);
  	// printf("dx = %d\n", dx);
  	// printf("dy = %d\n", dy);
  	if (dx >= dy)
	{
   		dy *= 2;
		dx *= 2;
		x2 = x1 + 20;
		while (x1 <= x2)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x1, y1, 0xFF5733);
			e -= dy;
			if (e < 0)
			{
				y1 += 20;
				e += dx;
			}
			x1 += 20;
		}
  	}	
	// while (x <= x2)
	// {
	// 	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xFF5733);
	// 	e += dy * 2;
	// 	if (e >= 0)
	// 	{
	// 		y++;
	// 		e -= dx * 2;
	// 	}
	// 	x++;
	// }
}

void	ft_draw(t_data *data, t_mlx *mlx)
{
	// int		y;
	int		x;

	int y = 0;
	// x = 0;
	(void)mlx;
	printf("mlx -> map : %d\n", data->tab[2][2]);
	printf("data->line : %d\n", data->line);
	printf("data->col : %d\n", data->col);
	while (--data->line)
	{
		printf("data->line : %d\n", data->line);
		printf("%d \n", data->tab[2][2]);
	}

	while (data->tab[y])
	{
		printf("y = %d\n", y);
		x = 0;
		while (data->tab[x])
		{
			printf("x = %d\n", x);
			if (data->tab[x + 1])
				ft_line(x, y, mlx);
			x++;
		}
		y++;
	}
}

void	ft_aff_window(t_mlx *mlx, t_data *data)
{
	t_img	img;

	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 500, 500, "fdf");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, 500, 500);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	// mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 250, 250, 0xFF5733);
	my_mlx_pixel_put(&img, 250, 250, 0x000000FF);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img_ptr, 0, 0);
	ft_draw(data, mlx);
	// ft_line(data, mlx);
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
	ft_aff_window(&mlx, &data);
	return (0);
}
