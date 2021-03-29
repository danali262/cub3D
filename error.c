#include "cub3d.h"

static void	error2(int errnum)
{
	if (errnum == 11)
		ft_putstr_fd("Please provide all the necessary information.\n", 2);
	else if (errnum == 12)
		ft_putstr_fd("Texture file does not exist.\n", 2);
	else
		ft_putstr_fd("Please check your input.\n", 2);
	exit (0);
}

void	error(int errnum)
{
	ft_putstr_fd("Error\n", 2);
	if (errnum == 0)
		ft_putstr_fd("Error reading the .cub file.\n", 2);
	else if (errnum == 1)
		ft_putstr_fd("Memory allocation error.\n", 2);
	else if (errnum == 2)
		ft_putstr_fd("Please provide a valid .cub file as an argument.\n", 2);
	else if (errnum == 3)
		ft_putstr_fd("Please provide a valid second argument.\n", 2);
	else if (errnum == 4)
		ft_putstr_fd("Too many arguments provided.\n", 2);
	else if (errnum == 5)
		ft_putstr_fd("Map contains invalid characters.\n", 2);
	else if (errnum == 6)
		ft_putstr_fd("Invalid player position.\n", 2);
	else if (errnum == 7)
		ft_putstr_fd("Please provide a valid floor/ceiling color.\n", 2);
	else if (errnum == 8)
		ft_putstr_fd("Please provide a valid resolution.\n", 2);
	else if (errnum == 9)
		ft_putstr_fd("Please provide valid map components.\n", 2);
	else if (errnum == 10)
		ft_putstr_fd("Screenshot failed.\n", 2);
	error2(errnum);
}
