#include "cub3d.h"

int	check_RFC(char c, char *map, int i)
{
	if ((map[i + 1] == ' ' && (map[i - 1] == '\n' || map[i - 1] == ' '))
		|| (map[i] == c && i == 0 && map[i + 1] == ' '))
		return (1);
	return (0);
}

int	check_dir(char *map, int i)
{
	if (map[i + 2] == ' ' && (map[i - 1] == '\n' || map[i - 1] == ' '
			|| map[i - 1] == '\t' || i == 0 ))
		return (1);
	return (0);
}

int	check_dir_spr(char *map, int i)
{
	if (map[i + 1] == ' ' && (map[i - 1] == '\n' || map[i - 1] == ' '
			|| map[i - 1] == '\t' || i == 0 ))
		return (1);
	return (0);
}

void	check_flag_RFC(char *map, int i, t_flags *flags)
{
	if (map[i] == 'R' && (check_RFC(map[i], map, i)))
	{
		if (flags->res_flag)
			error(9);
	}
	else if (map[i] == 'F' && (check_RFC(map[i], map, i)))
	{
		if (flags->floor_flag)
			error(9);
	}
	else if (map[i] == 'C' && (check_RFC(map[i], map, i)))
	{
		if (flags->ceiling_flag)
			error(9);
	}
}

void	check_flag_dir(char *map, int i, t_flags *flags)
{
	if (map[i] == 'N' && map[i + 1] == 'O' && check_dir(map, i))
	{
		if (flags->north_flag)
			error(9);
	}
	else if (map[i] == 'S' && map[i + 1] == 'O' && check_dir(map, i))
	{
		if (flags->south_flag)
			error(9);
	}
	else if (map[i] == 'W' && map[i + 1] == 'E' && check_dir(map, i))
	{
		if (flags->west_flag)
			error(9);
	}
	else if (map[i] == 'E' && map[i + 1] == 'A' && check_dir(map, i))
	{
		if (flags->east_flag)
			error(9);
	}
	else if (map[i] == 'S' && map[i + 1] != 'O' && check_dir_spr(map, i))
	{
		if (flags->sprite_flag)
			error(9);
	}
}
