#include "so_long.h"

int main(int ac, char **av)
{
	void *mlx;
	void *mlx_win;
	char *map_path;
	t_data img;
	t_game game;

	if (ac == 1)
	{
		(void)av;
		map_path = "maps/map2.ber"; // av[1];
		img.map_width = get_map_width(map_path);
		img.map_height = get_map_height(map_path);
		img.unit_width = 50;
		img.unit_height = 50;
		game.curr_x_pos = 0;
		game.curr_y_pos = 0;
		game.curr_score = 0;
		game.screen_width = img.map_width * img.unit_width;
		game.screen_height = img.map_height * img.unit_height;
		game.map_height = img.map_height;
		game.map_width = img.map_width;
		game.map = malloc(sizeof(char) * (game.map_width * game.map_height));
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, img.unit_width * img.map_width, img.unit_height * img.map_height, "so long");
		img.img = mlx_new_image(mlx, img.unit_width * img.map_width, img.unit_height * img.map_height);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		game.mlx = mlx;
		game.win = mlx_win;
		sl_draw_items(&img, &game, map_path);
		/*
		int i = 0;
		while (game.map[i])
		{
			printf("%s",game.map[i]);
			i++;
		}
		*/
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_hook(mlx_win, 2, 1L << 0, sl_key_handler, &game);
		mlx_loop(mlx);
		return (0);
	}
	else
	{
		printf("Couldn't find map path.\n");
		exit(1);
	}
}
