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

void	li_pt_begin(t_map *map)
{
	map->x1 = map->x - map->y;
	map->y1 = map->y;
	printf(">>LIGNE_PT_BEGIN<<\n");
	printf("map->x : %d, map->x1 : %d, map->x2 : %d\n", map->x, map->x1, map->x2);
	printf("map->y : %d, map->y1 : %d, map->y2 : %d\n", map->y, map->y1, map->y2);
}

void	col_pt_begin(t_map *map)
{
	map->x1 = map->x - map->y;
	map->y1 = map->y;
	printf(">>COL_PT_BEGIN<<\n");
	printf("map->x : %d, map->x1 : %d, map->x2 : %d\n", map->x, map->x1, map->x2);
	printf("map->y : %d, map->y1 : %d, map->y2 : %d\n", map->y, map->y1, map->y2);
}

void	li_pt_next(t_map *map)
{
	map->x2 = map->x + map->space;
	map->y2 = map->y;
	printf(">>LINE_PT_NEXT<<\n");
	printf("map->x : %d, map->x1 : %d, map->x2 : %d\n", map->x, map->x1, map->x2);
	printf("map->y : %d, map->y1 : %d, map->y2 : %d\n", map->y, map->y1, map->y2);
}

void	col_pt_next(t_map *map)
{
	map->x2 = map->x;
	map->y2 = map->y + map->space;
	printf(">>COL_PT_NEXT<<\n");
	printf("map->x : %d, map->x1 : %d, map->x2 : %d\n", map->x, map->x1, map->x2);
	printf("map->y : %d, map->y1 : %d, map->y2 : %d\n", map->y, map->y1, map->y2);
}

// void	col_pt_next(t_mlx *var)
// {
// 	var->point.x2 = var->point.x - var->point.y - var->point.space;
// 	var->point.y2 = -var->point.alt * var->map.map[var->map.y + 1][var->map.x]
// 		+ var->point.space + var->point.y + var->point.x;
// }


void	ft_draw_one_li(t_mlx *mlx, t_map *map, t_data *data, t_img *img)
{
	while (map->x < ((data->col) * map->space))
	{
	    printf(">>>LIGNE SUIVANTE<<<\n");
		li_pt_next(map);
		ft_line(mlx, map, img);
		// map->x++;
		map->x += map->space;
		map->x1 = map->x2;
		map->y1 = map->y2;
	}
}

void	ft_draw_one_col(t_mlx *mlx, t_map *map, t_data *data, t_img *img)
{
	while (map->y < ((data->line) * map->space))
	{
		col_pt_next(map);
		ft_line(mlx, map, img);
		// map->y++;
		map->y += map->space;
		map->x1 = map->x2;
		map->y1 = map->y2;
	}
}

void	ft_draw(t_data *data, t_mlx *mlx, t_img *img)
{
	t_map	map;
	map.x = 0;
  	map.space = 40;
	data->x = 0;

	(void)mlx;

	map.z = data->tab[data->y][data->x];
	map.y = 0;
	data->y = 0;
	printf(">>FT_DRAW<<\n");
	// y <= nb_line * space >> pour afficher derniere ligne. Mais segfault
  	while (map.y <= (data->line * map.space))
  	{
		map.x = 0;
		data->x  = 0;
		printf("map.x : %d, map.x1 : %d, map.x2 : %d\n", map.x, map.x1, map.x2);
		printf("map.y : %d, map.y1 : %d, map.y2 : %d\n", map.y, map.y1, map.y2);
		li_pt_begin(&map);
		ft_draw_one_li(mlx, &map, data, img);
		data->y++;
		map.y += map.space;
	}
    map.x = 0;
	data->x  = 0;
    while (map.x <= (data->col * map.space))
    {
        map.y = 0;
		data->y  = 0;
        col_pt_begin(&map);
		ft_draw_one_col(mlx, &map, data, img);
		data->x++;
		map.x += map.space;
    }
	// x = 0;
	// y_alt = 0;
	// x_alt = 0;
	// while (x <= nb_col * space)
	// {
	// 	y = 0;
	// 	y_alt = 0;
	// 	while (y < (nb_line * space))
	// 	{
	// 		z = data->tab[y_alt][x_alt];
	// 		ft_col(x, y, mlx, img, z, space);
	// 		y += space;
	// 		y_alt++;
	// 	}
	// 	x += space;
	// 	x_alt++;
	// }

}