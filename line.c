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

void ft_line(t_mlx *mlx, t_map *map, t_img *img)
{
	printf(">>FT_LINE<<\n");
	printf("map->x : %d, map->x1 : %d, map->x2 : %d\n", map->x, map->x1, map->x2);
	printf("map->y : %d, map->y1 : %d, map->y2 : %d\n", map->y, map->y1, map->y2);
	printf("map->z = %d\n", map->z);

	map->dx = (abs(map->x2 - map->x1));
	map->dy = -(abs(map->y2 - map->y1));
	printf("dy : %d, dx : %d\n", map->dy, map->dx);

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
	printf("step_x : %d, step_y : %d, e : %d\n", map->step_x, map->step_y, map->e);

	while (1)
	{
		// printf(">>PIXEL_PUT<<\n");
		// printf("map->x : %d, map->x1 : %d, map->x2 : %d\n", map->x, map->x1, map->x2);
		// printf("map->y : %d, map->y1 : %d, map->y2 : %d\n", map->y, map->y1, map->y2);
		// printf("map->z = %d\n", map->z);
		my_mlx_pixel_put(mlx, img, map->x1, map->y1, 0xFF3395);
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

