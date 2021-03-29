#include "cub3d.h"

static void	load_north_texture(t_settings *grid)
{
	if (grid->north_path[ft_strlen(grid->north_path) - 1] == 'm')
	{
		grid->txt.tex_n = mlx_xpm_file_to_image(grid->mlx, grid->north_path,
				&grid->txt.width_n, &grid->txt.height_n);
		if (!grid->txt.tex_n)
			error(12);
	}
	else
	{
		grid->txt.tex_n = mlx_png_file_to_image(grid->mlx, grid->north_path,
				&grid->txt.width_n, &grid->txt.height_n);
		if (!grid->txt.tex_n)
			error(12);
	}
	grid->txt.add_n = (int *)mlx_get_data_addr(grid->txt.tex_n,
			&grid->txt.bpp_n, &grid->txt.sl_n, &grid->txt.endian_n);
	free(grid->north_path);
	if (!grid->txt.tex_n)
		error(1);
}

static void	load_south_texture(t_settings *grid)
{
	if (grid->south_path[ft_strlen(grid->south_path) - 1] == 'm')
	{
		grid->txt.tex_s = mlx_xpm_file_to_image(grid->mlx, grid->south_path,
				&grid->txt.width_s, &grid->txt.height_s);
		if (!grid->txt.tex_s)
			error(12);
	}
	else
	{
		grid->txt.tex_s = mlx_png_file_to_image(grid->mlx, grid->south_path,
				&grid->txt.width_s, &grid->txt.height_s);
		if (!grid->txt.tex_s)
			error(12);
	}
	grid->txt.add_s = (int *)mlx_get_data_addr(grid->txt.tex_s,
			&grid->txt.bpp_s, &grid->txt.sl_s, &grid->txt.endian_s);
	free(grid->south_path);
	if (!grid->txt.tex_s)
		error(1);
}

static void	load_east_texture(t_settings *grid)
{
	if (grid->east_path[ft_strlen(grid->east_path) - 1] == 'm')
	{
		grid->txt.tex_e = mlx_xpm_file_to_image(grid->mlx, grid->east_path,
				&grid->txt.width_e, &grid->txt.height_e);
		if (!grid->txt.tex_e)
			error(12);
	}
	else
	{
		grid->txt.tex_e = mlx_png_file_to_image(grid->mlx, grid->east_path,
				&grid->txt.width_e, &grid->txt.height_e);
		if (!grid->txt.tex_e)
			error(12);
	}
	grid->txt.add_e = (int *)mlx_get_data_addr(grid->txt.tex_e,
			&grid->txt.bpp_e, &grid->txt.sl_e, &grid->txt.endian_e);
	free(grid->east_path);
	if (!grid->txt.tex_e)
		error(1);
}

static void	load_west_texture(t_settings *grid)
{
	if (grid->west_path[ft_strlen(grid->west_path) - 1] == 'm')
	{
		grid->txt.tex_w = mlx_xpm_file_to_image(grid->mlx, grid->west_path,
				&grid->txt.width_w, &grid->txt.height_w);
		if (!grid->txt.tex_w)
			error(12);
	}
	else
	{
		grid->txt.tex_w = mlx_png_file_to_image(grid->mlx, grid->west_path,
				&grid->txt.width_w, &grid->txt.height_w);
		if (!grid->txt.tex_w)
			error(12);
	}
	grid->txt.add_w = (int *)mlx_get_data_addr(grid->txt.tex_w,
			&grid->txt.bpp_w, &grid->txt.sl_w, &grid->txt.endian_w);
	free(grid->west_path);
	if (!grid->txt.tex_w)
		error(1);
}

void	load_textures(t_settings *grid)
{
	load_north_texture(grid);
	load_south_texture(grid);
	load_east_texture(grid);
	load_west_texture(grid);
	load_sprite_texture(grid);
}
