#include "cub3d.h"

void	move_forward(t_settings *grid)
{
	if (grid->plr.key_w)
	{
		if (grid->map[(int)grid->plr.posY][(int)(grid->plr.posX
			+ (grid->plr.dirX * grid->plr.moveSpeed))] == 0)
			grid->plr.posX = grid->plr.posX + (grid->plr.dirX
					* grid->plr.moveSpeed);
		if (grid->map[(int)(grid->plr.posY + (grid->plr.dirY
				* grid->plr.moveSpeed))][(int)grid->plr.posX] == 0)
			grid->plr.posY = grid->plr.posY + (grid->plr.dirY
					* grid->plr.moveSpeed);
	}
}

void	move_backward(t_settings *grid)
{
	if (grid->plr.key_s)
	{
		if (grid->map[(int)grid->plr.posY][(int)(grid->plr.posX
			- (grid->plr.dirX * grid->plr.moveSpeed))] == 0)
			grid->plr.posX = grid->plr.posX - (grid->plr.dirX
					* grid->plr.moveSpeed);
		if (grid->map[(int)(grid->plr.posY - (grid->plr.dirY
				* grid->plr.moveSpeed))][(int)grid->plr.posX] == 0)
			grid->plr.posY = grid->plr.posY - (grid->plr.dirY
					* grid->plr.moveSpeed);
	}
}

void	move_left(t_settings *grid)
{
	if (grid->plr.key_a)
	{
		if (grid->map[(int)grid->plr.posY][(int)(grid->plr.posX
			- (grid->plr.planeX * grid->plr.moveSpeed))] == 0)
			grid->plr.posX = grid->plr.posX - (grid->plr.planeX
					* grid->plr.moveSpeed);
		if (grid->map[(int)(grid->plr.posY - (grid->plr.planeY
				* grid->plr.moveSpeed))][(int)grid->plr.posX] == 0)
			grid->plr.posY = grid->plr.posY - (grid->plr.planeY
					* grid->plr.moveSpeed);
	}
}

void	move_right(t_settings *grid)
{
	if (grid->plr.key_d)
	{
		if (grid->map[(int)grid->plr.posY][(int)(grid->plr.posX
			+ (grid->plr.planeX * grid->plr.moveSpeed))] == 0)
			grid->plr.posX = grid->plr.posX + (grid->plr.planeX
					* grid->plr.moveSpeed);
		if (grid->map[(int)(grid->plr.posY + (grid->plr.planeY
				* grid->plr.moveSpeed))][(int)grid->plr.posX] == 0)
			grid->plr.posY = grid->plr.posY + (grid->plr.planeY
					* grid->plr.moveSpeed);
	}
}
