#include "cub3d.h"

static void	parse_map(char *map, t_settings *grid)
{
	int		i;
	int		k;
	t_flags	flags;

	init_flags(&flags);
	i = assign_info(map, grid, &flags);
	while (map[i] == '\n' || map[i] == ' ')
		i++;
	if (ft_isalpha(map[i]))
		error(5);
	if (map[i] == '0' || map[i] == '1' || map[i] == '2')
	{
		while (map[i] != '\n')
			i--;
	}
	i++;
	k = i;
	find_map_dimensions(map, grid, i);
	init_map(grid);
	find_player_position(map, grid, k);
	check_map(grid);
}

static char	*read_file(int fd, char *map)
{
	char	*buf;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		buf = (char *)malloc(sizeof(char) * 1001);
		if (!buf)
			error(1);
		ret = read(fd, buf, 1000);
		if (ret < 0)
			error(2);
		buf[ret] = '\0';
		map = ft_strcat(map, buf);
		if (!map)
			error(1);
	}
	return (map);
}

void	parse_file(char *file_name, t_settings *grid)
{
	int		fd;
	char	*map;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error(2);
	map = ft_strdup("");
	if (!map)
		error(1);
	map = read_file(fd, map);
	parse_map(map, grid);
	free(map);
}
