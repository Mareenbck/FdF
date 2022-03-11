/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:16:12 by mbascuna          #+#    #+#             */
/*   Updated: 2022/03/11 17:18:57 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (!mlx->data.tab)
		return ;
	while (i < mlx->data.line)
	{
		free(mlx->data.tab[i]);
		mlx->data.tab[i] = 0;
		i++;
	}
	free(mlx->data.tab);
}

int	ft_exit_win(t_mlx *mlx)
{
	ft_free_map(mlx);
	if (!mlx)
		exit(0);
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	exit(0);
	return (1);
}

void	ft_free_tab(int **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = 0;
		i++;
	}
	free(tab);
}
