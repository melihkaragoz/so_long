#include "so_long.h"

int main(int ac, char **av)
{
	void *mlx;
	void *mlx_win;
	char *map_path;
	t_data img;
	t_game	game;

	if (ac == 2)
	{
		map_path = av[1];
		img.map_width = get_map_width(map_path);
		img.map_height = get_map_height(map_path);
		img.unit_width = 50;
		img.unit_height = 50;
		game.curr_x_pos = 0;
		game.curr_y_pos = 0;
		game.curr_score = 0;
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, img.unit_width * img.map_width, img.unit_height * img.map_height, "so long");
		img.img = mlx_new_image(mlx, img.unit_width * img.map_width, img.unit_height * img.map_height);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		game.mlx = mlx;
		game.win = mlx_win;
		sl_draw_items(&img, &game, map_path);
		//printf("char x : %d\nchar y : %d\n",game.curr_x_pos,game.curr_y_pos); // karakterin baslangic konumunu yazdir.
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
