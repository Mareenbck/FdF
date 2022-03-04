/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinebascunana <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:20:18 by marinebas         #+#    #+#             */
/*   Updated: 2022/02/08 12:02:10 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(t_mlx *mlx, t_map *map, t_data *data, t_img *img)
{
	while (map->x < ((data->col - 1) * map->space))
	{
        // Init des points 2
		map->x2 = map->x + map->space - map->y;
	    map->y2 = map->y + map->x + map->space - (mlx->altitude * data->tab[data->y][data->x + 1]);
		printf("line = mlx->alt = %d\n", mlx->altitude);
		
		ft_bresenham(mlx, map, img, data);
		map->x += map->space + 1;
		map->x1 = map->x2;
		map->y1 = map->y2;
		data->x++;
	}
}

void	ft_col(t_mlx *mlx, t_map *map, t_data *data, t_img *img)
{
	while (map->y < ((data->line - 1) * map->space))
	{
		// Init des points 2
		map->x2 = map->x - map->y - map->space;
	    map->y2 = map->x + map->y + map->space - (mlx->altitude * data->tab[data->y + 1][data->x]);
		ft_bresenham(mlx, map, img, data);
		map->y += map->space + 1;
		map->x1 = map->x2;
		map->y1 = map->y2;
		data->y++;
	}
}

void	ft_draw(t_data *data, t_mlx *mlx, t_img *img, t_map *map)
{
	// t_map	map;
    // >> FONCTION POUR DETERMINER SPACE
  	// map.space = 20;
	// ft_space(map, data);
    // <<
	map->y = 0;
	data->y  = 0;
	mlx->altitude = 1;
  	while (map->y < ((data->line) * map->space))
  	{
		map->x = 0;
		data->x  = 0;
        // Init des points 1
		map->x1 = map->x - map->y;
	    map->y1 = map->y + map->x - (mlx->altitude * data->tab[data->y][data->x]);
		printf("x1 = %d, y1 = %d\n", map->x1, map->x2);
		ft_line(mlx, map, data, img);
		data->y++;
		map->y += map->space + 1;
	}
    map->x = 0;
	data->x  = 0;
    while (map->x <= (data->col * map->space))
    {
        map->y = 0;
		data->y  = 0;
        // Init des points 1
        map->x1 = map->x - map->y;
	    map->y1 = map->y + map->x - (mlx->altitude * data->tab[data->y][data->x]);
		ft_col(mlx, map, data, img);
		data->x++;
		map->x += map->space + 1;
    }
	

}