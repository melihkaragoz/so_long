#include "so_long.h"

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
	sl_pixel_fill(data, x_start, y_start, (x_start + data->unit_width), (y_start + data->unit_height), 0x0000FF00); // unit_width ve height birim karenin boyutlarini temsil ediyor bu fonksiyon ve parametreler sayesinde bir birim kare boyamis oluyoruz. // duvarlar simdilik yesil renk olacak sonra kahverengi rengini bulup degisicez
}

void sl_draw_walls(t_data *data, char *map_path)
{
	char *s;
	int fd;
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	y = 0;
	(void)x;
	(void)y;
	(void)data;
	fd = open(map_path, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("%s\n", s);
		while (s[i] && s[i] != '\n')
		{
			printf("char = %c\n", s[i]);
			if (s[i] == '1')
			{
				sl_put_wall(data, x, y);
				x += data->unit_width;
			}
			else if (s[i] == '0' || s[i] == 'C')
			{
				x += data->unit_width;
			}
			else if (s[i] == 'P')
			{
				sl_draw_character(data, x, y);
				x += data->unit_width;
			}

			i++;
		}
		y += data->unit_height;
		x = 0;
		i = 0;
		free(s);
		s = get_next_line(fd);
	}
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
