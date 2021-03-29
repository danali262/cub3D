#include "cub3d.h"

void	rotate_left(t_settings *grid)
{
	double	oldDirX;
	double	oldPlaneX;

	if (grid->plr.key_left)
	{
		oldDirX = grid->plr.dirX;
		oldPlaneX = grid->plr.planeX;
		grid->plr.dirX = grid->plr.dirX * cos(-grid->plr.rotSpeed)
			- grid->plr.dirY * sin(-grid->plr.rotSpeed);
		grid->plr.planeX = grid->plr.planeX * cos(-grid->plr.rotSpeed)
			- grid->plr.planeY * sin(-grid->plr.rotSpeed);
		grid->plr.dirY = oldDirX * sin(-grid->plr.rotSpeed) + grid->plr.dirY
			* cos(-grid->plr.rotSpeed);
		grid->plr.planeY = oldPlaneX * sin(-grid->plr.rotSpeed)
			+ grid->plr.planeY * cos(-grid->plr.rotSpeed);
	}
}

void	rotate_right(t_settings *grid)
{
	double	oldDirX;
	double	oldPlaneX;

	if (grid->plr.key_right)
	{
		oldDirX = grid->plr.dirX;
		oldPlaneX = grid->plr.planeX;
		grid->plr.dirX = grid->plr.dirX * cos(grid->plr.rotSpeed)
			- grid->plr.dirY * sin(grid->plr.rotSpeed);
		grid->plr.planeX = grid->plr.planeX * cos(grid->plr.rotSpeed)
			- grid->plr.planeY * sin(grid->plr.rotSpeed);
		grid->plr.dirY = oldDirX * sin(grid->plr.rotSpeed) + grid->plr.dirY
			* cos(grid->plr.rotSpeed);
		grid->plr.planeY = oldPlaneX * sin(grid->plr.rotSpeed)
			+ grid->plr.planeY * cos(grid->plr.rotSpeed);
	}
}
