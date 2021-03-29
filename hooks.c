#include "cub3d.h"

static void	free_memory(t_settings *grid)
{
	int	i;

	free(grid->spr.sprite0rder);
	free(grid->spr.spriteDistance);
	free(grid->map_width);
	i = 0;
	while (i < grid->screen_height)
	{
		free(grid->buffer[i]);
		i++;
	}
	free(grid->buffer);
	i = 0;
	while (i < 5)
	{
		free(grid->texture[i]);
		i++;
	}
	free(grid->texture);
	i = 0;
	while (i < grid->map_height)
	{
		free(grid->map[i]);
		i++;
	}
}

int	exit_hook(t_settings *grid)
{
	int	i;

	free_memory(grid);
	free(grid->map);
	free(grid->zBuffer);
	i = 0;
	while (i < grid->sprite_num)
	{
		free(grid->sprites[i]);
		i++;
	}
	free(grid->sprites);
	exit(0);
}

int	key_press(int key, t_settings *grid)
{
	if (key == ESC)
		exit_hook(grid);
	else if (key == KEY_W)
		grid->plr.key_w = 1;
	else if (key == KEY_A)
		grid->plr.key_a = 1;
	else if (key == KEY_S)
		grid->plr.key_s = 1;
	else if (key == KEY_D)
		grid->plr.key_d = 1;
	else if (key == KEY_LEFT)
		grid->plr.key_left = 1;
	else if (key == KEY_RIGHT)
		grid->plr.key_right = 1;
	return (0);
}

int	key_release(int key, t_settings *grid)
{
	if (key == ESC)
		exit_hook(grid);
	else if (key == KEY_W)
		grid->plr.key_w = 0;
	else if (key == KEY_A)
		grid->plr.key_a = 0;
	else if (key == KEY_S)
		grid->plr.key_s = 0;
	else if (key == KEY_D)
		grid->plr.key_d = 0;
	else if (key == KEY_LEFT)
		grid->plr.key_left = 0;
	else if (key == KEY_RIGHT)
		grid->plr.key_right = 0;
	return (0);
}
