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

// void	my_pixel_put(t_mlx *var, int x, int y)
// {	
// 	if (x > 0 && x < var->win_len && y > 0 && y < var->win_width)
// 	{
// 		var->img.addr[(y * var->img.size_l) + (x * (var->img.bpp / 8))]
// 			= var->color.red;
// 		var->img.addr[(y * var->img.size_l) + (x * (var->img.bpp / 8)) + 1]
// 			= var->color.green;
// 		var->img.addr[(y * var->img.size_l) + (x * (var->img.bpp / 8)) + 2]
// 			= var->color.blue;
// 	}
// }

void	my_mlx_pixel_put(t_mlx *mlx, t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < mlx->win_len && y > 0 && y < mlx->win_width)
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void ft_line_low(t_map *map, t_img *img)
// {
// 	printf("FT_LINE_LOW\n");
// 	map->e = map->dx / 2;
// 	printf("map->x = %d, map->x2 : %d, map->y : %d\n", map->x, map->x2, map->y);
// 	// my_mlx_pixel_put(img, map->x, map->y, 0xFF3395);

// 	while (map->x <= map->x2)
// 	{
// 		my_mlx_pixel_put(img, map->x, map->y, 0xFF3395);
// 		// map->e = map->dx / 2;
// 		if (map->dy > map->e)
// 		{
// 			// map->y += map->step_y;
// 			map->e += map->dx;
// 		}
// 		// else
// 		// {
// 		// 	map->e += 2 * map->dy;
// 		// }
// 		map->x += map->step_x;
// 		printf("map->x = %d, map->x1 : %d, map->x2 : %d, e : %d\n", map->x, map->x1, map->x2, map->e);
// 	}
// 	printf("ca sort\n");
// }

// void ft_line_high(t_map *map, t_img *img)
// {
// 	printf("FT_LINE_HIGH\n");
// 	map->e = 2 * map->dx - map->dy;
// 	// map->e = -map->dy / 2;
// 	my_mlx_pixel_put(img, map->x, map->y, 0xFF3395);

// 	while (map->y <= map->y2)
// 	{
// 		my_mlx_pixel_put(img, map->x, map->y, 0x4D8C39);
// 		// map->e = map->dx / 2;
// 		if (map->e < 0)
// 		{
// 			map->e += 2 * map->dy;
// 		}
// 		else
// 		{
// 			map->x += map->step_x;
// 			map->e += 2 * (map->dx - map->dy);
// 		}
// 		map->y += map->step_y;
// 		printf("map->y = %d, map->y2 : %d, e : %d\n", map->y, map->y2, map->e);
// 	}
// 	printf("ca sort\n");
// }


void ft_line(t_mlx *mlx, t_map *map, t_img *img)
{
	printf("FT_LINE\n");
	printf("Z = %d\n", map->z);
  	//space pour tracer trait sinon que pixel point
  	printf("x1 = %d, x2 = %d\n", map->x1, map->x2);
  	printf("y1 = %d, y2 = %d\n", map->y1, map->y2);

	map->y2 = map->y1 + map->space;
	map->x2 = map->x1 + map->space;
	map->dx = (abs(map->x2 - map->x1));
	map->dy = (abs(map->y2 - map->y1));
	printf("dy : %d, dx : %d\n", map->dy, map->dx);
	// printf("dx = %d, dy = %d\n", dx, dy);
	if (map->x2 > map->x1)
		map->step_x = 1;
	else
		map->step_x = -1;
	if (map->y2 > map->y1)
		map->step_y = 1;
	else
		map->step_y = -1;
	if (map->dx > map->dy)
		map->e = map->dx / 2;
	else 
		map->e = map->dy / 2;
	printf("step_x : %d, step_y : %d, e : %d\n", map->step_x, map->step_y, map->e);

	// map->e = map->dx - map->dy;
	// if (dx > dy)
	// 	e = dx / 2;
	// else
	// e -= dy / 2;
	// e = x2 - x1;
  	// printf("x = %d, y = %d\n", map->x, map->y);
	while (1)
	{
		my_mlx_pixel_put(mlx, img, map->x, map->y, 0xFF3395);
		if (map->x1 == map->x2 && map->y1 == map->y2)
			break ;
		if (map->dx > -map->e)
		{
			map->e -= map->dy;
			map->x1 += map->step_x;
		}
		if (map->dy > map->e)
		{
			map->e += map->dx;
			map->y1 += map->step_y;
		}
	}
	// if (map->dx == map->dy)
	// {
    // // 	// x2 = x1 + space;
    // // 	// printf("x1 = %d\n", x1);
    // // 	// printf("x2 = %d\n", x2);
    // 	while (map->x <= map->x2)
	// 	{
	// 		my_mlx_pixel_put(img, map->x, map->y, 0xFF5733);
   	//  		//mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x1, y1, 0xFF3395);
    //   		//PAS UTILE POUR LIGNE HORIZONTALES
	// 		map->e -= map->dy;

	// 		// if (e < 0)
	// 		// {
	// 		// 	y1++;
	// 		// 	e += dx;
	// 		// }
	// 		map->x += map->step_x;
	// 	}
	// }
	// else if (map->dx > map->dy)


	// if (map->dx >= map->dy)
	// 	ft_line_low(map, img);
	// else
	// 	ft_line_high(map, img);


	// while (map->x <= map->x2)
	// {
	// 	my_mlx_pixel_put(img, map->x, map->y, 0xFF3395);
	// 	e = dx / 2;
	// 	if (e < 0)
	// 	{
	// 		e -= dy;
	// 	}
	// 	else
	// 	{
	// 		map->y += map->step_y;
	// 		e += dx;
	// 	}
	// 	printf("map->x1 = %d, map->x2 : %d\n", map->x1, map->x2);
	// 	map->x += map->step_x;
	// 	printf("map->x1 = %d, map->x2 : %d, e : %d\n", map->x1, map->x2, e);
	// }
	// printf("ca sort\n");



  	// if (dx > 0 && dy > 0)
	// {
	// 	if (dx >= dy)
	// 	{
	// 		e = dx/2;
	// 		// dy *= z;
	// 		map->x2 = map->x1 + map->space;
	// 		while (map->x1 <= map->x2)
	// 		{
	// 			printf("line 1");
	// 			my_mlx_pixel_put(img, map->x1, map->y1, 0xFF3395);
	// 			// e -= dy;
	// 			if (dy > e)
	// 			{
	// 				map->y1++;
	// 				e += dx;
	// 			}
	// 			map->x1++;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		e = dy/2;
	// 		// dx *= z;
	// 		y2 = y1 + space;
	// 		while (y1 <= y2)
	// 		{
	// 			printf("line 2");

	// 			my_mlx_pixel_put(img, x1, y1, 0x4D8C39);
	// 			// e -= dx;
	// 			if (dx > -e)
	// 			{
	// 				x1++;
	// 				e -= dy;
	// 			}
	// 			y1++;
	// 		}
	// 	}
	// }
	// else if (dx > 0 && dy < 0)
	// {
	// 	if (dx >= -dy)
	// 	{
	// 		e = dx/2;
	// 		// dy *= z;
	// 		x2 = x1 + space;
	// 		while (x1 <= x2)
	// 		{
	// 			printf("line 3");

	// 			my_mlx_pixel_put(img, x1, y1, 0x4D8C39);
	// 			// e += dy;
	// 			if (dy > e)
	// 			{
	// 				y1--;
	// 				e += dx;
	// 			}
	// 			x1++;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		e = dy/2;
	// 		// dx *= z;
	// 		y2 = y1 + space;
	// 		while (y1 <= y2)
	// 		{
	// 			printf("line 4");

	// 			my_mlx_pixel_put(img, x1, y1, 0x4D8C39);
	// 			// e += dx;
	// 			if (dx > -e)
	// 			{
	// 				x1--;
	// 				e += dy;
	// 			}
	// 			y1++;
	// 		}
	// 	}
	// }
	// else if (dx > 0 && dy == 0)
	// {
	// 	x2 = x1 + space;
	// 	while (x1 <= x2)
	// 	{
	// 		printf("line 5");

	// 		my_mlx_pixel_put(img, x1, y1, 0xFF3395);
	// 		x1++;
	// 	}
	// }
	  
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
 	 
}
void	li_pt_begin(t_map *map)
{
	map->x1 = map->x -map->y;
	map->y1 = map->x + map->y;
}

void	li_pt_next(t_map *map)
{
	map->x2 = map->x + map->space - map->y;
	map->y2 = map->y + map->space;
}

void	ft_draw_one_li(t_mlx *mlx, t_map *map, t_data *data, t_img *img)
{
	while (map->x < ((data->col - 1) * map->space))
	{
		li_pt_next(map);
		ft_line(mlx, map, img);
		map->x++;
		map->x += map->space;
		map->x1 = map->x2;
		map->y1 = map->y2;
	}
}


void	ft_draw(t_data *data, t_mlx *mlx, t_img *img)
{
	t_map	map;
	map.x = 0;
  	map.space = 30;
	data->x = 0;

	(void)mlx;

	map.z = data->tab[data->y][data->x];
	map.y = 0;
	data->y = 0;
	// y <= nb_line * space >> pour afficher derniere ligne. Mais segfault
  	while (map.y < (data->line * map.space))
  	{
		map.x = 0;
		data->x  = 0;
		li_pt_begin(&map);
		ft_draw_one_li(mlx, &map, data, img);
		data->y++;
		printf("data.y = %d\n", data->y);
		printf("map.y = %d\n", map.y);
		map.y += map.space;
		printf("map.y = %d\n", map.y);
	}
	// x = 0;
	// y_alt = 0;
	// x_alt = 0;
	// while (x <= nb_col * space)
	// {
	// 	y = 0;
	// 	y_alt = 0;
	// 	while (y < (nb_line * space))
	// 	{
	// 		z = data->tab[y_alt][x_alt];
	// 		ft_col(x, y, mlx, img, z, space);
	// 		y += space;
	// 		y_alt++;
	// 	}
	// 	x += space;
	// 	x_alt++;
	// }

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
