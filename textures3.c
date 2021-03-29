#include "cub3d.h"

static void	assign_north(t_settings *grid)
{
	int	x;
	int	y;

	y = 0;
	while (y < grid->txt.height_n)
	{
		x = 0;
		while (x < grid->txt.width_n)
		{
			grid->texture[0][grid->txt.width_n * y + x]
				= grid->txt.add_n[grid->txt.width_n * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(grid->mlx, grid->txt.tex_n);
}

static void	assign_south(t_settings *grid)
{
	int	x;
	int	y;

	y = 0;
	while (y < grid->txt.height_s)
	{
		x = 0;
		while (x < grid->txt.width_s)
		{
			grid->texture[1][grid->txt.width_s * y + x]
				= grid->txt.add_s[grid->txt.width_s * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(grid->mlx, grid->txt.tex_s);
}

static void	assign_east(t_settings *grid)
{
	int	x;
	int	y;

	y = 0;
	while (y < grid->txt.height_e)
	{
		x = 0;
		while (x < grid->txt.width_e)
		{
			grid->texture[2][grid->txt.width_e * y + x]
				= grid->txt.add_e[grid->txt.width_e * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(grid->mlx, grid->txt.tex_e);
}

static void	assign_west(t_settings *grid)
{
	int	x;
	int	y;

	y = 0;
	while (y < grid->txt.height_w)
	{
		x = 0;
		while (x < grid->txt.width_w)
		{
			grid->texture[3][grid->txt.width_w * y + x]
				= grid->txt.add_w[grid->txt.width_w * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(grid->mlx, grid->txt.tex_w);
}

void	assign_textures(t_settings *grid)
{
	assign_north(grid);
	assign_south(grid);
	assign_east(grid);
	assign_west(grid);
	assign_sprite_texture(grid);
}
