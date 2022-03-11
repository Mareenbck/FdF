/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinebascunana <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:20:18 by marinebas         #+#    #+#             */
/*   Updated: 2022/03/11 17:34:23 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_init_point(t_mlx *mlx)
{
	mlx->map.y = 0;
	mlx->data.y = 0;
	mlx->map.x = 0;
	mlx->data.x = 0;
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y)
{
	if (x >= 0 && x <= mlx->win_len && y >= 0 && y <= mlx->win_width)
	{
		mlx->img.addr[(y * mlx->img.line_length
				+ x *(mlx->img.bits_per_pixel / 8))] = mlx->color.blue;
		mlx->img.addr[(y * mlx->img.line_length
				+ x * (mlx->img.bits_per_pixel / 8) + 1)] = mlx->color.green;
		mlx->img.addr[(y * mlx->img.line_length
				+ x * (mlx->img.bits_per_pixel / 8) + 2)] = mlx->color.red;
	}	
}

void	ft_line(t_mlx *mlx)
{
	while (mlx->map.x < ((mlx->data.col - 1) * mlx->map.space))
	{
		mlx->map.x2 = mlx->map.x + mlx->map.space - mlx->map.y;
		mlx->map.y2 = mlx->map.y + mlx->map.x + mlx->map.space
			- (mlx->altitude * mlx->data.tab[mlx->data.y][mlx->data.x + 1]);
		mlx->color.next = mlx->data.tab[mlx->data.y][mlx->data.x + 1];
		ft_bresenham(mlx);
		mlx->map.x += mlx->map.space;
		mlx->map.x1 = mlx->map.x2;
		mlx->map.y1 = mlx->map.y2;
		mlx->data.x++;
	}
}

void	ft_col(t_mlx *mlx)
{
	while (mlx->map.y < ((mlx->data.line - 1) * mlx->map.space))
	{
		mlx->map.x2 = mlx->map.x - mlx->map.y - mlx->map.space;
		mlx->map.y2 = mlx->map.x + mlx->map.y + mlx->map.space
			- (mlx->altitude * mlx->data.tab[mlx->data.y + 1][mlx->data.x]);
		mlx->color.next = mlx->data.tab[mlx->data.y + 1][mlx->data.x];
		ft_bresenham(mlx);
		mlx->map.y += mlx->map.space;
		mlx->map.x1 = mlx->map.x2;
		mlx->map.y1 = mlx->map.y2;
		mlx->data.y++;
	}
}

void	ft_draw(t_mlx *mlx)
{
	ft_init_point(mlx);
	while (mlx->map.y < ((mlx->data.line) * mlx->map.space))
	{
		mlx->map.x = 0;
		mlx->data.x = 0;
		mlx->map.x1 = mlx->map.x - mlx->map.y;
		mlx->map.y1 = mlx->map.y + mlx->map.x
			- (mlx->altitude * mlx->data.tab[mlx->data.y][mlx->data.x]);
		ft_line(mlx);
		mlx->data.y++;
		mlx->map.y += mlx->map.space;
	}
	ft_init_point(mlx);
	while (mlx->map.x < ((mlx->data.col) * mlx->map.space))
	{
		mlx->map.y = 0;
		mlx->data.y = 0;
		mlx->map.x1 = mlx->map.x - mlx->map.y;
		mlx->map.y1 = mlx->map.y + mlx->map.x
			- (mlx->altitude * mlx->data.tab[mlx->data.y][mlx->data.x]);
		ft_col(mlx);
		mlx->data.x++;
		mlx->map.x += mlx->map.space;
	}
}
