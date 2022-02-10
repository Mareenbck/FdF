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

void	**ft_free_tab(int **tab)
{
	int	i;

	i = 0;
    if (tab)
    {
        while (tab[i])
        {
            free(tab[i]);
            tab[i] = NULL;
            i++;
        }
        free(tab);
    }
	return (NULL);
}

int   **ft_init_map(int fd)
{
    t_data tab;
    int x;

    char *get_line;
    int **map;

    tab.col = 0;
    get_line = ft_get_next_line(fd);
    x = ft_count_words(get_line, ' ');
    tab.col = x;
    tab.line = 0;
    while (get_line)
    {
        free(get_line);
        tab.line++;
        get_line = ft_get_next_line(fd);
    }
    free(get_line);
    map = (int **)malloc(sizeof(int *) * tab.line + 1);
    if (!map)
        return (NULL);
    map[tab.line] = NULL;
    tab.line--;
    while (tab.line >= 0)
    { 
        map[tab.line] = (int *)malloc(sizeof(int) * (tab.col));
        if (!map[tab.line])
        {
            ft_free_tab(map);
            return (NULL); 
        }
        tab.line--;
    }
    return (map);
}


int **ft_read_map(char *file)
{
    int **map;
    char **split_line;
    // t_data map;
    int fd;
    // int y;
    char *get_line;

    fd = open(file, O_RDONLY, 0);
    map = ft_init_map(fd);
    close(fd);

    int line;
    line = 0;
    int col;
    col = 0;
    fd = open(file, O_RDONLY, 0);
    get_line = ft_get_next_line(fd);
    while (get_line)
    {
        split_line = ft_split(get_line, ' ');
        // printf("split_line[%d][%d] = %s\n", line, col, split_line[line]);
        col = 0;
        while (split_line[col] != NULL)
        {
            map[line][col] = ft_atoi(split_line[col]);
            // printf("sortie map[%d][%d] = %d\n", line, col, map[line][col]);

            // printf("split_line = %s\n", split_line[3]);
            // printf("map[%d][%d] = %d\n", line, col, map[line][col]);
            // printf("split_line[%d][%d] = %s\n", line, col, split_line[line]);
            free(split_line[col]);
            col++;
            // printf("map[%d][%d] = %d\n", line, col, map[line][col]);
            // printf("split_line[%d][%d] = %s\n", line, col, split_line[line]);

        }
        // printf("sortie map[%d][%d] = %d\n", line, col, map[line][col]);
        free(get_line);
        line++;
        get_line = ft_get_next_line(fd);
        free(split_line);
    }
    free(get_line);
    close(fd);
    // map[line] = NULL;
    // ft_free_tab(map);
    return (map);
}