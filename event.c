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
	// ft_space(map, data);

	if (key == 112)
		mlx->map.space += 5;
	else if (key == 111)
		if (mlx->map.space > 5)
			mlx->map.space -= 5;
	printf("mlx->map.space = %d\n", mlx->map.space);

}
//appelee avec numero de touche et void * transmis dans le main
//utiliser un putnbr pour recuperer le numero dela touche et adapter comportement en fonction de la touche
int deal_key(int key, t_mlx *mlx)
{ 
	printf("key = %d\n", key);
	if (key == 113)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		return (0);
	}
	else if (key == 65451 || key == 65421)
		ft_altitude(key, mlx);
	else if (key == 112 || key == 111)
		ft_zoom(key, mlx);
	ft_expose_hook(mlx);
	return (0);
}

