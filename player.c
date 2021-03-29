#include "cub3d.h"

static void	fill_south(t_settings *grid)
{
	grid->plr.dirX = 0;
	grid->plr.dirY = 1;
	grid->plr.planeX = -0.66;
	grid->plr.planeY = 0;
}

static void	fill_north(t_settings *grid)
{
	grid->plr.dirX = 0;
	grid->plr.dirY = -1;
	grid->plr.planeX = 0.66;
	grid->plr.planeY = 0;
}

static void	fill_east(t_settings *grid)
{
	grid->plr.dirX = 1;
	grid->plr.dirY = 0;
	grid->plr.planeX = 0;
	grid->plr.planeY = 0.66;
}

static void	fill_west(t_settings *grid)
{
	grid->plr.dirX = -1;
	grid->plr.dirY = 0;
	grid->plr.planeX = 0;
	grid->plr.planeY = -0.66;
}

void	player_spawning_orientation(char c, t_settings *grid)
{
	if (c == 'S')
		fill_south(grid);
	else if (c == 'N')
		fill_north(grid);
	else if (c == 'E')
		fill_east(grid);
	else if (c == 'W')
		fill_west(grid);
}
