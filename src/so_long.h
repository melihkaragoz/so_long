#ifndef SO_LONG
#define SO_LONG

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../mlx/mlx.h"
#include "../gnl/get_next_line.h"

typedef struct s_data
{
	void *img;
	int map_width;
	int map_height;
	int screen_width;
	int screen_height;
	int unit_width;
	int unit_height;
	int **walls;
	int bits_per_pixel;
	int line_length;
	int endian;
	char *addr;
} t_data;

typedef struct s_game
{
	void *mlx;
	void *win;
	char *line;
	char **map;
	int curr_x_pos;
	int curr_y_pos;
	int curr_score;
	int	step_count;
	int total_collectible;
	int screen_width;
	int screen_height;
	int unit_width;
	int unit_height;
	int map_height;
	int map_width;
	t_data *img;
} t_game;

void sl_pixel_put(t_data *data, int x, int y, int color);
void sl_pixel_fill(t_data *data, int x_start, int y_start, int x_end, int y_end, int color);
void sl_draw_character(t_game *game, int x, int y);
void sl_put_wall(t_data *data, int x_start, int y_start);
void sl_init_items(t_data *data, t_game *game, char *map_path);
void sl_draw_collectible(t_data *img, int x, int y);
void sl_draw_exit(t_game *game, int x, int y);
void sl_update_screen(t_game *game);
void sl_update_map(t_game *game);
void sl_move(int key, t_game *t);
void sl_print_map(t_game *game);
int sl_move_up(t_game *t);
int sl_move_down(t_game *t);
int sl_move_left(t_game *t);
int sl_move_right(t_game *t);
int sl_is_char_valid(char c);
int get_map_width(char *map_path);
int get_map_height(char *map_path);
int sl_key_handler(int keycode, t_game *t);
char *ft_strdup(char *str);
char	*ft_itoa(int n);
#endif
