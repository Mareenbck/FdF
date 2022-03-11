/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinebascunana <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:20:18 by marinebas         #+#    #+#             */
/*   Updated: 2022/02/08 12:02:10 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int		check_win_size(int key, t_dot **matrix)
{
	if ((key == 0 && PRM.win_y <= 500) || (key == 6 && PRM.win_x <= 500))
		return (1);
	if ((key == 1 && PRM.win_y > 1000) || (key == 7 && PRM.win_x > 2000))
		return (1);
	return (0);
}

void	change_window_size(int key, t_dot **matrix)
{
	if (check_win_size(key, matrix))
		return ;
	if (key == 6)
		PRM.win_x -= 100;
	if (key == 7)
		PRM.win_x += 100;
	if (key == 0)
		PRM.win_y -= 100;
	if (key == 1)
		PRM.win_y += 100;
	if (key == 3)
		full_screen(matrix);
}


