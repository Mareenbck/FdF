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
	mlx->win_len = 1920;
	mlx->win_width = 1080;
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
		mlx->map.space = 30;
	else if (mlx->data.col <= 100)
		mlx->map.space = 30;
	else if (mlx->data.col <= 200)
		mlx->map.space = 20;
	else
		mlx->map.space = 15;
}

// void	ft_colors_bis(t_mlx *mlx)
// {
// 	double	divisor;
// 	double	percent;
// 	mlx->color.r_max = 255;
// 	mlx->color.r_min = 174;
// 	mlx->color.g_max = 217;
// 	mlx->color.g_min = 166;
// 	mlx->color.b_max = 224;
// 	mlx->color.b_min = 158;
// 	mlx->data.z = mlx->data.tab[mlx->data.y][mlx->data.x];

// 	divisor = mlx->color.z_max - mlx->color.z_min;
// 	printf("divisor : %f\n", divisor);

// 	if (mlx->color.next > mlx->data.z)
// 		percent = (mlx->color.next - mlx->color.z_min) / divisor;
// 	else if (divisor != 0)
// 		percent = (mlx->data.z - mlx->color.z_min) / divisor;
// 	else
// 		percent = 0.0;
// 	printf("percent : %f\n", percent);
// 	if (percent == 0.0)
// 	{
// 		mlx->color.red = 255;
// 		mlx->color.green = 166;
// 		mlx->color.blue = 158;
// 	}
// 	else
// 	{
// 		mlx->color.red = (int)(mlx->color.r_min * (1.0 - percent) + (mlx->color.r_max * percent));
// 		mlx->color.green = (int)(mlx->color.g_min * (1.0 - percent) + (mlx->color.g_max * percent));
// 		mlx->color.blue = (int)(mlx->color.b_min * (1.0 - percent) + (mlx->color.b_max * percent));
// 	}
// }
