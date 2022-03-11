/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinebascunana <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:20:18 by marinebas         #+#    #+#             */
/*   Updated: 2022/03/11 17:11:31 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	int		fd;

	(void)ac;
	fd = open(av[1], O_RDONLY, 0);
	ft_read_map(fd, &mlx);
	close(fd);
	ft_fill_tab(av[1], &mlx);
	mlx.altitude = 1;
	mlx.x_angle = 0.0;
	ft_setup_colors(&mlx);
	ft_window_size(&mlx);
	ft_padding(&mlx);
	ft_space(&mlx);
	ft_create_window(&mlx);
	return (0);
}
