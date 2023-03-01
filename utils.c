#include "so_long.h"

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

void sl_draw_character(t_data *img, int x, int y, int size)
{
	sl_pixel_fill(img, 350, 100, 450, 200, 0x00ACB9EF); // kafa
	sl_pixel_fill(img, 380, 200, 420, 230, 0x0000DD00); // boyun
	sl_pixel_fill(img, 270, 230, 290, 400, 0x0000DD00); // sol-kol
	sl_pixel_fill(img, 510, 230, 530, 400, 0x0000DD00); // sag-kol
	sl_pixel_fill(img, 300, 230, 500, 400, 0x0000DD00); // govde
	sl_pixel_fill(img, 365, 400, 380, 500, 0x0000DD00); // sol-bacak
	sl_pixel_fill(img, 415, 400, 430, 500, 0x0000DD00); // sag-bacak
}
