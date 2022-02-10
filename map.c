/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:47:08 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/10 10:47:11 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int   **ft_init_map(int fd)
{
    t_data tab;
    int x;
    // int y;
    char *line;
    int **map;
    // int fd;
    // int i = 0;
    // tab = 0;
    printf("rentre dans init map\n");
    line = ft_get_next_line(fd);
    printf("line = %s\n", line);
    x = ft_count_words(line, ' ');
    printf("x = %d\n", x);
    tab.col = x;
    // while (i <= x)
    // {
    //     printf("i = %d\n", i);

    //     tab.col = i;    
    //     i++;
    // }
    // *map.x = x;
    printf("col = %d\n", tab.col);

    //free(line);
    // y = 0;
    while (line)
    {
        printf("line boucle = %s\n", line);
        printf("y = %d\n", tab.line);
        tab.line++;
        line = ft_get_next_line(fd);
        free(line);

    }
    // free(line);
    map = malloc(sizeof(int) * tab.line + 1);
    if (!map)
        return (NULL);
    while (tab.line)
    {
        map[tab.col] = malloc(sizeof(int) * (tab.col));
        tab.line--;
    }
    // map = malloc(sizeof(t_map) * map->y + 1);
    // if (!map)
    //     return (NULL);
    // while (map->y)
    // {
    //     map[map->y] = malloc(sizeof(t_map) * map->x + 1);
    //     y--;

    // }
    return (map);
}

// int **ft_malloc_tab(int x, int y)
// {
//     int **map;
//     int *line;
//     int i;

//     map = malloc(sizeof(int) * y + 1);
//     if (!map)
//         return (NULL);
//     line = malloc(sizeof(int) * (x * y));
//     if (!line)
//         return (NULL);
//     i = 0;
//     while (i < y)
//     {
//         map[i] = &line[i * x];
//         i++;
//     }
//     return (map);
    
// }

// int	ft_nb_col_li(char *av, t_mlx *var)
// {
// 	char	*line;
// 	int		i;
// 	int		fd;

// 	i = 0;
// 	fd = (open(av, O_RDONLY));
// 	if (fd == -1)
// 		return (-1);
// 	line = get_next_line(fd);
// 	while (line[i])
// 	{
// 		if (line[i] == ' ')
// 			var->map.col++;
// 		i++;
// 	}
// 	while (line)
// 	{
// 		var->map.li++;
// 		line = get_next_line(fd);
// 		free(line);
// 	}
// 	close (fd);
// 	return (0);
// }



// void   ft_fill_map(int **matrix, int y, char *line)
// {
//     char  **fill;
//     int x;

//     fill = ft_split(line, ' ');
//     x = 0;
//     while (fill[x])
//     {
//         matrix[y][x].z = ft_atoi(fill[x]);
//         matrix[y][x].x = x;
//         matrix[y][x].y = y;
//     }
//    free(fill);

// }

int **ft_read_map(char *file)
{
    int **map;
    // t_data map;
    int fd;
    int y;
    char *line;

    fd = open(file, O_RDONLY, 0);
    printf("fd = %d\n", fd);
    map = ft_init_map(fd);
    close(fd);
    // matrix = ft_malloc_tab(map->col, map->line);
    y = 0;
    line = ft_get_next_line(fd);
    while (line)
    {
        // ft_fill_map(matrix, y, line);
        line = ft_get_next_line(fd);
        y++;
    }
    free(line);
    // matrix[y] = NULL;
    return (map);
}