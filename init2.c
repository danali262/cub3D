#include "cub3d.h"

static void	malloc_map(t_settings *grid)
{
	int	i;

	grid->map = (int **)malloc(sizeof(int *) * grid->map_height);
	if (!grid->map)
		error(1);
	i = 0;
	while (i < grid->map_height)
	{
		grid->map[i] = (int *)malloc(sizeof(int) * grid->map_width[i]);
		if (!grid->map[i])
			error(1);
		i++;
	}
}

void	init_map(t_settings *grid)
{
	int	i;
	int	j;

	malloc_map(grid);
	i = 0;
	while (i < grid->map_height)
	{
		j = 0;
		while (j < grid->map_width[i])
		{
			grid->map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	init_flags(t_flags *flags)
{
	flags->res_flag = 0;
	flags->north_flag = 0;
	flags->south_flag = 0;
	flags->west_flag = 0;
	flags->east_flag = 0;
	flags->sprite_flag = 0;
	flags->floor_flag = 0;
	flags->ceiling_flag = 0;
	flags->end_flag = 0;
}

void	init_spr(t_sprite *spr)
{
	spr->spriteX = 0;
	spr->spriteY = 0;
	spr->invDet = 0;
	spr->transformX = 0;
	spr->transformY = 0;
	spr->spriteScreenX = 0;
	spr->vMoveScreen = 0;
	spr->spriteHeight = 0;
	spr->drawStartY = 0;
	spr->drawEndY = 0;
	spr->spriteWidth = 0;
	spr->drawStartX = 0;
	spr->drawEndX = 0;
	spr->stripe = 0;
	spr->d = 0;
	spr->texX = 0;
	spr->texY = 0;
	spr->color = 0;
	spr->uDiv = 1;
	spr->vDiv = 1;
	spr->vMove = 0.0;
}
