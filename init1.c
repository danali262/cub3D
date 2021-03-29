#include "cub3d.h"

static void	init_player(t_player *game)
{
	game->posX = 0;
	game->posY = 0;
	game->dirX = 0;
	game->dirY = 0;
	game->planeX = 0;
	game->planeY = 0;
	game->key_a = 0;
	game->key_w = 0;
	game->key_s = 0;
	game->key_d = 0;
	game->key_left = 0;
	game->key_right = 0;
	game->key_esc = 0;
	game->moveSpeed = 0.05;
	game->rotSpeed = 0.05;
}

static void	init_settings(t_settings *grid)
{
	grid->map_height = 0;
	grid->screen_width = 0;
	grid->screen_height = 0;
	grid->option = 0;
	grid->north_path = NULL;
	grid->south_path = NULL;
	grid->west_path = NULL;
	grid->east_path = NULL;
	grid->sprite_path = NULL;
	grid->floor_color = 0;
	grid->ceiling_color = 0;
	grid->wall_or = 0;
	grid->x = 0;
	grid->render = 0;
	grid->sprite_num = 0;
	grid->screenshot = 0;
	grid->player_pos = 0;
	grid->i = 0;
}

static void	init_calc2(t_calculate *calc)
{
	calc->lineHeight = 0;
	calc->drawStart = 0;
	calc->drawEnd = 0;
	calc->texNum = 0;
	calc->wallX = 0;
	calc->texX = 0;
	calc->texY = 0;
	calc->step = 0;
	calc->texPos = 0;
	calc->color = 0;
	calc->wallHeight = 0;
	calc->texWidth = 0;
	calc->texHeight = 0;
}

static void	init_calc(t_calculate *calc)
{
	calc->cameraX = 0;
	calc->rayDirX = 0;
	calc->rayDirY = 0;
	calc->mapX = 0;
	calc->mapY = 0;
	calc->sideDistX = 0;
	calc->sideDistY = 0;
	calc->deltaDistX = 0;
	calc->deltaDistY = 0;
	calc->perpWallDist = 0;
	calc->stepX = 0;
	calc->stepY = 0;
	calc->hit = 0;
	calc->side = 0;
	init_calc2(calc);
}

void	init_structs(t_settings *grid)
{
	init_settings(grid);
	init_player(&grid->plr);
	init_calc(&grid->calc);
	init_spr(&grid->spr);
}
