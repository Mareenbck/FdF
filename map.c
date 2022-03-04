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

int   **ft_init_map(int fd, t_data *data)
{
    char *get_line;

    get_line = ft_get_next_line(fd);
    data->col = ft_count_words(get_line, ' ');
    data->line = 0;
    while (get_line)
    {
        free(get_line);
        data->line++;
        get_line = ft_get_next_line(fd);
    }
    // free(get_line);
    data->tab = (int **)malloc(sizeof(t_data) * data->line);
    if (!data->tab)
        return (NULL);
    data->tab[data->line] = 0;

    // printf("DATA [%d] %ls \n",data->line, data->tab[data->line]);
    while (data->line > 0)
    { 
        data->line--;
        data->tab[data->line] = (int *)malloc(sizeof(int) * (data->col));
        if (!data->tab[data->line])
        {
            ft_free_tab(data->tab);
            return (NULL); 
        }
    }
    return (data->tab);
}

t_data *ft_read_map(char *file, t_data *data)
{
    // t_data data;
    char **split_line;
    int fd;
    char *get_line;
    //OPEN A SECURISER
    fd = open(file, O_RDONLY, 0);
    ft_init_map(fd, data);
    close(fd);
    fd = open(file, O_RDONLY, 0);
    get_line = ft_get_next_line(fd);
    while (get_line)
    {
        split_line = ft_split(get_line, ' ');
        data->col = 0;
        while (split_line[data->col] != NULL)
        {
            data->tab[data->line][data->col] = ft_atoi(split_line[data->col]);
            free(split_line[data->col]);
            data->col++;
        }
        free(get_line);
        data->line++;
        get_line = ft_get_next_line(fd);
        free(split_line);
    }
    free(get_line);
    close(fd);
    return (data);
}