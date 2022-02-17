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

void ft_line(int x1, int y1, t_mlx *mlx, t_img *img, int z, int space)
{

	printf("Z = %d\n", z);
  	//space pour tracer trait sinon que pixel point
  	int y2 = y1 + space;

  	// printf("y2 = %d\n", y2);

  	int x2 = x1 + space;

  	// printf("x2 = %d\n", x2);

	int	dx;
	int	dy;

(void)mlx;
	dx = abs(x2 - x1) * z;
	dy = abs(y2 - y1) * z;
  	printf("dx = %d\n", dx);
  	printf("dy = %d\n", dy);
	int e = 0;
	// e = x2 - x1;

  	if (dx > 0 && dy > 0)
	{
		if (dx >= dy)
		{
			e = dx/2;
			// dy *= z;
			x2 = x1 + space;
			while (x1 <= x2)
			{
				my_mlx_pixel_put(img, x1, y1, 0xFF3395);
				// e -= dy;
				if (dy > e)
				{
					y1++;
					e += dx;
				}
				x1++;
			}
		}
		else
		{
			e = dy/2;
			// dx *= z;
			y2 = y1 + space;
			while (y1 <= y2)
			{
				my_mlx_pixel_put(img, x1, y1, 0x4D8C39);
				// e -= dx;
				if (dx > -e)
				{
					x1++;
					e -= dy;
				}
				y1++;
			}
		}
	}
	else if (dx > 0 && dy < 0)
	{
		if (dx >= -dy)
		{
			e = dx/2;
			// dy *= z;
			x2 = x1 + space;
			while (x1 <= x2)
			{
				my_mlx_pixel_put(img, x1, y1, 0x4D8C39);
				// e += dy;
				if (dy > e)
				{
					y1--;
					e += dx;
				}
				x1++;
			}
		}
		else
		{
			e = dy/2;
			// dx *= z;
			y2 = y1 + space;
			while (y1 <= y2)
			{
				my_mlx_pixel_put(img, x1, y1, 0x4D8C39);
				// e += dx;
				if (dx > -e)
				{
					x1--;
					e += dy;
				}
				y1++;
			}
		}
	}
	else if (dx > 0 && dy == 0)
	{
		x2 = x1 + space;
		while (x1 <= x2)
		{
			my_mlx_pixel_put(img, x1, y1, 0xFF3395);
			x1++;
		}
	}
	  
  // == 0 car horizontal
	// if (dx >= dy)
	// {
    // 	x2 = x1 + space;
    // 	// printf("x1 = %d\n", x1);
    // 	// printf("x2 = %d\n", x2);
    // 	while (x1 <= x2)
	// 	{
	// 		my_mlx_pixel_put(img, x1, y1, 0xFF3395);
   	//  		//mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x1, y1, 0xFF3395);
    //   		//PAS UTILE POUR LIGNE HORIZONTALES
	// 		e -= dy;
	// 		printf("E = %d\n", e);

	// 		if (e < 0)
	// 		{
	// 			y1++;
	// 			e += dx;
	// 		}
	// 		x1++;
	// 	}
 	//  }
}

void ft_col(int x1, int y1, t_mlx *mlx, t_img *img, int z, int space)
{
  	int y2 = y1 + space;
  	int x2 = x1 + space;
	int	dx;
	int	dy;
	(void)mlx;
	dx = abs(x2 - x1) * z;

	dy = abs(y2 - y1) * z;

	int e = 0;
	// e = y2 - y1;
	printf("dx dans col = %d\n", dx);
	printf("dy dans col = %d\n", dy);
  	if (-dx < 0 && dy > 0)
	{
		if (-dx >= dy)
		{
			e = dx/2;
			// dy *= z;
			x2 = x1 + space;
			while (x1 <= x2)
			{
				my_mlx_pixel_put(img, x1, y1, 0x4D8C39);
				// e += dy;
				if (dy > e)
				{
					y1++;
					e += dx;
				}
				x1++;
			}
		}
		else
		{
			e = dy/2;
			// dx *= z;
			y2 = y1 + space;
			while (y1 <= y2)
			{
				my_mlx_pixel_put(img, x1, y1, 0x568AB0);
				// e += dx;
				if (dx > -e)
				{
					x1--;
					e += dy;
				}
				y1++;
			}
		}
	}
	// CA NE RENTRE JMS ICI >> PKOI
	else if (dx < 0 && dy < 0)
	{
		if (dx <= dy)
		{
			e = dx / 2;
			// dx *= z;
			x2 = x1 + space;
			while (x1 <= x2)
			{
				my_mlx_pixel_put(img, x1, y1, 0x568AB0);
				// e -= dy;
				if (dy > e)
				{
					y1--;
					e += dx;
				}
				x1++;
			}
		}
		else 
		{
			e = dy/2;
			// dx *= z;
			y2 = y1 + space;
			while (y1 <= y2)
			{
				my_mlx_pixel_put(img, x1, y1, 0x568AB0);
				// e -= dx;
				if (dx > -e)
				{
					x1--;
					e += dy;
				}
				y1++;
			}			
		}
	}
	else if (dy == 0)
	{
		y2 = y1 + space;
		while (y1 <= y2)
		{
			my_mlx_pixel_put(img, x1, y1, 0x568AB0);
			y1++;
		}
	}
}





// 	// if (dx >= dy)
// 	// {
//     // 	y2 = y1 + space;
//     // 	// printf("x1 = %d\n", x1);
//     // 	// printf("x2 = %d\n", x2);
//     // 	while (y1 <= y2)
// 	// 	{
//     //   		my_mlx_pixel_put(img, x1, y1, 0x568AB0);
// 	// 		// mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
// 	// 		//   mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x1, y1, 0x568AB0);
// 	// 		e -= dx;
// 	// 		if (e < 0)
// 	// 		{
// 	// 			x1++;
// 	// 			e += dy;
// 	// 		}

// 	// 		y1++;
// 	// 	}
//   	// }
// }

void	ft_draw(t_data *data, t_mlx *mlx, t_img *img)
{
	int	x = 0;
	int y = 0;
	int	x_alt = 0;
	int y_alt = 0;

	(void)mlx;
  	int space = 20;
 	int nb_col = data->col;
  	int nb_line = data->line;
	int z = data->tab[y_alt][x_alt];

	// y <= nb_line * space >> pour afficher derniere ligne. Mais segfault
  	while (y < (nb_line * space))
  	{
		x = 0;
		x_alt = 0;
		while (x < (nb_col * space))
		{
      		// if (data->tab[x + 1])
			z = data->tab[y_alt][x_alt];
			ft_line((x),(y), mlx, img, z, space);
			x+= space;
			x_alt++;
		}
		y+= space;
		y_alt++;
	}
	x = 0;
	y_alt = 0;
	x_alt = 0;
	while (x <= nb_col * space)
	{
		y = 0;
		y_alt = 0;
		while (y < (nb_line * space))
		{
			z = data->tab[y_alt][x_alt];
			ft_col(x, y, mlx, img, z, space);
			y += space;
			y_alt++;
		}
		x += space;
		x_alt++;
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
	ft_aff_window(&mlx, &data);
	return (0);
}
