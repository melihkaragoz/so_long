#include "so_long.h"

void sl_print_map(t_game *game)
{
	int i = 0;
	int	j = 0;

	game->map[6][19] = 0;

	while (game->map[i])
	{
		while (game->map[i][j])
		{
			printf("%c|",game->map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

char *ft_strdup(char *str)
{
	char *c;
	int i;

	i = 0;
	if (!str)
		return (NULL);
	c = (char *)malloc(ft_strlen(str) + 1);
	if (!c)
		return (NULL);
	while (str[i])
	{
		c[i] = str[i];
		i++;
	}
	c[i] = 0;
	return (c);
}

int sl_key_handler(int keycode, t_game *t)
{
	// printf("code : %d\n", keycode);
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

void sl_move(int key, t_game *t)
{
	if (key == 13 || key == 126)
		sl_move_up(t);
	else if (key == 1 || key == 125)
		sl_move_down(t);
	else if (key == 0 || key == 123)
		sl_move_left(t);
	else if (key == 2 || key == 124)
		sl_move_right(t);
	printf("konum degisti, yeni konum = x: %d, y: %d\n", t->curr_x_pos, t->curr_y_pos);
}

void sl_move_up(t_game *t)
{
	(void)t;
	if (t->curr_y_pos >= 50)
	{
		t->curr_y_pos -= 50;
		sl_print_map(t);
	}
	else
		printf("height-up overflow");
}

void sl_move_down(t_game *t)
{
	(void)t;
	if (t->curr_y_pos <= t->screen_height - 50)
	{
		t->curr_y_pos += 50;
		mlx_clear_window(t->mlx, t->win); // ekran temizlendi
										  // ekran yeniden cizilecek
	}
	else
		printf("height-down overflow");
}

void sl_move_left(t_game *t)
{
	(void)t;
	if (t->curr_x_pos >= 50)
	{
		t->curr_x_pos -= 50;
		sl_update_screen(t);
	}
	else
		printf("width-left overflow");
}

void sl_move_right(t_game *t)
{
	(void)t;
	if (t->curr_x_pos <= t->screen_width - 50)
	{
		t->curr_x_pos += 50;
		mlx_clear_window(t->mlx, t->win); // ekran temizlendi
										  // ekran yeniden cizilecek
	}
	else
		printf("width-right overflow");
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

void sl_pixel_put(t_data *data, int x, int y, int color)
{
	char *d;

	d = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)d = color;
}

void sl_pixel_fill(t_data *data, int x_start, int y_start, int x_end, int y_end, int color)
{
	int i = x_start;
	int j = y_start;
	while (j <= y_end)
	{
		while (i <= x_end)
		{
			sl_pixel_put(data, i, j, color);
			i++;
		}
		i = x_start;
		j++;
	}
}

void sl_put_wall(t_data *data, int x_start, int y_start) // parametre olarak sadece baslangic konumu gerekiyor cunku her birim kare ayni boyutta olacagi icin bitise gerek yok.
{
	sl_pixel_fill(data, x_start, y_start, (x_start + data->unit_width), (y_start + data->unit_height), 0x00BC4A3C); // unit_width ve height birim karenin boyutlarini temsil ediyor bu fonksiyon ve parametreler sayesinde bir birim kare boyamis oluyoruz. // duvarlar simdilik yesil renk olacak sonra kahverengi rengini bulup degisicez
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
		while (s[i] && s[i] != '\n')
		{
			if (s[i] == '1')
			{
				sl_put_wall(data, x, y);
				x += data->unit_width;
			}
			else if (s[i] == '0' || s[i] == 'E')
			{
				x += data->unit_width;
			}
			else if (s[i] == 'C')
			{
				sl_draw_collectible(data, x, y);
				x += data->unit_width;
			}
			else if (s[i] == 'P')
			{
				sl_draw_character(data, x, y);
				game->curr_x_pos = x;
				game->curr_y_pos = y;
				x += data->unit_width;
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
	game->map[game->map_height-2][game->map_width] = 0;
	game->map[game->map_height-1] = 0;
}

void sl_update_screen(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
}

void sl_draw_character(t_data *img, int x, int y)
{																	// karakter boyu 18x50
	sl_pixel_fill(img, x + 4, y, x + 14, y + 10, 0x00ACB9EF);		// kafa
	sl_pixel_fill(img, x + 8, y + 10, x + 10, y + 13, 0x0000DD00);	// boyun
	sl_pixel_fill(img, x, y + 13, x + 2, y + 33, 0x0000DD00);		// sol-kol
	sl_pixel_fill(img, x + 16, y + 13, x + 18, y + 33, 0x0000DD00); // sag-kol
	sl_pixel_fill(img, x + 4, y + 13, x + 14, y + 33, 0x0000DD00);	// govde
	sl_pixel_fill(img, x + 4, y + 35, x + 7, y + 50, 0x0000DD00);	// sol-bacak
	sl_pixel_fill(img, x + 11, y + 35, x + 14, y + 50, 0x0000DD00); // sag-bacak
}

void sl_draw_collectible(t_data *img, int x, int y)
{
	x -= 3;
	sl_pixel_fill(img, x + 9, y + 20, x + 41, y + 30, 0x0000DD00);
	sl_pixel_fill(img, x + 25, y + 21, x + 25, y + 23, 0x00474646);
	sl_pixel_fill(img, x + 23, y + 24, x + 28, y + 24, 0x00474646);
	sl_pixel_fill(img, x + 23, y + 24, x + 23, y + 27, 0x00474646);
	sl_pixel_fill(img, x + 23, y + 27, x + 28, y + 27, 0x00474646);
	sl_pixel_fill(img, x + 25, y + 27, x + 25, y + 30, 0x00474646);
	sl_pixel_fill(img, x + 9, y + 30, x + 41, y + 30, 0x0000DD00);
}
