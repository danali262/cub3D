#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
// # include <mlx.h>
# include "mlx/mlx.h"
# include <math.h>
// # include <X11/X.h>

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
# define	ESC			53
# define KEY_A		0
# define KEY_W		13
# define KEY_S		1
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124

typedef struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_left;
	int		key_right;
	int		key_esc;
	double	moveSpeed;
	double	rotSpeed;
}				t_player;

typedef struct s_img
{
	void	*img_old;
	void	*img_new;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_textures
{
	void	*tex_n;
	int		*add_n;
	int		sl_n;
	int		bpp_n;
	int		endian_n;
	int		width_n;
	int		height_n;
	void	*tex_s;
	int		*add_s;
	int		sl_s;
	int		bpp_s;
	int		endian_s;
	int		width_s;
	int		height_s;
	void	*tex_w;
	int		*add_w;
	int		sl_w;
	int		bpp_w;
	int		endian_w;
	int		width_w;
	int		height_w;
	void	*tex_e;
	int		*add_e;
	int		sl_e;
	int		bpp_e;
	int		endian_e;
	int		width_e;
	int		height_e;
	void	*tex_spr;
	int		*add_spr;
	int		sl_spr;
	int		bpp_spr;
	int		endian_spr;
	int		width_spr;
	int		height_spr;
}				t_textures;

typedef struct s_calculate
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		texNum;
	double	wallX;
	int		texX;
	int		texY;
	double	step;
	double	texPos;
	int		color;
	int		wallHeight;
	int		texWidth;
	int		texHeight;
}				t_calculate;

typedef struct s_sprite
{
	int		*sprite0rder;
	double	*spriteDistance;
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		vMoveScreen;
	int		spriteHeight;
	int		drawStartY;
	int		drawEndY;
	int		spriteWidth;
	int		drawStartX;
	int		drawEndX;
	int		stripe;
	int		d;
	int		texX;
	int		texY;
	int		color;
	int		uDiv;
	int		vDiv;
	double	vMove;
}				t_sprite;

typedef struct s_settings
{
	int			*map_width;
	int			map_height;
	int			screen_width;
	int			screen_height;
	int			option;
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	char		*sprite_path;
	int			floor_color;
	int			ceiling_color;
	void		*mlx;
	void		*win;
	int			**buffer;
	int			**texture;
	int			**map;
	double		*zBuffer;
	int			wall_or;
	int			x;
	int			render;
	int			sprite_num;
	double		**sprites;
	int			screenshot;
	int			player_pos;
	int			i;
	t_img		img;
	t_player	plr;
	t_textures	txt;
	t_calculate	calc;
	t_sprite	spr;
}				t_settings;

typedef struct s_flags
{
	int	end_flag;
	int	res_flag;
	int	north_flag;
	int	south_flag;
	int	west_flag;
	int	east_flag;
	int	sprite_flag;
	int	floor_flag;
	int	ceiling_flag;
}				t_flags;

typedef struct s_pair
{
	double	first;
	int		second;
}				t_pair;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_screenshot
{
	int	i;
	int	pad;
}				t_screenshot;

size_t	ft_strlen(const char *s);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strcat(char *src, char *append);
int		ft_atoi(const char *nptr);
int		ft_numlen(int d);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putstr_fd(char *s, int fd);
int		ft_ismapchar(int c);
void	*ft_memset(void *b, int c, size_t len);

void	error(int errnum);
void	input_check(int argc, char **argv, t_settings *grid);
void	check_map(t_settings *grid);
int		check_RFC(char c, char *map, int i);
int		check_dir(char *map, int i);
int		check_dir_spr(char *map, int i);
void	check_flag_RFC(char *map, int i, t_flags *flags);
void	check_flag_dir(char *map, int i, t_flags *flags);

int		handle_res(char *map, int i, t_settings *grid);
int		handle_path(char *map, int i, int option, t_settings *grid);
int		handle_color(char *map, int i, int option, t_settings *grid);

void	assign_color(int option, t_settings *grid, int color);
void	assign_textures(t_settings *grid);
void	assign_sprite_texture(t_settings *grid);
int		assign_info(char *map, t_settings *grid, t_flags *flags);
void	assign_sprites(t_settings *grid);

void	parse_file(char *file_name, t_settings *grid);

void	load_sprite_texture(t_settings *grid);
void	load_textures(t_settings *grid);
void	malloc_textures(t_settings *grid);

void	init_structs(t_settings *grid);
void	init_flags(t_flags *flags);
void	init_buffers(t_settings *grid);
void	init_textures(t_settings *grid);
void	init_sprite_texture(t_settings *grid);
void	init_map(t_settings *grid);
void	init_sprites(t_settings *grid);
void	init_spr(t_sprite *spr);
void	init_color(t_color *rgb);
void	init_screenshot(t_screenshot *screen);

int		main_loop(t_settings *grid);
void	wall_casting(t_settings *grid);
int		calculate_color(int r, int g, int b);
void	player_spawning_orientation(char c, t_settings *grid);
void	sprite_casting(t_settings *grid);

int		key_press(int key, t_settings *grid);
int		key_release(int key, t_settings *grid);
void	key_update(t_settings *grid);
int		exit_hook(t_settings *grid);

void	move_forward(t_settings *grid);
void	move_backward(t_settings *grid);
void	move_left(t_settings *grid);
void	move_right(t_settings *grid);
void	rotate_left(t_settings *grid);
void	rotate_right(t_settings *grid);

void	calculate(t_settings *grid);
void	draw(t_settings *grid);
void	make_screenshot(t_settings *grid);

void	find_player_position(char *map, t_settings *grid, int k);
void	find_map_dimensions(char *map, t_settings *grid, int i);

void	setting_drawing_variables(t_settings *grid);
void	calculate_texNum(t_settings *grid);
void	calculate_wallX(t_settings *grid);
void	texture_casting_x(t_settings *grid);
void	calculate_texX(t_settings *grid);
void	texture_casting_y(t_settings *grid);
void	draw_image(t_settings *grid);
void	new_img(t_settings *grid);
void	exchange_img(t_settings *grid);

void	initialize_spritecasting(t_settings *grid);
void	draw_sprite(t_settings *grid);

#endif