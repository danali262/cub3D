#include "cub3d.h"

static void	player_position(t_settings *grid, char c, double x, double y)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (grid->player_pos == 1)
			error(6);
		grid->player_pos = 1;
		grid->plr.posX = x + 0.5;
		grid->plr.posY = y + 0.5;
		grid->map[(int)y][(int)x] = 0;
		player_spawning_orientation(c, grid);
	}
	else if (c >= '0' && c <= '2')
	{
		if (c == '2')
			grid->sprite_num++;
		grid->map[(int)y][(int)x] = c - '0';
	}
	else if (c == ' ')
		grid->map[(int)y][(int)x] = 1;
	else if (c != ' ')
		error(5);
}

void	find_player_position(char *map, t_settings *grid, int k)
{
	int	x;
	int	y;

	y = 0;
	while (y < grid->map_height)
	{
		x = 0;
		while (x < grid->map_width[y])
		{
			if (ft_ismapchar(map[k]) || map[k] == ' ')
			{
				player_position(grid, map[k], x, y);
				x++;
			}
			k++;
		}
		y++;
	}
}
