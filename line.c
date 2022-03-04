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

void ft_bresenham(t_mlx *mlx, t_map *map, t_img *img, t_data *data)
{
	// printf(">>FT_LINE<<\n");
	// printf("BRES : map->x : %d, map->x1 : %d, map->x2 : %d\n", map->x, map->x1, map->x2);
	// printf("map->y : %d, map->y1 : %d, map->y2 : %d\n", map->y, map->y1, map->y2);
	// printf("map->z = %d\n", map->z);
	t_color	color;
	map->dx = abs(map->x2 - map->x1);
	map->dy = -abs(map->y2 - map->y1);

	// >>> DETERMINER STEP <<<
	if (map->x2 > map->x1)
		map->step_x = 1;
	else
		map->step_x = -1;
	if (map->y2 > map->y1)
		map->step_y = 1;
	else
		map->step_y = -1;
	map->e = map->dy + map->dx;
	while (1)
	{
		ft_colors(data, &color);
		my_mlx_pixel_put(mlx, img, map->x1 + mlx->pad_left_right, map->y1 + mlx->pad_top_bot, &color);
		if ((map->x1 == map->x2 && map->y1 == map->y2))
			break ;
		map->e2 = map->e * 2;
		if (map->e2 >= map->dy)
		{
			if (map->x1 == map->x2) 
				break ;
			map->e += map->dy;
			map->x1 += map->step_x;
		}
		if (map->e2 <= map->dx)
		{
			if (map->y1 == map->y2) 
				break ;
			map->e += map->dx;
			map->y1 += map->step_y;
		}
	}
}

