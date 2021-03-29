#include "cub3d.h"

static void	malloc_sprites(t_settings *grid)
{
	int	i;

	grid->sprites = (double **)malloc(sizeof(double *) * grid->sprite_num);
	grid->spr.sprite0rder = (int *)malloc(sizeof(int) * grid->sprite_num);
	grid->spr.spriteDistance = (double *)malloc(sizeof(double)
			* grid->sprite_num);
	if (!(grid->sprites) || !(grid->spr.sprite0rder)
		|| !(grid->spr.spriteDistance))
		error(1);
	i = 0;
	while (i < grid->sprite_num)
	{
		grid->sprites[i] = (double *)malloc(sizeof(double) * 2.00);
		if (!(grid->sprites[i]))
			error(1);
		i++;
	}
}

void	init_sprites(t_settings *grid)
{
	int	i;
	int	j;

	malloc_sprites(grid);
	i = 0;
	while (i < grid->sprite_num)
	{
		j = 0;
		while (j < 2)
		{
			grid->sprites[i][j] = 0;
			j++;
		}
		grid->spr.sprite0rder[i] = 0;
		grid->spr.spriteDistance[i] = 0;
		i++;
	}
}

void	load_sprite_texture(t_settings *grid)
{
	if (grid->sprite_path[ft_strlen(grid->sprite_path) - 1] == 'm')
	{
		grid->txt.tex_spr = mlx_xpm_file_to_image(grid->mlx, grid->sprite_path,
				&grid->txt.width_spr, &grid->txt.height_spr);
		if (!grid->txt.tex_spr)
			error(12);
	}
	else
	{
		grid->txt.tex_spr = mlx_png_file_to_image(grid->mlx, grid->sprite_path,
				&grid->txt.width_spr, &grid->txt.height_spr);
		if (!grid->txt.tex_spr)
			error(12);
	}
	grid->txt.add_spr = (int *)mlx_get_data_addr(grid->txt.tex_spr,
			&grid->txt.bpp_spr, &grid->txt.sl_spr, &grid->txt.endian_spr);
	free(grid->sprite_path);
	if (!grid->txt.tex_spr)
		error(1);
}

void	init_sprite_texture(t_settings *grid)
{
	int	j;

	j = 0;
	while (j < grid->txt.height_w * grid->txt.width_w)
	{
		grid->texture[4][j] = 0;
		j++;
	}
}

void	assign_sprite_texture(t_settings *grid)
{
	int	x;
	int	y;

	y = 0;
	while (y < grid->txt.height_spr)
	{
		x = 0;
		while (x < grid->txt.width_spr)
		{
			grid->texture[4][grid->txt.width_spr * y + x]
				= grid->txt.add_spr[grid->txt.width_spr * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(grid->mlx, grid->txt.tex_spr);
}
