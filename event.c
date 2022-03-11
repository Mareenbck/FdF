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
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
}

void	ft_zoom(int key, t_mlx *mlx)
{
	if (key == 112)
		mlx->map.space += 5;
	else if (key == 111)
		if (mlx->map.space > 5)
			mlx->map.space -= 5;
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
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
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
}

void	ft_set_angle(int key, t_mlx *mlx)
{
	if (key == 107)
		mlx->x_angle -= 5;
	else if (key == 106)
		mlx->x_angle += 5;
	
	// printf("angle : %f\n", mlx->x_angle);
	// else if (key == 6)
	// 	map_info->controls->x_angle -= 5;
	// else if (key == 7)
	// 	map_info->controls->x_angle += 5;
	// mlx_clear_window(MLX, WIN);
	// expose_hook(map_info);
}

//appelee avec numero de touche et void * transmis dans le main
//utiliser un putnbr pour recuperer le numero dela touche et adapter comportement en fonction de la touche
int deal_key(int key, t_mlx *mlx)
{ 
	// printf("key = %d\n", key);
	if (key == 65307)
		ft_exit_win(mlx);
	else if (key == 65451 || key == 65421)
		ft_altitude(key, mlx);
	else if (key == 112 || key == 111)
		ft_zoom(key, mlx);
	else if (key == 65362 || key == 65364 || key == 65363 || key == 65361)
		ft_move(key, mlx);
	else if (key == 114 || key == 103 || key == 98)
		ft_change_color(key, mlx);
	else if (key == 107|| key == 106)
		ft_set_angle(key, mlx);
	ft_print_window(mlx);
	return (0);
}
// int     mlx_mouse_move(void *win_ptr, int x, int y);
void	ft_move_mouse(int key, t_mlx *mlx)
{
	if (key == 4)
		mlx->pad_top_bot -= 40;
	else if (key == 5)
		mlx->pad_top_bot += 40;
	// else if (key == 65361)
	// 	mlx->pad_left_right -= 40;
	// else if (key == 65363)
	// 	mlx->pad_left_right += 40;
}

// int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
// mouse_hook(int button, int x,int y, void *param);
int mouse_hook(int key, t_mlx *mlx)
{
	// printf("key = %d\n", key);
	if (key == 4 || key == 5)
		ft_move_mouse(key, mlx);
	return (0);
}
