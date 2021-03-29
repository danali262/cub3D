#include "cub3d.h"

static void	assign_option(char *map, int i, t_settings *grid, t_flags *flags)
{
	check_flag_RFC(map, i, flags);
	check_flag_dir(map, i, flags);
	if (map[i] == 'R' && (check_RFC(map[i], map, i)))
		grid->option = 1;
	else if (map[i] == 'N' && map[i + 1] == 'O' && check_dir(map, i))
		grid->option = 2;
	else if (map[i] == 'S' && map[i + 1] == 'O' && check_dir(map, i))
		grid->option = 3;
	else if (map[i] == 'W' && map[i + 1] == 'E' && check_dir(map, i))
		grid->option = 4;
	else if (map[i] == 'E' && map[i + 1] == 'A' && check_dir(map, i))
		grid->option = 5;
	else if (map[i] == 'S' && map[i + 1] != 'O' && check_dir_spr(map, i))
		grid->option = 6;
	else if ((map[i] == 'F' && (check_RFC(map[i], map, i))))
		grid->option = 7;
	else if ((map[i] == 'C' && (check_RFC(map[i], map, i))))
		grid->option = 8;
	else
	{
		if (map[i] != ' ' && map[i] != '\t' && map[i] != '\n')
			error(9);
	}
}

static void	assign_flag(int option, t_flags *flags)
{
	if (option == 1)
		flags->res_flag = 1;
	else if (option == 2)
		flags->north_flag = 1;
	else if (option == 3)
		flags->south_flag = 1;
	else if (option == 4)
		flags->west_flag = 1;
	else if (option == 5)
		flags->east_flag = 1;
	else if (option == 6)
		flags->sprite_flag = 1;
	else if (option == 7)
		flags->floor_flag = 1;
	else if (option == 8)
		flags->ceiling_flag = 1;
}

static int	parse_info(char *map, int i, t_settings *grid)
{
	if (grid->option == 1)
		i = handle_res(map, i, grid);
	if (grid->option == 2 || grid->option == 3 || grid->option == 4
		|| grid->option == 5 || grid->option == 6)
		i = handle_path(map, i, grid->option, grid);
	if (grid->option == 7 || grid->option == 8)
		i = handle_color(map, i, grid->option, grid);
	return (i);
}

static int	endflag_check(t_flags *flags)
{
	if (flags->ceiling_flag == 1 && flags->east_flag == 1
		&& flags->floor_flag == 1 && flags->north_flag == 1
		&& flags->res_flag == 1 && flags->south_flag == 1
		&& flags->sprite_flag == 1 && flags->west_flag
		== 1)
		return (1);
	return (0);
}

int	assign_info(char *map, t_settings *grid, t_flags *flags)
{
	int			i;

	i = 0;
	while (flags->end_flag == 0 && map[i] != '\0')
	{
		if (ft_isdigit(map[i]) && flags->end_flag == 0
			&& (flags->ceiling_flag == 1 && flags->floor_flag == 1
				&& flags->res_flag == 1))
			error(9);
		while (map[i] == ' ' || map[i] == '\n' || map[i] == '\t')
			i++;
		assign_option(map, i, grid, flags);
		assign_flag(grid->option, flags);
		i = parse_info(map, i, grid);
		flags->end_flag = endflag_check(flags);
		if (grid->option == 0)
			i++;
	}
	if (flags->end_flag == 0)
		error(9);
	return (i);
}
