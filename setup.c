/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:47:08 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/10 10:47:11 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_window_size(t_mlx *mlx)
{
	mlx->win_len = mlx->data.col * 100;
	mlx->win_width = mlx->data.line * 100;
}

void	ft_padding(t_mlx *mlx)
{
	mlx->pad_left_right = mlx->win_len / 2;
	mlx->pad_top_bot = mlx->win_width / 8;
}

void	ft_space(t_mlx *mlx)
{
	if (mlx->data.col <= 20)
		mlx->map.space = 30;
	else if (mlx->data.col <= 50)
		mlx->map.space = 20;
	else if (mlx->data.col <= 100)
		mlx->map.space = 15;
	else if (mlx->data.col <= 200)
		mlx->map.space = 5;
	else
		mlx->map.space = 1;
}

void	ft_colors(t_mlx *mlx)
{
	// t_color color;
	// int i = 0;
	// int j = 0;
	// int k = 0;
	mlx->data.z = mlx->data.tab[mlx->data.y][mlx->data.x];
	// if (mlx->data.tab[mlx->data.y -1])
	// 	i = mlx->data.tab[mlx->data.y - 1][mlx->data.x];
	// if (mlx->data.tab[mlx->data.y][mlx->data.x + 1])
	// 	j = mlx->data.tab[mlx->data.y][mlx->data.x + 1];
	// if ((mlx->data.tab[mlx->data.y + 1]) && (mlx->data.tab[mlx->data.y][mlx->data.x + 1]))
	//  	k = mlx->data.tab[mlx->data.y + 1][mlx->data.x + 1];
	// printf(" i = %d\n", i);
	if (mlx->data.z > 0)
	{
		mlx->color.red = 255;
		mlx->color.green = 153;
		mlx->color.blue = 158;
	}
	else if (mlx->data.z <= 0 && mlx->data.z > -5)
	{
		mlx->color.red = 94;
		mlx->color.green = 100;
		mlx->color.blue = 114;
	}
}