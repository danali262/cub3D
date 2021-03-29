#include "cub3d.h"

void	malloc_textures(t_settings *grid)
{
	grid->texture = (int **)malloc(sizeof(int *) * 5);
	if (!(grid->texture))
		error(1);
	grid->texture[0] = (int *)malloc(sizeof(int) * (grid->txt.height_n
				* grid->txt.width_n));
	if (!(grid->texture[0]))
		error(1);
	grid->texture[1] = (int *)malloc(sizeof(int) * (grid->txt.height_s
				* grid->txt.width_s));
	if (!(grid->texture[1]))
		error(1);
	grid->texture[2] = (int *)malloc(sizeof(int) * (grid->txt.height_e
				* grid->txt.width_e));
	if (!(grid->texture[2]))
		error(1);
	grid->texture[3] = (int *)malloc(sizeof(int) * (grid->txt.height_w
				* grid->txt.width_w));
	if (!(grid->texture[3]))
		error(1);
	grid->texture[4] = (int *)malloc(sizeof(int) * (grid->txt.height_spr
				* grid->txt.width_spr));
	if (!(grid->texture[4]))
		error(1);
}
