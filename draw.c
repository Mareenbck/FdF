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
	while (map->x < ((data->col) * map->space))
	{
        // Init des points 2
		map->x2 = map->x + map->space;
	    map->y2 = map->y;
		ft_bresenham(mlx, map, img);
		map->x += map->space;
		map->x1 = map->x2;
		map->y1 = map->y2;
	}
}

void	ft_col(t_mlx *mlx, t_map *map, t_data *data, t_img *img)
{
	while (map->y < ((data->line) * map->space))
	{
        // Init des points 2
		map->x2 = map->x;
	    map->y2 = map->y + map->space;
		ft_bresenham(mlx, map, img);
		map->y += map->space;
		map->x1 = map->x2;
		map->y1 = map->y2;
	}
}

void	ft_draw(t_data *data, t_mlx *mlx, t_img *img)
{
	t_map	map;
    // >> FONCTION POUR DETERMINER SPACE
  	map.space = 50;
    // <<

	map.z = data->tab[data->y][data->x];
  	while (map.y <= (data->line * map.space))
  	{
		map.x = 0;
		data->x  = 0;
        // Init des points 1
		map.x1 = map.x - map.y;
	    map.y1 = map.y;
		ft_line(mlx, &map, data, img);
		data->y++;
		map.y += map.space;
	}
    map.x = 0;
	data->x  = 0;
    while (map.x <= (data->col * map.space))
    {
        map.y = 0;
		data->y  = 0;
        // Init des points 1
        map.x1 = map.x - map.y;
	    map.y1 = map.y;
		ft_col(mlx, &map, data, img);
		data->x++;
		map.x += map.space;
    }
}