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
	// exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void ft_line(t_mlx *mlx)
{
	int	x1 = 0;
	int x2 = 250;
	int	y1 = 0;
	int	y2 = 500;

	int	dx;
	int	dy;
	// float m;
	int	x = x1;
	int	y = y1;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	float e = -0.5 * dx;
	// e = dy / dx;
  printf("%f\n", e);
	while (x <= x2)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xFF5733);
		e += dy * 2;
		if (e >= 0)
		{
			y++;
			e -= dx * 2;
		}
		// y = m * x + y1 + 0.5;
		x++;
	}
}
// int	ft_expose_hook(t_mlx *var)
// {
// 	var->img.img = mlx_new_image(var->mlx, var->win_len, var->win_width);
// 	var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bpp,
// 			&var->img.size_l, &var->img.endian);
// 	ft_draw_col(var);
// 	ft_draw_li(var);
// 	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
// 	mlx_destroy_image(var->mlx, var->img.img);
// 	return (0);


// float slope = (float)(y1 - y0) / (float)(x1 - x0);

// 		for (int x = x0; x <= x1; ++x)
// 		{
// 			float y = slope * (x - x0) + y0;
// 			gfx.setPixel(x, y, Color(255, 255, 255));
// 		}
// 		gfx.render();
// }


void	ft_aff_window(t_mlx *mlx)
{
	t_img	img;

	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 500, 500, "fdf");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, 500, 500);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	// mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 250, 250, 0xFF5733);
	my_mlx_pixel_put(&img, 250, 250, 0x000000FF);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img_ptr, 0, 0);
	ft_line(mlx);
	// mlx_hook(mlx->win_ptr, deal_key, mlx);
	mlx_hook(mlx->win_ptr, 2, 1L<<0, deal_key, mlx);
	mlx_destroy_image(mlx->mlx_ptr, img.img_ptr);

	// mlx_expose_hook(var->win, ft_expose_hook, var);
	mlx_loop(mlx->mlx_ptr);
}


int main(int ac, char **av)
{
	(void)ac;
	// (void)av;
	t_mlx mlx;


	// mlx->mlx_ptr = mlx_init();
	// // //remplacer 500 par le nb de ligne de get next line ?
	// mlx->mlx_ptr = mlx_new_window(mlx->mlx_ptr, 500, 500, "test");
	// // //evenement clavier
	// mlx_key_hook(mlx->win_ptr, deal_key, mlx);
	// mlx_loop(mlx->mlx_ptr);

	// int **matrix;
	// int y = 0;
	// int x = 0;

	// printf("ok\n");


	int **map;
	map = ft_read_map(av[1]);
	if (map)
		ft_free_tab(map);
	ft_aff_window(&mlx);
	return (0);
	// printf("%d \n",matrix[y][x].z);

}
