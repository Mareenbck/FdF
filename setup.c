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
	if (data->col <= 10)
		mlx->win_len = data->col * 150;
	else if (data->col <= 20)
		mlx->win_len = data->col * 80;
	else if (data->col <= 50)
		mlx->win_len = data->col * 30;
	else if (data->col <= 100)
		mlx->win_len = data->col * 20;
	else
		mlx->win_len = data->col * 10;
	if (data->line <= 20)
		mlx->win_width = data->line * 80;
	else if (data->line <= 50)
		mlx->win_width = data->line * 50;
	else if (data->line <= 100)
		mlx->win_width = data->line * 20;
	else
		mlx->win_width = data->line * 10;
}

void	ft_padding(t_mlx *mlx)
{
	mlx->pad_left_right = mlx->win_len / 4;
	mlx->pad_top_bot = mlx->win_width / 8;
}