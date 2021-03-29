#include "cub3d.h"

void	texture_casting_y(t_settings *grid)
{
	if (grid->wall_or == 'S')
	{
		grid->calc.step = 1.0 * grid->txt.height_s / grid->calc.lineHeight;
		grid->calc.texHeight = grid->txt.height_s;
	}
	else if (grid->wall_or == 'N')
	{
		grid->calc.step = 1.0 * grid->txt.height_n / grid->calc.lineHeight;
		grid->calc.texHeight = grid->txt.height_n;
	}
	else if (grid->wall_or == 'W')
	{
		grid->calc.step = 1.0 * grid->txt.height_w / grid->calc.lineHeight;
		grid->calc.texHeight = grid->txt.height_w;
	}
	if (grid->wall_or == 'E')
	{
		grid->calc.step = 1.0 * grid->txt.height_e / grid->calc.lineHeight;
		grid->calc.texHeight = grid->txt.height_e;
	}
	grid->calc.texPos = (grid->calc.drawStart - (grid->screen_height / 2)
			+ (grid->calc.lineHeight / 2)) * grid->calc.step;
}

void	draw_image(t_settings *grid)
{
	int	y;

	y = grid->calc.drawStart;
	while (y < grid->calc.drawEnd)
	{
		grid->calc.texY = (int)grid->calc.texPos & (grid->calc.texHeight - 1);
		grid->calc.texPos += grid->calc.step;
		grid->calc.color = grid->texture[grid->calc.texNum][grid->calc.texHeight
			* grid->calc.texY + grid->calc.texX];
		if (grid->calc.side == 1)
			grid->calc.color = (grid->calc.color >> 1) & 8355711;
		grid->buffer[y][grid->x] = grid->calc.color;
		y++;
	}
	while (y < grid->screen_height)
	{
		grid->buffer[y][grid->x] = grid->floor_color;
		grid->buffer[grid->screen_height - y - 1][grid->x]
			= grid->ceiling_color;
		y++;
	}
}
