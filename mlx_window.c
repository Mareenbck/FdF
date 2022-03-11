#include "fdf.h"

int ft_print_window(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_len, mlx->win_width);
	if (!mlx->img.img_ptr)
		ft_exit_win(mlx);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	ft_draw(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	return (0);
}

void	ft_create_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return ;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_len, mlx->win_width, "fdf");
	if (!mlx->win_ptr)
		return ;
	mlx_key_hook(mlx->win_ptr, deal_key, mlx);
	mlx_hook(mlx->win_ptr, 33, 1L << 2, ft_exit_win, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_hook, mlx);
	ft_print_window(mlx);
	mlx_loop(mlx->mlx_ptr);
}