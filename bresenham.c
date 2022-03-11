/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinebascunana <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:20:18 by marinebas         #+#    #+#             */
/*   Updated: 2022/03/11 17:32:11 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_define_step(t_mlx *mlx)
{
	mlx->map.dx = abs(mlx->map.x2 - mlx->map.x1);
	mlx->map.dy = -abs(mlx->map.y2 - mlx->map.y1);
	if (mlx->map.x2 > mlx->map.x1)
		mlx->map.step_x = 1;
	else
		mlx->map.step_x = -1;
	if (mlx->map.y2 > mlx->map.y1)
		mlx->map.step_y = 1;
	else
		mlx->map.step_y = -1;
	mlx->map.e = mlx->map.dy + mlx->map.dx;
}

void	ft_bresenham(t_mlx *mlx)
{
	ft_define_step(mlx);
	while (1)
	{
		mlx->color.color = ft_colors(mlx);
		my_mlx_pixel_put(mlx, mlx->map.x1 + mlx->pad_left_right,
			mlx->map.y1 + mlx->pad_top_bot);
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
