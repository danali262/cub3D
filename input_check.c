#include "cub3d.h"

static void	check_argc_2(char **argv)
{
	int		len;
	int		i;
	char	test[5];

	len = ft_strlen(argv[1]);
	len--;
	i = 3;
	while (i >= 0)
	{
		test[i] = argv[1][len];
		i--;
		len--;
	}
	test[4] = '\0';
	if (ft_strncmp(test, ".cub", 5) != 0)
		error(2);
}

static void	check_argc_3(char **argv, t_settings *grid)
{
	if (ft_strncmp(argv[2], "--save", 8) == 0)
	{
		grid->screenshot = 1;
		return ;
	}
	else
		error(3);
}

void	input_check(int argc, char **argv, t_settings *grid)
{
	if (argc == 1)
		error(2);
	if (argc > 3)
		error(4);
	if (argc == 2)
		check_argc_2(argv);
	if (argc == 3)
		check_argc_3(argv, grid);
}
