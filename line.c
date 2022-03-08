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
		// ft_colors(mlx);
		// printf("R:%d G:%d B:%d\n", mlx->color.red, mlx->color.green, mlx->color.blue);
	// printf("BRES : mlx->map.x : %d, mlx->map.x1 : %d, mlx->map.x2 : %d\n", mlx->map.x, mlx->map.x1, mlx->map.x2);
	// printf("BRES : mlx->map.y : %d, mlx->map.y1 : %d, mlx->map.y2 : %d\n", mlx->map.y, mlx->map.y1, mlx->map.y2);
		my_mlx_pixel_put(mlx, mlx->map.x1 + mlx->pad_left_right, mlx->map.y1 + mlx->pad_top_bot);
		// printf("passe pixel put");
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

