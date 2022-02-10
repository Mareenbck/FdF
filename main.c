/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinebascunana <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:20:18 by marinebas         #+#    #+#             */
/*   Updated: 2022/02/08 12:02:10 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_x11/mlx.h"
#include "./minilibx_macos/mlx.h"
//#include "./minilibx/mlx_int.h"
//#include "./MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//appelee avec numero de touche et void * transmis dans le main
//utiliser un putnbr pour recuperer le numero dela touche et adapter comportement en fonction de la touche
int deal_key(int key, void *param)
{
	(void)key;
	(void)param;
	ft_putchar('X');
//	mlx_pixel_put(mlx_ptr, new_window, 25, 250, 0xFF5733);

	return (0);
}

int main()
{
	void *mlx_ptr;
	void *new_window;

	mlx_ptr = mlx_init();
	//remplacer 500 par le nb de ligne de get next line ?
	new_window = mlx_new_window(mlx_ptr, 500, 500, "test");
	mlx_pixel_put(mlx_ptr, new_window, 25, 250, 0xFF5733);
	//evenement clavier
	mlx_key_hook(new_window, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
