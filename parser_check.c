#include "cub3d.h"

static void	map_chars_check(int c)
{
	if (c != 0 && c != 1 && c != 2 && c != '\n' && c != '\0')
		error (5);
}

static void	check_first_row(t_settings *grid)
{
	int	j;

	j = 0;
	while (j < grid->map_width[0])
	{
		if (grid->map[0][j] != 1)
			error(5);
		j++;
	}
}

static void	check_last_row(t_settings *grid)
{
	int	j;

	j = 0;
	while (j < grid->map_width[grid->map_height - 1])
	{
		if (grid->map[grid->map_height - 1][j] != 1)
			error(5);
		j++;
	}
}

static void	check_between_rows(t_settings *grid)
{
	int	i;

	i = 1;
	while (i < grid->map_height - 1)
	{
		while (grid->map_width[i] == 0)
			i++;
		if (grid->map[i][0] != 1 || grid->map[i][grid->map_width[i] - 1] != 1)
			error(5);
		i++;
	}
}

void	check_map(t_settings *grid)
{
	int	i;
	int	j;

	if (grid->player_pos == 0)
		error(6);
	i = 0;
	while (i < grid->map_height)
	{
		j = 0;
		while (j < grid->map_width[i])
		{
			map_chars_check(grid->map[i][j]);
			j++;
		}
		i++;
	}
	check_first_row(grid);
	check_last_row(grid);
	check_between_rows(grid);
}
