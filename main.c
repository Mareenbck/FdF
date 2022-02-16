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
  int space = 20;
  //space pour tracer trait
  int y2 = y1;
  int x2 = x1;
	int	dx = x2 - x1;
	int	dy = y2 - y1;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	// int e = x2 - x1;
	// e = dy / dx;
  if (dx >= dy)
  // == 0 car horizontal
	{
    x2 = x1 + space;
    printf("x1 = %d\n", x1);
    printf("x2 = %d\n", x2);
    while (x1 <= x2)
		{
      mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x1, y1, 0xFF3395);
      //PAS UTILE POUR LIGNE HORIZONTALESssss
      // e -= dy;
			// if (e < 0)
			// {
			// 	y1++;
			// 	e += dx;
			// }
			x1++;
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
	int	x = 0;
	int y = 0;

	(void)mlx;
  int space = 20;
  int nb_col = data->col;
  int nb_line = data->line;
  while (y < (nb_line * space))
	{
    x = 0;
		while (x < (nb_col * space))
		{
      // if (data->tab[x + 1])
				ft_line((x),(y), mlx);
			x+= space;
    }
		y+= space;
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
