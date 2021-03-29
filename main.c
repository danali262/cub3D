#include "cub3d.h"

static void	game_initialization(t_settings *grid, int argc, char **argv)
{
	init_structs(grid);
	input_check(argc, argv, grid);
	parse_file(argv[1], grid);
	init_buffers(grid);
	init_sprites(grid);
	assign_sprites(grid);
	load_textures(grid);
	init_textures(grid);
	assign_textures(grid);
}

static void	render_image(t_settings *grid)
{
	new_img(grid);
	exchange_img(grid);
	calculate(grid);
	draw(grid);
}

int	main(int argc, char **argv)
{
	t_settings	grid;

	grid.mlx = mlx_init();
	if (!grid.mlx)
		error(1);
	game_initialization(&grid, argc, argv);
	if (grid.screenshot == 1)
	{
		calculate(&grid);
		make_screenshot(&grid);
	}
	else
	{
		grid.win = mlx_new_window(grid.mlx, grid.screen_width,
				grid.screen_height, "cub3D");
		if (!grid.win)
			error(1);
		render_image(&grid);
		mlx_hook(grid.win, 17, 0, &exit_hook, &grid);
		mlx_hook(grid.win, X_EVENT_KEY_PRESS, 0, &key_press, &grid);
		mlx_hook(grid.win, X_EVENT_KEY_RELEASE, 0, &key_release, &grid);
		mlx_loop_hook(grid.mlx, &main_loop, &grid);
		mlx_loop(grid.mlx);
	}
	return (0);
}
