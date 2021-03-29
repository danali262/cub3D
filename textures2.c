#include "cub3d.h"

static void	initialize_north(t_settings *grid)
{
	int	j;

	j = 0;
	while (j < grid->txt.height_n * grid->txt.width_n)
	{
		grid->texture[0][j] = 0;
		j++;
	}
}

static void	initialize_south(t_settings *grid)
{
	int	j;

	j = 0;
	while (j < grid->txt.height_s * grid->txt.width_s)
	{
		grid->texture[1][j] = 0;
		j++;
	}
}

static void	initialize_east(t_settings *grid)
{
	int	j;

	j = 0;
	while (j < grid->txt.height_e * grid->txt.width_e)
	{
		grid->texture[2][j] = 0;
		j++;
	}
}

static void	initialize_west(t_settings *grid)
{
	int	j;

	j = 0;
	while (j < grid->txt.height_w * grid->txt.width_w)
	{
		grid->texture[3][j] = 0;
		j++;
	}
}

void	init_textures(t_settings *grid)
{
	malloc_textures(grid);
	initialize_north(grid);
	initialize_south(grid);
	initialize_east(grid);
	initialize_west(grid);
	init_sprite_texture(grid);
}
