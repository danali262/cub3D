#include "cub3d.h"

static void	initialize_spritecasting2(t_settings *grid)
{
	grid->spr.drawStartY = -grid->spr.spriteHeight / 2 + grid->screen_height
		/ 2 + grid->spr.vMoveScreen;
	if (grid->spr.drawStartY < 0)
		grid->spr.drawStartY = 0;
	grid->spr.drawEndY = grid->spr.spriteHeight / 2 + grid->screen_height / 2
		+ grid->spr.vMoveScreen;
	if (grid->spr.drawEndY >= grid->screen_height)
		grid->spr.drawEndY = grid->screen_height - 1;
	grid->spr.spriteWidth = (int)fabs((grid->screen_height
				/ grid->spr.transformY) / grid->spr.uDiv);
	grid->spr.drawStartX = -grid->spr.spriteWidth / 2 + grid->spr.spriteScreenX;
	if (grid->spr.drawStartX < 0)
		grid->spr.drawStartX = 0;
	grid->spr.drawEndX = grid->spr.spriteWidth / 2 + grid->spr.spriteScreenX;
	if (grid->spr.drawEndX >= grid->screen_width)
		grid->spr.drawEndX = grid->screen_width - 1;
}

void	initialize_spritecasting(t_settings *grid)
{
	grid->spr.spriteX = grid->sprites[grid->spr.sprite0rder[grid->i]][0]
		- grid->plr.posX;
	grid->spr.spriteY = grid->sprites[grid->spr.sprite0rder[grid->i]][1]
		- grid->plr.posY;
	grid->spr.invDet = 1.0 / (grid->plr.planeX * grid->plr.dirY
			- grid->plr.dirX * grid->plr.planeY);
	grid->spr.transformX = grid->spr.invDet * (grid->plr.dirY
			* grid->spr.spriteX - grid->plr.dirX * grid->spr.spriteY);
	grid->spr.transformY = grid->spr.invDet * (-grid->plr.planeY
			* grid->spr.spriteX + grid->plr.planeX * grid->spr.spriteY);
	grid->spr.spriteScreenX = (int)(grid->screen_width / 2)*(1
			+ grid->spr.transformX / grid->spr.transformY);
	grid->spr.vMoveScreen = (int)(grid->spr.vMove / grid->spr.transformY);
	grid->spr.spriteHeight = (int)fabs((grid->screen_height
				/ grid->spr.transformY) / grid->spr.vDiv);
	initialize_spritecasting2(grid);
}

static void	draw_sprite_aux(t_settings *grid, int y)
{
	grid->spr.d = (y - grid->spr.vMoveScreen) * 256
		- grid->screen_height * 128 + grid->spr.spriteHeight * 128;
	grid->calc.texY = ((grid->spr.d * grid->calc.texHeight)
			/ grid->spr.spriteHeight) / 256;
	grid->calc.color = grid->texture[4][grid->calc.texWidth
		* grid->calc.texY + grid->calc.texX];
	if ((grid->calc.color & 0x00FFFFFF) != 0)
		grid->buffer[y][grid->spr.stripe] = grid->calc.color;
}

void	draw_sprite(t_settings *grid)
{
	int	y;

	while (grid->spr.stripe < grid->spr.drawEndX)
	{
		grid->calc.texX = (int)((256 * (grid->spr.stripe
						- (-grid->spr.spriteWidth / 2
							+ grid->spr.spriteScreenX)) * grid->calc.texWidth
					/ grid->spr.spriteWidth) / 256);
		if (grid->spr.transformY > 0 && grid->spr.stripe > 0
			&& grid->spr.stripe < grid->screen_width && grid->spr.transformY
			< grid->zBuffer[grid->spr.stripe])
		{
			y = grid->spr.drawStartY;
			while (y < grid->spr.drawEndY)
			{
				draw_sprite_aux(grid, y);
				y++;
			}
		}
		grid->spr.stripe++;
	}
}
