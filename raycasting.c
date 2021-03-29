#include "cub3d.h"

void	calculate(t_settings *grid)
{
	wall_casting(grid);
	sprite_casting(grid);
}

void	draw(t_settings *grid)
{
	int	y;
	int	x;

	y = 0;
	while (y < grid->screen_height)
	{
		x = 0;
		while (x < grid->screen_width)
		{
			grid->img.data[y * grid->screen_width + x] = grid->buffer[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(grid->mlx, grid->win, grid->img.img_new, 0, 0);
}
