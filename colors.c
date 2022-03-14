/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:47:08 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/10 10:47:11 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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




double		ft_lint(double start, double end, double percent)
{
	double color;
  color = 0.0;
  if (start == end)
		return (start);
  color = start * (1.0 - percent) + (end * percent);
	return (color);
}

int	ft_colors(t_mlx *mlx)
{
    double	divisor;
	  double	percent;
    int color_start;
    color_start = 0;
    mlx->data.z = mlx->data.tab[mlx->data.y][mlx->data.x];
    divisor = mlx->color.z_max - mlx->color.z_min;

    // mlx->color.c_min = 0x3A3042;
    // mlx->color.c_min = 0xFFA69E;
    // mlx->color.c_third = 0xAED9E0;
    // mlx->color.c_max = 0xB8F2E6;
    // mlx->color.c_max = 0xFAF3DD;
    // ft_change_color(key, mlx);
  if (mlx->color.next > mlx->data.z)
		percent = (mlx->color.next - mlx->color.z_min) / divisor;
	else if (divisor != 0)
		percent = (mlx->data.z - mlx->color.z_min) / divisor;
	else
		percent = 0.0;


	if (percent == 0.0)
		color_start = mlx->color.c_min;
	// else if (percent < 0.0525)
	// 	color_start = mlx->color.c_half;
	// if (percent < 0.125)
	// 	color_start = mlx->color.c_third;
	// else if (percent < 0.275)
	// 	color_start = mlx->color.c_fourth;
	else if (percent == 1.0)
		color_start = mlx->color.c_max;


  mlx->color.red = (int)ft_lint(((color_start >> 16) & 0xFF), ((mlx->color.c_max >> 16) & 0xFF), percent);
	mlx->color.green = (int)ft_lint(((color_start >> 8) & 0xFF), ((mlx->color.c_max >> 8) & 0xFF), percent);
	mlx->color.blue = (int)ft_lint((color_start & 0xFF), (mlx->color.c_max & 0xFF), percent);
	return (mlx->color.red << 16 | mlx->color.green << 8 | mlx->color.blue);
}

// void	ft_change_color(int key, t_mlx *mlx)
// {
// 	if (key == 114)
// 		mlx->color.red += 20;
// 	else if (key == 103)
// 		mlx->color.green += 20;
// 	else if (key == 98)
// 		mlx->color.blue += 20;
// 	if (mlx->img.img_ptr)
// 		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
// }
