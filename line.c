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

void ft_bresenham(t_mlx *mlx)
{
	// printf("map->y : %d, map->y1 : %d, map->y2 : %d\n", map->y, map->y1, map->y2);
	// printf("map->z = %d\n", map->z);

	mlx->map.dx = abs(mlx->map.x2 - mlx->map.x1);
	mlx->map.dy = -abs(mlx->map.y2 - mlx->map.y1);
	// printf("BRES,");
	// >>> DETERMINER STEP <<<
	if (mlx->map.x2 > mlx->map.x1)
		mlx->map.step_x = 1;
	else
		mlx->map.step_x = -1;
	if (mlx->map.y2 > mlx->map.y1)
		mlx->map.step_y = 1;
	else
		mlx->map.step_y = -1;
	mlx->map.e = mlx->map.dy + mlx->map.dx;
	while (1)
	{
		// ft_colors_bis(mlx);
		mlx->color.color = ft_colors_3(mlx);
		my_mlx_pixel_put(mlx, mlx->map.x1 + mlx->pad_left_right, mlx->map.y1 + mlx->pad_top_bot, mlx->color.color);
		if ((mlx->map.x1 == mlx->map.x2 && mlx->map.y1 == mlx->map.y2))
			break ;
		mlx->map.e2 = mlx->map.e * 2;
		if (mlx->map.e2 >= mlx->map.dy)
		{
			if (mlx->map.x1 == mlx->map.x2) 
				break ;
			mlx->map.e += mlx->map.dy;
			mlx->map.x1 += mlx->map.step_x;
		}
		if (mlx->map.e2 <= mlx->map.dx)
		{
			if (mlx->map.y1 == mlx->map.y2) 
				break ;
			mlx->map.e += mlx->map.dx;
			mlx->map.y1 += mlx->map.step_y;
		}
	}
}

