#include "cub3d.h"

static void	setting_variables(t_settings *grid)
{
	grid->calc.cameraX = 2 * grid->x / (double)grid->screen_width - 1;
	grid->calc.rayDirX = grid->plr.dirX + (grid->plr.planeX
			* grid->calc.cameraX);
	grid->calc.rayDirY = grid->plr.dirY + (grid->plr.planeY
			* grid->calc.cameraX);
	grid->calc.mapX = (int)grid->plr.posX;
	grid->calc.mapY = (int)grid->plr.posY;
	grid->calc.deltaDistX = fabs(1 / grid->calc.rayDirX);
	grid->calc.deltaDistY = fabs(1 / grid->calc.rayDirY);
	grid->calc.hit = 0;
}

static void	perform_DDA(t_settings *grid)
{
	while (grid->calc.hit == 0)
	{
		if (grid->calc.sideDistX < grid->calc.sideDistY)
		{
			grid->calc.sideDistX += grid->calc.deltaDistX;
			grid->calc.mapX += grid->calc.stepX;
			grid->calc.side = 0;
		}
		else
		{
			grid->calc.sideDistY += grid->calc.deltaDistY;
			grid->calc.mapY += grid->calc.stepY;
			grid->calc.side = 1;
		}
		if (grid->map[grid->calc.mapY][grid->calc.mapX] == 1)
			grid->calc.hit = 1;
	}
}

static void	calculate_step(t_settings *grid)
{
	if (grid->calc.rayDirX < 0)
	{
		grid->calc.stepX = -1;
		grid->calc.sideDistX = (grid->plr.posX - grid->calc.mapX)
			* grid->calc.deltaDistX;
	}
	else
	{
		grid->calc.stepX = 1;
		grid->calc.sideDistX = (grid->calc.mapX + 1.0 - grid->plr.posX)
			* grid->calc.deltaDistX;
	}
	if (grid->calc.rayDirY < 0)
	{
		grid->calc.stepY = -1;
		grid->calc.sideDistY = (grid->plr.posY - grid->calc.mapY)
			* grid->calc.deltaDistY;
	}
	else
	{
		grid->calc.stepY = 1;
		grid->calc.sideDistY = (grid->calc.mapY + 1.0 - grid->plr.posY)
			* grid->calc.deltaDistY;
	}
	perform_DDA(grid);
}

static void	calculate_perpWallDist(t_settings *grid)
{
	if (grid->calc.side == 0)
	{
		grid->calc.perpWallDist = (grid->calc.mapX - grid->plr.posX + (1.0
					- grid->calc.stepX) / 2) / grid->calc.rayDirX;
		if (grid->calc.rayDirX < 0)
			grid->wall_or = 'W';
		else
			grid->wall_or = 'E';
	}
	else
	{
		grid->calc.perpWallDist = (grid->calc.mapY - grid->plr.posY + (1.0
					- grid->calc.stepY) / 2) / grid->calc.rayDirY;
		if (grid->calc.rayDirY < 0)
			grid->wall_or = 'N';
		else
			grid->wall_or = 'S';
	}
}

void	wall_casting(t_settings *grid)
{
	while (grid->x < grid->screen_width)
	{
		setting_variables(grid);
		calculate_step(grid);
		calculate_perpWallDist(grid);
		setting_drawing_variables(grid);
		calculate_texNum(grid);
		calculate_wallX(grid);
		texture_casting_x(grid);
		calculate_texX(grid);
		texture_casting_y(grid);
		draw_image(grid);
		grid->zBuffer[grid->x] = grid->calc.perpWallDist;
		grid->x++;
	}
}
