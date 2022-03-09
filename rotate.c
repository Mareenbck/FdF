/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinebascunana <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:20:18 by marinebas         #+#    #+#             */
/*   Updated: 2022/02/08 12:02:10 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rot_x(t_mlx *mlx, double ang)
{
	int	y;
	int	z;
    ang = ang * 3.14159 / 180;
	y = (double)mlx->map.y;
    z = (double)mlx->map.z;
	mlx->map.y = y * cos(ang) + z * sin(ang);
	mlx->map.z = -y * sin(ang) + z * cos(ang);
    printf("y : %d, map.y : %d\n", y, mlx->map.y);
}

// static void	rot_y(t_mlx *mlx, double ang)
// {
// 	int	x;

// 	x = mlx->map.rx ;make 
// 	mlx->map.rx = x * cos(ang) + mlx->map.rz * sin(ang);
// 	mlx->map.rz = -x * sin(ang) + mlx->map.rz * cos(ang);
// }

// static void	rot_z(t_mlx *mlx, double ang)
// {
// 	int	x;
// 	int	y;

// 	x = mlx->map.rx;
// 	y = mlx->map.ry;
// 	mlx->map.rx = x * cos(ang) - y * sin(ang);
// 	mlx->map.ry = x * sin(ang) + y * cos(ang);
// }

/*
** Using rotation matrix to get new coordinates
** for each point. Centering RX and RY before
** rotation.
*/

// void		rotate(t_mlx *mlx)
// {
// 	// int	x;
// 	// int	y;

// 	mlx->data.y = 0;
// 	while (mlx->data.y < mlx->data.line)
// 	{
// 		mlx->data.x = 0;
// 		while (mlx->data.x < mlx->data.col)
// 		{
// 			// RX = POINT_X;
// 			// RY = POINT_Y;
// 			// RZ = POINT_Z;
// 			// RX *= ZOOM;
// 			// RY *= ZOOM;
// 			// RZ *= ZOOM / ZMOD;
// 			// RX -= (MAP_WIDTH * ZOOM) / 2;
// 			// RY -= (MAP_HEIGHT * ZOOM) / 2;
//             printf("x_angle : %f\n", mlx->x_angle);
// 			rot_x(mlx, mlx->x_angle);
// 			// rot_y(mlx->data.tab[mlx->data.y][mlx->data.x], mlx->x_angle);
// 			// rot_y(POINT, radian_ang(Y_ANGLE));
// 			// rot_z(POINT, radian_ang(Z_ANGLE));
// 			mlx->data.x++;
// 		}
// 		mlx->data.y++;
// 	}
// }
