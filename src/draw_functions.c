#include "so_long.h"

void sl_draw_character(t_game *game, int x, int y)
{
	sl_pixel_fill(game->img, x + 4, y, x + 14, y + 10, 0x00ACB9EF);		  // kafa
	sl_pixel_fill(game->img, x + 8, y + 10, x + 10, y + 13, 0x0000DD00);  // boyun
	sl_pixel_fill(game->img, x, y + 13, x + 2, y + 33, 0x0000DD00);		  // sol-kol
	sl_pixel_fill(game->img, x + 16, y + 13, x + 18, y + 33, 0x0000DD00); // sag-kol
	sl_pixel_fill(game->img, x + 4, y + 13, x + 14, y + 33, 0x0000DD00);  // govde
	sl_pixel_fill(game->img, x + 4, y + 35, x + 7, y + 50, 0x0000DD00);	  // sol-bacak
	sl_pixel_fill(game->img, x + 11, y + 35, x + 14, y + 50, 0x0000DD00); // sag-bacak
	game->curr_x_pos = x;
	game->curr_y_pos = y;
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

void sl_draw_exit(t_game *game, int x, int y)
{
	x -= 3;
	sl_pixel_fill(game->img, x + 9, y + 20, x + 41, y + 30, 0x00FF0000);
	sl_pixel_fill(game->img, x + 25, y + 21, x + 25, y + 23, 0x00FF0000);
	sl_pixel_fill(game->img, x + 23, y + 24, x + 28, y + 24, 0x00FF0000);
	sl_pixel_fill(game->img, x + 23, y + 24, x + 23, y + 27, 0x00FF0000);
	sl_pixel_fill(game->img, x + 23, y + 27, x + 28, y + 27, 0x00FF0000);
	sl_pixel_fill(game->img, x + 25, y + 27, x + 25, y + 30, 0x00FF0000);
	sl_pixel_fill(game->img, x + 9, y + 30, x + 41, y + 30, 0x00FF0000);
}

void sl_pixel_fill(t_data *data, int x_start, int y_start, int x_end, int y_end, int color)
{
	int i = x_start;
	int j = y_start;
	while (j <= y_end)
	{
		while (i <= x_end)
			sl_pixel_put(data, i++, j, color);
		i = x_start;
		j++;
	}
}

void sl_put_wall(t_data *data, int x_start, int y_start) // parametre olarak sadece baslangic konumu gerekiyor cunku her birim kare ayni boyutta olacagi icin bitise gerek yok.
{
	sl_pixel_fill(data, x_start, y_start, (x_start + data->unit_width), (y_start + data->unit_height), 0x00BC4A3C); // unit_width ve height birim karenin boyutlarini temsil ediyor bu fonksiyon ve parametreler sayesinde bir birim kare boyamis oluyoruz. // duvarlar simdilik yesil renk olacak sonra kahverengi rengini bulup degisicez
}
