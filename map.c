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

void    ft_read_map(int fd, t_mlx *mlx)
{
    char *get_line;

    get_line = ft_get_next_line(fd);
    mlx->data.col = ft_count_words(get_line, ' ');
    mlx->data.line = 0;
    while (get_line)
    {
        free(get_line);
        mlx->data.line++;
        get_line = ft_get_next_line(fd);
    }
}

int **ft_init_tab(t_mlx *mlx)
{
    int **tab;

    tab = (int **)malloc(sizeof(int *) * mlx->data.line);
    if (!tab)
        return (NULL);
    // tab[mlx->data.line] = 0;
    while (mlx->data.line > 0)
    {
        mlx->data.line--;
        tab[mlx->data.line] = (int *)malloc(sizeof(int) * (mlx->data.col));
        if (!tab[mlx->data.line])
        {
            ft_free_tab(tab);
            return (NULL); 
        }
    }
    return (tab);
}

int ft_fill_tab(char *file, t_mlx *mlx)
{
    int fd;
    char *get_line;
    char **split_line;
 //OPEN A SECURISER
    
    mlx->data.tab = ft_init_tab(mlx);

    fd = open(file, O_RDONLY, 0);
    get_line = ft_get_next_line(fd);
    while (get_line)
    {
        split_line = ft_split(get_line, ' ');
        mlx->data.col = 0;
        while (split_line[mlx->data.col] != NULL)
        {
            mlx->data.tab[mlx->data.line][mlx->data.col] = ft_atoi(split_line[mlx->data.col]);
            free(split_line[mlx->data.col]);
            mlx->data.col++;
        }
        free(get_line);
        mlx->data.line++;
        get_line = ft_get_next_line(fd);
        free(split_line);
    }
    free(get_line);
    close(fd);
    return (0);
}