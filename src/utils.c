#include "so_long.h"

int sl_key_handler(int keycode, t_game *t)
{
	if (keycode == 53)
	{
		mlx_destroy_window(t->mlx, t->win);
		exit(0);
	}
	else if (keycode == 36)
		mlx_clear_window(t->mlx, t->win);
	else
		sl_move(keycode, t);
	return (0);
}

void sl_pixel_put(t_data *data, int x, int y, int color)
{
	char *d;

	d = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)d = color;
}

void sl_init_items(t_data *data, t_game *game, char *map_path)
{
	char *s;
	int fd;
	int x;
	int y;
	int i;
	int line;

	i = 0;
	x = 0;
	y = 0;
	line = 0;
	fd = open(map_path, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		game->map[line] = ft_strdup(s);
		game->map[line][ft_strlen(s)] = 0;
		while (s[i] && s[i] != '\n')
		{
			if (s[i] == '1')
			{
				sl_put_wall(data, x, y);
				x += data->unit_width;
			}
			else if (s[i] == '0')
			{
				x += data->unit_width;
			}
			else if (s[i] == 'C')
			{
				game->total_collectible++;
				sl_draw_collectible(data, x, y);
				x += data->unit_width;
			}
			else if (s[i] == 'P')
			{
				sl_draw_character(game, x, y);
				game->curr_x_pos = x;
				game->curr_y_pos = y;
				x += data->unit_width;
			}
			else if(s[i] == 'E')
			{
				sl_draw_exit(game,(i * game->unit_width), (line * game->unit_height));
			}
			i++;
		}
		y += data->unit_height;
		x = 0;
		i = 0;
		free(s);
		line++;
		s = get_next_line(fd);
	}
	game->map[game->map_height - 2][game->map_width] = 0;
	game->map[game->map_height - 1] = 0;
}

void sl_update_screen(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	sl_update_map(game);
}
