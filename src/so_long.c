#include "so_long.h"

int main(int ac, char **av)
{
	void *mlx;
	void *mlx_win;
	char *map_path;
	t_data img;

	if (ac == 2)
	{
		map_path = av[1];
		img.map_width = get_map_width(map_path);
		img.map_height = get_map_height(map_path);
		img.unit_width = 50;
		img.unit_height = 50;
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, img.unit_width * img.map_width, img.unit_height * img.map_height, "so long");
		img.img = mlx_new_image(mlx, img.unit_width * img.map_width, img.unit_height * img.map_height);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		sl_draw_items(&img, map_path);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
		return (0);
	}
	else
	{
		printf("Couldn't find map path.\n");
		exit(1);
	}
}
