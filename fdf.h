/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinebascunana <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:22:53 by marinebas         #+#    #+#             */
/*   Updated: 2022/02/07 14:23:31 by marinebas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx_x11/mlx.h"
# include "./minilibx_macos/mlx.h"
# include <stdio.h>
# include <unistd.h>       
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct  t_data
{
	int	**tab;
	int	col;
	int	line;
}   t_data;


int main(int ac, char **av);

/*****MAP.C*****/
int   **ft_read_map(char *file);
int	count_words(char const *s, char c);
int   **ft_init_map(int fd);
void   ft_fill_map(t_data **matrix, int y, char *line);
void	**ft_free_tab(int **tab);




#endif
