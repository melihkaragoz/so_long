#include "so_long.h"

void sl_print_map(t_game *game)
{
	int i = 0;
	int j = 0;

	while (game->map[i])
	{
		while (j <= ft_strlen(game->map[i]))
		{
			printf("%i|", game->map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

void sl_update_map(t_game *game)
{
	int i;
	int j;

	i = -1;
	j = -1;
	mlx_clear_window(game->mlx, game->win);
	game->img->img = mlx_new_image(game->mlx, game->img->unit_width * game->img->map_width, game->img->unit_height * game->img->map_height);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
	while (game->map[++i])
	{
		while (game->map[i][++j])
		{
			if (sl_is_char_valid(game->map[i][j]))
			{
				if (game->map[i][j] == '1')
					sl_put_wall(game->img, (j * game->unit_width), (i * game->unit_height));
				else if (game->map[i][j] == 'C')
					sl_draw_collectible(game->img, (j * game->unit_width), (i * game->unit_height));
				else if (game->map[i][j] == 'P')
					sl_draw_character(game, (j * game->unit_width), (i * game->unit_height));
				else if (game->map[i][j] == 'E')
					sl_draw_exit(game, (j * game->unit_width), (i * game->unit_height)); // fonksiyonun ici yazilacak;
			}
		}
		j = -1;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}

int get_map_width(char *map_path)
{
	int fd;
	int map_width;
	char *map_tmp_str;

	fd = open(map_path, O_RDONLY);
	map_tmp_str = get_next_line(fd);
	map_width = ft_strlen(map_tmp_str);
	free(map_tmp_str);
	return (map_width)-1;
}

int get_map_height(char *map_path)
{
	int fd;
	int map_height;
	char *s;

	map_height = 0;
	fd = open(map_path, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		map_height++;
		free(s);
		s = get_next_line(fd);
	}
	return (map_height);
}

int sl_is_char_valid(char c)
{
	return ((c == '0') || (c == '1') || (c == 'C') || (c == 'P') || (c == 'E') || (c == '\n'));
}
