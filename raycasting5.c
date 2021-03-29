#include "cub3d.h"

static void	assign_order_distance(t_settings *grid)
{
	int	i;

	i = 0;
	while (i < grid->sprite_num)
	{
		grid->spr.sprite0rder[i] = i;
		grid->spr.spriteDistance[i] = ((grid->plr.posX - grid->sprites[i][0])
				* (grid->plr.posX - grid->sprites[i][0]) + (grid->plr.posY
					- grid->sprites[i][1]) * (grid->plr.posY
					- grid->sprites[i][1]));
		i++;
	}
}

static void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

static void	sort_sprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;
	int		i;

	sprites = (t_pair *)malloc(sizeof(t_pair) * amount);
	i = 0;
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_order(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
}

void	sprite_casting(t_settings *grid)
{
	assign_order_distance(grid);
	sort_sprites(grid->spr.sprite0rder, grid->spr.spriteDistance,
		grid->sprite_num);
	grid->i = 0;
	while (grid->i < grid->sprite_num)
	{
		initialize_spritecasting(grid);
		grid->spr.stripe = grid->spr.drawStartX;
		grid->calc.texWidth = grid->txt.width_spr;
		grid->calc.texHeight = grid->txt.height_spr;
		draw_sprite(grid);
		grid->i++;
	}
}
