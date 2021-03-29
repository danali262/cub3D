#include "cub3d.h"

void	setting_drawing_variables(t_settings *grid)
{
	grid->calc.lineHeight = (int)(grid->screen_height
			/ grid->calc.perpWallDist);
	grid->calc.drawStart = -(grid->calc.lineHeight
			/ 2) + (grid->screen_height / 2);
	if (grid->calc.drawStart < 0)
		grid->calc.drawStart = 0;
	grid->calc.drawEnd = (grid->calc.lineHeight / 2) + (grid->screen_height
			/ 2);
	if (grid->calc.drawEnd >= grid->screen_height)
		grid->calc.drawEnd = grid->screen_height - 1;
}

void	calculate_texNum(t_settings *grid)
{
	if (grid->wall_or == 'N')
		grid->calc.texNum = 0;
	else if (grid->wall_or == 'S')
		grid->calc.texNum = 1;
	else if (grid->wall_or == 'E')
		grid->calc.texNum = 2;
	else if (grid->wall_or == 'W')
		grid->calc.texNum = 3;
}

void	calculate_wallX(t_settings *grid)
{
	if (grid->calc.side == 0)
		grid->calc.wallX = grid->plr.posY + grid->calc.perpWallDist
			* grid->calc.rayDirY;
	else
		grid->calc.wallX = grid->plr.posX + grid->calc.perpWallDist
			* grid->calc.rayDirX;
	grid->calc.wallX -= floor(grid->calc.wallX);
}

void	texture_casting_x(t_settings *grid)
{
	if (grid->wall_or == 'S')
	{
		grid->calc.texX = (int)(grid->calc.wallX * (double)grid->txt.width_s);
		grid->calc.texWidth = grid->txt.width_s;
	}
	else if (grid->wall_or == 'N')
	{
		grid->calc.texX = (int)(grid->calc.wallX * (double)grid->txt.width_n);
		grid->calc.texWidth = grid->txt.width_n;
	}
	else if (grid->wall_or == 'W')
	{
		grid->calc.texX = (int)(grid->calc.wallX * (double)grid->txt.width_w);
		grid->calc.texWidth = grid->txt.width_w;
	}
	else if (grid->wall_or == 'E')
	{
		grid->calc.texX = (int)(grid->calc.wallX * (double)grid->txt.width_e);
		grid->calc.texWidth = grid->txt.width_e;
	}
}

void	calculate_texX(t_settings *grid)
{
	if (grid->calc.side == 0 && grid->calc.rayDirX > 0)
		grid->calc.texX = grid->calc.texWidth - grid->calc.texX - 1;
	if (grid->calc.side == 1 && grid->calc.rayDirY < 0)
		grid->calc.texX = grid->calc.texWidth - grid->calc.texX - 1;
}
