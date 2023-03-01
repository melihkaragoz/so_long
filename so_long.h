#ifndef SO_LONG
#define SO_LONG

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "mlx/mlx.h"

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

void	sl_pixel_put(t_data *data, int x, int y, int color);
void	sl_pixel_fill(t_data *data, int x_start, int y_start, int x_end, int y_end, int color);
void sl_draw_character();
#endif
