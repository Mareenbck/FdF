/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinebascunana <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:20:18 by marinebas         #+#    #+#             */
/*   Updated: 2022/02/08 12:02:10 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(t_mlx *mlx)
{
	// rot_x(mlx, mlx->x_angle);
	while (mlx->map.x < ((mlx->data.col - 1) * mlx->map.space))
	{
        // Init des points 2
		mlx->map.x2 = mlx->map.x + mlx->map.space - mlx->map.y;
	    mlx->map.y2 = mlx->map.y + mlx->map.x + mlx->map.space - (mlx->altitude * mlx->data.tab[mlx->data.y][mlx->data.x + 1]);
		mlx->color.next = mlx->data.tab[mlx->data.y][mlx->data.x + 1];
		// mlx->color.before = mlx->data.tab[mlx->data.y][mlx->data.x -1];
		// mlx->map.z = mlx->data.tab[mlx->data.y][mlx->data.x];
		// ft_colors_bis(mlx);
		// mlx->color.color = ft_colors_3(mlx);
		ft_bresenham(mlx);
		mlx->map.x += mlx->map.space + 1;
		mlx->map.x1 = mlx->map.x2;
		mlx->map.y1 = mlx->map.y2;
		mlx->data.x++;
	}
}

void	ft_col(t_mlx *mlx)
{
	while (mlx->map.y < ((mlx->data.line - 1) * mlx->map.space))
	{
		// Init des points 2
		mlx->map.x2 = mlx->map.x - mlx->map.y - mlx->map.space;
	    mlx->map.y2 = mlx->map.x + mlx->map.y + mlx->map.space - (mlx->altitude * mlx->data.tab[mlx->data.y + 1][mlx->data.x]);
		// if (mlx->data.tab[mlx->data.y-1])
		// 	mlx->color.before = mlx->data.tab[mlx->data.y - 1][mlx->data.x];
		mlx->color.next = mlx->data.tab[mlx->data.y + 1][mlx->data.x];
		// mlx->map.z = mlx->data.tab[mlx->data.y][mlx->data.x];
		// ft_colors_bis(mlx);
		// mlx->color.color = ft_colors_3(mlx);
		ft_bresenham(mlx);
		mlx->map.y += mlx->map.space + 1;
		mlx->map.x1 = mlx->map.x2;
		mlx->map.y1 = mlx->map.y2;
		mlx->data.y++;
	}
}

void	ft_draw(t_mlx *mlx)
{
	mlx->map.y = 0;
	mlx->data.y  = 0;
	// printf("ft_draw\n");
  	while (mlx->map.y <= ((mlx->data.line) * mlx->map.space))
  	{
		mlx->map.x = 0;
		mlx->data.x  = 0;
        // Init des points 1
		mlx->map.x1 = mlx->map.x - mlx->map.y;
	    mlx->map.y1 = mlx->map.y + mlx->map.x - (mlx->altitude * mlx->data.tab[mlx->data.y][mlx->data.x]);
		
		ft_line(mlx);
		mlx->data.y++;
		mlx->map.y += mlx->map.space + 1;
		// mlx->color.before = mlx->data.tab[mlx->data.y - 1][mlx->data.x] - mlx->data.tab[mlx->data.y][mlx->data.x];
	}
    mlx->map.x = 0;
	mlx->data.x  = 0;
    while (mlx->map.x <= (mlx->data.col * mlx->map.space))
    {
        mlx->map.y = 0;
		mlx->data.y  = 0;
        // Init des points 1
        mlx->map.x1 = mlx->map.x - mlx->map.y;
	    mlx->map.y1 = mlx->map.y + mlx->map.x - (mlx->altitude * mlx->data.tab[mlx->data.y][mlx->data.x]);
		ft_col(mlx);
		mlx->data.x++;
		mlx->map.x += mlx->map.space + 1;
		// mlx->color.before = mlx->data.tab[mlx->data.y][mlx->data.x - 1] - mlx->data.tab[mlx->data.y][mlx->data.x];
    }
}