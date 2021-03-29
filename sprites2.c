#include "cub3d.h"

void	assign_sprites(t_settings *grid)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < grid->map_height)
	{
		j = 0;
		while (j < grid->map_width[i])
		{
			if (grid->map[i][j] == 2)
			{
				grid->sprites[k][0] = j + 0.5;
				grid->sprites[k][1] = i + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
}
