#include "cub3d.h"

static char	*copy_path(char *src, char *dst, int len, int k)
{
	int	j;

	j = 0;
	while (j < len)
	{
		dst[j] = src[k];
		j++;
		k++;
	}
	dst[j] = '\0';
	return (dst);
}

static void	assign_path(int option, char *path, t_settings *grid)
{
	if (option == 2)
		grid->north_path = ft_strdup(path);
	else if (option == 3)
		grid->south_path = ft_strdup(path);
	else if (option == 4)
		grid->west_path = ft_strdup(path);
	else if (option == 5)
		grid->east_path = ft_strdup(path);
	else if (option == 6)
		grid->sprite_path = ft_strdup(path);
}

int	handle_path(char *map, int i, int option, t_settings *grid)
{
	int		len;
	char	*path;
	int		k;

	len = 0;
	while (ft_isalpha(map[i]))
		i++;
	while (map[i] == ' ' || map[i] == '\t')
		i++;
	while (map[i] != '\n' && map[i] != ' ' && map[i] != '\t')
	{
		len++;
		i++;
	}
	path = (char *)malloc(sizeof(char) * (len + 1));
	k = i - len;
	path = copy_path(map, path, len, k);
	assign_path(option, path, grid);
	free(path);
	return (i);
}
