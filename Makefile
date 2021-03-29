NAME = cub3D

SRCS = buffer.c error.c hooks.c hooks2.c hooks3.c init1.c init2.c init3.c input_check.c\
		main_loop.c main.c parser_check.c parser_color.c parser_color2.c parser_path.c\
		parser_res.c parser1.c parser2.c parser3.c path_check.c player.c player2.c\
		raycasting.c raycasting2.c raycasting3.c raycasting4.c raycasting5.c raycasting6.c\
		screenshot.c sprites.c sprites2.c textures.c textures2.c textures3.c textures4.c\
		utilities.c utilities2.c utilities3.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

MLX = libmlx.a

MLXDIR = ./mlx/

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLXDIR)
	cp ./mlx/libmlx.a .
	$(CC) $(OBJS) -Lmlx -lmlx -lz -framework OpenGL -framework Appkit -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(MLXDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX)
	rm -f screenshot.bmp

re: fclean all
