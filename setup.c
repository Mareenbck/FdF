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


void	ft_window_size(t_data *data, t_mlx *mlx)
{
	mlx->win_len = data->col * 100;
	mlx->win_width = data->line * 100;
}

void	ft_padding(t_mlx *mlx)
{
	mlx->pad_left_right = mlx->win_len / 2;
	mlx->pad_top_bot = mlx->win_width / 8;
}

void	ft_space(t_map *map, t_data *data)
{
	if (data->col <= 20)
		map->space = 30;
	else if (data->col <= 50)
		map->space = 20;
	else if (data->col <= 100)
		map->space = 15;
	else if (data->col <= 200)
		map->space = 5;
	else
		map->space = 1;
}

void	ft_colors(t_data *data, t_color *color)
{
	// t_color color;
	int i = 0;
	int j = 0;
	// int k = 0;


	data->z = data->tab[data->y][data->x];
	if (data->tab[data->y + 1])
		i = data->tab[data->y + 1][data->x];
	if (data->tab[data->y][data->x + 1])
		j = data->tab[data->y][data->x + 1];
	// if ((data->tab[data->y + 1]) && (data->tab[data->y][data->x + 1]))
	 	// k = data->tab[data->y + 1][data->x + 1];
	if (data->z > 0 || i > 0 || j < 0)
	{
		color->red = 255;
		color->green = 153;
		color->blue = 158;
	}
	else
	{
		color->red = 94;
		color->green = 100;
		color->blue = 114;
	}
}