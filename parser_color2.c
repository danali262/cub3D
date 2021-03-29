#include "cub3d.h"

int	calculate_color(int r, int g, int b)
{
	return (((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF));
}

void	assign_color(int option, t_settings *grid, int color)
{
	if (option == 7)
		grid->floor_color = color;
	else if (option == 8)
		grid->ceiling_color = color;
}
