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
	mlx->pad_top_bot = mlx->win_width / 10;
}

void	ft_space(t_mlx *mlx)
{
	int length;
	int width;
	int mul;
	mul = 3;

	if (mlx->data.col <= 20 || mlx->data.line <= 15)
		mul = 3;
	else if (mlx->data.col <= 30 || mlx->data.line <= 40)
		mul = 2;

	length = mlx->win_len / (mlx->data.col * mul);
	width = mlx->win_width / (mlx->data.line * mul);
	if (length <= width)
		mlx->map.space = length;
	else
		mlx->map.space = width;
}