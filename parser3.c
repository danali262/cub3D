#include "cub3d.h"

static void	find_dimension_y(char *map, t_settings *grid, int i)
{
	grid->map_height++;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			grid->map_height++;
		i++;
	}
}

static void	init_map_width(t_settings *grid)
{
	int	i;

	grid->map_width = (int *)malloc(sizeof(int) * grid->map_height);
	if (!grid->map_width)
		error(1);
	i = 0;
	while (i < grid->map_height)
	{
		grid->map_width[i] = 0;
		i++;
	}
}

static void	find_dimension_x(char *map, t_settings *grid, int i)
{
	int	j;

	j = 0;
	while (j < grid->map_height)
	{
		while (map[i] != '\n' && map[i] != '\0')
		{
			if ((map[i] == ' ') || (ft_ismapchar(map[i])))
				grid->map_width[j]++;
			i++;
		}
		j++;
		i++;
	}
}

void	find_map_dimensions(char *map, t_settings *grid, int i)
{
	find_dimension_y(map, grid, i);
	init_map_width(grid);
	find_dimension_x(map, grid, i);
}
