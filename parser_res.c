#include "cub3d.h"

static int	handle_res_width(char *map, int i, t_settings *grid)
{
	int	j;
	int	sizex;
	int	sizey;

	sizex = 0;
	sizey = 0;
	while (map[i] == ' ')
		i++;
	j = i;
	while (map[j] != '\n')
	{
		if (ft_isdigit(map[j]) == 0 && map[j] != ' ')
			error(8);
		j++;
	}
	grid->screen_width = ft_atoi(&map[i]);
	if (grid->screen_width < 0)
		error(8);
	i += ft_numlen(grid->screen_width);
	mlx_get_screen_size(grid->mlx, &sizex, &sizey);
	if (grid->screen_width > sizex)
		grid->screen_width = sizex;
	return (i);
}

static int	handle_res_height(char *map, int i, t_settings *grid)
{
	int	sizex;
	int	sizey;

	sizex = 0;
	sizey = 0;
	while (map[i] == ' ')
		i++;
	if (map[i] == '\n')
		error(8);
	grid->screen_height = ft_atoi(&map[i]);
	if (grid->screen_height < 0)
		error(8);
	i += ft_numlen(grid->screen_height);
	mlx_get_screen_size(grid->mlx, &sizex, &sizey);
	if (grid->screen_height > sizey)
		grid->screen_height = sizey;
	if (grid->screen_height == 0 || grid->screen_width == 0)
		error(8);
	while (map[i] != '\n')
	{
		if (map[i] != ' ' && map[i] != '\t')
			error(8);
		i++;
	}
	return (i);
}

int	handle_res(char *map, int i, t_settings *grid)
{
	while (ft_isalpha(map[i]))
		i++;
	i = handle_res_width(map, i, grid);
	i = handle_res_height(map, i, grid);
	return (i);
}
