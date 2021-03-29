#include "cub3d.h"

static int	handle_r(char *map, int i, t_color *rgb)
{
	int	j;

	while (map[i] == ' ')
		i++;
	j = i;
	while (map[j] != ',')
	{
		if (ft_isdigit(map[j]) == 0 && map[j] != ' ' && map[j] != '\t')
			error(7);
		j++;
	}
	rgb->r = ft_atoi(&map[i]);
	i += ft_numlen(rgb->r);
	while (map[i] == ' ')
		i++;
	if (map[i] == ',')
		i++;
	else
		error(7);
	return (i);
}

static int	handle_g(char *map, int i, t_color *rgb)
{
	int	j;

	while (map[i] == ' ')
		i++;
	j = i;
	while (map[j] != ',')
	{
		if (ft_isdigit(map[j]) == 0 && map[j] != ' ' && map[j] != '\t')
			error(7);
		j++;
	}
	rgb->g = ft_atoi(&map[i]);
	i += ft_numlen(rgb->g);
	while (map[i] == ' ')
		i++;
	if (map[i] == ',')
		i++;
	else
		error(7);
	return (i);
}

static int	handle_b(char *map, int i, t_color *rgb)
{
	int	j;

	while (map[i] == ' ')
		i++;
	j = i;
	if (map[j] == '\n')
		error(7);
	while (map[j] != '\n')
	{
		if (ft_isdigit(map[j]) == 0 && map[j] != ' ' && map[j] != '\t')
			error(7);
		j++;
	}
	rgb->b = ft_atoi(&map[i]);
	i += ft_numlen(rgb->b);
	return (i);
}

int	handle_color(char *map, int i, int option, t_settings *grid)
{
	t_color	rgb;
	int		color;

	while (ft_isalpha(map[i]))
		i++;
	init_color(&rgb);
	i = handle_r(map, i, &rgb);
	i = handle_g(map, i, &rgb);
	i = handle_b(map, i, &rgb);
	if (rgb.r < 0 || rgb.r > 255 || rgb.g < 0 || rgb.g > 255 || rgb.b < 0
		|| rgb.b > 255)
		error(7);
	color = calculate_color(rgb.r, rgb.g, rgb.b);
	assign_color(option, grid, color);
	return (i);
}
