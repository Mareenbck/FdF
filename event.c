/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinebascunana <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:20:18 by marinebas         #+#    #+#             */
/*   Updated: 2022/02/08 12:02:10 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_altitude(int key, t_mlx *mlx)
{
	if (key == 65451)
		mlx->altitude += 2;
	else if (key == 65421)
		mlx->altitude -= 2;
}

void	ft_zoom(int key, t_mlx *mlx)
{
	if (key == 112)
		mlx->map.space += 5;
	else if (key == 111)
		if (mlx->map.space > 5)
			mlx->map.space -= 5;
}


void	ft_move(int key, t_mlx *mlx)
{
	if (key == 65362)
		mlx->pad_top_bot -= 40;
	else if (key == 65364)
		mlx->pad_top_bot += 40;
	else if (key == 65361)
		mlx->pad_left_right -= 40;
	else if (key == 65363)
		mlx->pad_left_right += 40;
}

void	ft_change_color(int key, t_mlx *mlx)
{
	if (key == 114)
		mlx->color.red += 20;
	else if (key == 103)
		mlx->color.green += 20;
	else if (key == 98)
		mlx->color.blue += 20;
}
//appelee avec numero de touche et void * transmis dans le main
//utiliser un putnbr pour recuperer le numero dela touche et adapter comportement en fonction de la touche
int deal_key(int key, t_mlx *mlx)
{ 
	printf("key = %d\n", key);
	if (key == 65307)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit (0);
	}
	else if (key == 65451 || key == 65421)
		ft_altitude(key, mlx);
	else if (key == 112 || key == 111)
		ft_zoom(key, mlx);
	else if (key == 65362 || key == 65364 || key == 65363 || key == 65361)
		ft_move(key, mlx);
	else if (key == 114 || key == 103 || key == 98)
		ft_change_color(key, mlx);
	ft_print_window(mlx);
	return (0);
}

