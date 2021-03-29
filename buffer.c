#include "cub3d.h"

static void	malloc_buffers(t_settings *grid)
{
	int	i;

	grid->buffer = (int **)malloc(sizeof(int *) * grid->screen_height);
	if (!(grid->buffer))
		error(1);
	grid->zBuffer = (double *)malloc(sizeof(double) * grid->screen_width);
	if (!(grid->zBuffer))
		error(1);
	i = 0;
	while (i < grid->screen_height)
	{
		grid->buffer[i] = (int *)malloc(sizeof(int) * grid->screen_width);
		if (!(grid->buffer[i]))
			error(1);
		i++;
	}
}

void	init_buffers(t_settings *grid)
{
	int	i;
	int	j;

	malloc_buffers(grid);
	i = 0;
	while (i < grid->screen_height)
	{
		j = 0;
		while (j < grid->screen_width)
		{
			grid->buffer[i][j] = 0;
			grid->zBuffer[j] = 0;
			j++;
		}
		i++;
	}
}
