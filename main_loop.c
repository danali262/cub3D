#include "cub3d.h"

static void	check_render(t_settings *grid)
{
	if (grid->plr.key_w)
		grid->render = 1;
	if (grid->plr.key_s)
		grid->render = 1;
	if (grid->plr.key_a)
		grid->render = 1;
	if (grid->plr.key_d)
		grid->render = 1;
	if (grid->plr.key_left)
		grid->render = 1;
	if (grid->plr.key_right)
		grid->render = 1;
}

static void	execute_hook(t_settings *grid)
{
	if (grid->plr.key_w)
		move_forward(grid);
	if (grid->plr.key_s)
		move_backward(grid);
	if (grid->plr.key_a)
		move_left(grid);
	if (grid->plr.key_d)
		move_right(grid);
	if (grid->plr.key_left)
		rotate_left(grid);
	if (grid->plr.key_right)
		rotate_right(grid);
}

void	exchange_img(t_settings *grid)
{
	grid->img.img_old = grid->img.img_new;
	mlx_put_image_to_window(grid->mlx, grid->win, grid->img.img_old, 0, 0);
}

void	new_img(t_settings *grid)
{
	grid->img.img_new = mlx_new_image(grid->mlx, grid->screen_width,
			grid->screen_height);
	if (!grid->img.img_new)
		error(1);
	grid->img.data = (int *)mlx_get_data_addr(grid->img.img_new,
			&grid->img.bpp, &grid->img.size_l, &grid->img.endian);
}

int	main_loop(t_settings *grid)
{
	check_render(grid);
	if (!grid->render)
		return (0);
	execute_hook(grid);
	if (grid->img.img_new)
		exchange_img(grid);
	new_img(grid);
	calculate(grid);
	draw(grid);
	if (grid->screenshot)
		make_screenshot(grid);
	if (grid->img.img_old)
		mlx_destroy_image(grid->mlx, grid->img.img_old);
	grid->x = 0;
	grid->render = 0;
	return (0);
}
