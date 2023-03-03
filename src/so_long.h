#ifndef SO_LONG
#define SO_LONG

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../mlx/mlx.h"
#include "../gnl/get_next_line.h"

typedef struct s_data
{
	void	*img;
	int		map_width;
	int		map_height;
	int		screen_width;
	int		screen_height;
	int		unit_width;
	int		unit_height;
	int		**walls;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

void	sl_pixel_put(t_data *data, int x, int y, int color);
void	sl_pixel_fill(t_data *data, int x_start, int y_start, int x_end, int y_end, int color);
void	sl_draw_character(t_data *img, int x, int y);
void	sl_put_wall(t_data *data, int x_start, int y_start);
void	sl_draw_items(t_data *data, char *map_path);
void	sl_draw_collectible(t_data *img, int x, int y);
int		get_map_width(char *map_path);
int		get_map_height(char *map_path);
#endif
