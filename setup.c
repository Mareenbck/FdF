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

// void	ft_colors(t_mlx *mlx)
// {
// // 	printf("ft_colors : next_x : %d, next_y : %d, next_diago : %d\n", mlx->color.next_x, mlx->color.next_y, mlx->color.next_diago);
// // 	printf("ft_colors : data.x : %d, data_y : %d, before : %d\n", mlx->data.x, mlx->data.y, mlx->color.before);
// 	// if (mlx->data.tab[mlx->data.y][mlx->data.x + 1])
// 	mlx->color.next_x = mlx->data.tab[mlx->data.y][mlx->data.x + 1] - mlx->data.tab[mlx->data.y][mlx->data.x];
// 	mlx->color.x_before = mlx->data.tab[mlx->data.y][mlx->data.x - 1] - mlx->data.tab[mlx->data.y][mlx->data.x];
// 	mlx->color.next_x2 = mlx->data.tab[mlx->data.y][mlx->data.x + 2] - mlx->data.tab[mlx->data.y][mlx->data.x];
// 	printf("ft_colors : color next : %d, netx2 : %d, before : %d\n", mlx->color.next_x, mlx->color.next_x2, mlx->color.before);
// 	if (mlx->data.tab[mlx->data.y + 1])
// 		mlx->color.next_y = mlx->data.tab[mlx->data.y + 1][mlx->data.x] - mlx->data.tab[mlx->data.y][mlx->data.x];
// 	if (mlx->data.x + 1 && mlx->data.tab[mlx->data.y + 1])
// 		mlx->color.next_diago = mlx->data.tab[mlx->data.y + 1][mlx->data.x + 1] - mlx->data.tab[mlx->data.y][mlx->data.x];
// 	if (mlx->color.next_x != 0 || mlx->color.next_y != 0 || mlx->color.next_diago != 0 || mlx->color.before != 0 || (mlx->color.next_x2 != 0 && mlx->color.x_before != 0) )
// 	{
// 		mlx->color.red = 255;
// 		mlx->color.green = 153;
// 		mlx->color.blue = 158;
// 	}
// 	else 
// 	{
// 		mlx->color.red = 94;
// 		mlx->color.green = 100;
// 		mlx->color.blue = 114;
// 	}
// }

// void	ft_colors_high(t_mlx *mlx)
// {
// 		mlx->data.z = mlx->data.tab[mlx->data.y][mlx->data.x];
// 		if (mlx->color.next_x > 0 || mlx->data.z > 0)
// 		{
// 			if (mlx->data.z < 6 || mlx->color.next_x > 6 || mlx->color.before > 6)
// 			{
// 				mlx->color.red = 255;
// 				mlx->color.green = 153;
// 				mlx->color.blue = 158;
// 			}
// 			else
// 			{
// 				mlx->color.red = 150;
// 				mlx->color.green = 45;
// 				mlx->color.blue = 120;
// 			}
// 		}
// 		else 
// 		{
// 			mlx->color.red = 94;
// 			mlx->color.green = 100;
// 			mlx->color.blue = 114;
// 		}
// }

void	ft_setup_colors(t_mlx *mlx)
{
	mlx->color.z_min = 0;
	mlx->color.z_max = 0;
	mlx->data.y = 0;
	while (mlx->data.y < mlx->data.line)
	{
		mlx->data.x = 0;
		while (mlx->data.x < mlx->data.col)
		{
			mlx->data.z = mlx->data.tab[mlx->data.y][mlx->data.x];
			if (mlx->data.z < mlx->color.z_min)
				mlx->color.z_min = mlx->data.z;
			if (mlx->data.z > mlx->color.z_max)
				mlx->color.z_max = mlx->data.z;
			mlx->data.x++;
		}
		mlx->data.y++;
	}
}

void	ft_colors_bis(t_mlx *mlx)
{
	double	divisor;
	double	percent;
	mlx->color.r_max = 255;
	mlx->color.r_min = 0;
	mlx->color.g_max = 255;
	mlx->color.g_min = 0;
	mlx->color.b_max = 255;
	mlx->color.b_min = 0;
	mlx->data.z = mlx->data.tab[mlx->data.y][mlx->data.x];

	divisor = mlx->color.z_max - mlx->color.z_min;
	printf("divisor : %f\n", divisor);

	if (mlx->color.next >= mlx->data.z)
		percent = (mlx->color.next - mlx->color.z_min) / divisor;
	else if (divisor != 0)
		percent = (mlx->data.z - mlx->color.z_min) / divisor;
	else
		percent = 0.0;
	printf("percent : %f\n", percent);
	if (percent == 0.0)
	{
		mlx->color.red = 255;
		mlx->color.green = 153;
		mlx->color.blue = 158;
	}
	else
	{
		mlx->color.red = (int)(mlx->color.r_min * (1.0 - percent) + (mlx->color.r_max * percent));
		mlx->color.green = (int)(mlx->color.g_min * (1.0 - percent) + (mlx->color.g_max * percent));
		mlx->color.blue = (int)(mlx->color.b_min * (1.0 - percent) + (mlx->color.b_max * percent));
	}
}