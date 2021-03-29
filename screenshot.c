#include "cub3d.h"

static void	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static void	write_bmp_header(t_settings *grid, int fd, int size)
{
	unsigned char	header[54];
	int				n;

	ft_memset(header, 0, 54);
	header[0] = (unsigned char) 'B';
	header[1] = (unsigned char) 'M';
	set_int_in_char(header + 2, size);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	set_int_in_char(header + 18, grid->screen_width);
	set_int_in_char(header + 22, grid->screen_height);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
	n = write(fd, header, 54);
	if (n < 0)
		error(10);
}

static void	init_data(t_settings *grid, t_screenshot *screen)
{
	screen->i = grid->screen_height - 1;
	screen->pad = (4 - (grid->screen_width * 3) % 4) % 4;
}

static void	write_data(t_settings *grid, int fd)
{
	const unsigned char		zero[3] = {0, 0, 0};
	int						j;
	int						n;
	t_screenshot			screen;

	init_screenshot(&screen);
	init_data(grid, &screen);
	while (screen.i >= 0)
	{
		j = 0;
		while (j < grid->screen_width)
		{
			n = write(fd, &grid->buffer[screen.i][j], 3);
			if (n < 0)
				error(10);
			if (screen.pad > 0)
			{
				n = write(fd, &zero, screen.pad);
				if (n < 0)
					error(10);
			}
			j++;
		}
		screen.i--;
	}
}

void	make_screenshot(t_settings *grid)
{
	int	fd;
	int	size;

	size = 54 + 3 * grid->screen_height * grid->screen_width;
	fd = open("screenshot.bmp", (O_WRONLY | O_CREAT | O_TRUNC | O_APPEND),
			00755);
	if (fd < 0)
		error(10);
	write_bmp_header(grid, fd, size);
	write_data(grid, fd);
	exit_hook(grid);
}
