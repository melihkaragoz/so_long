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
	return (map_width);
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
