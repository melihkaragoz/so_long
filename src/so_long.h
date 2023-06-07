/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:06:24 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:06:24 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_game
{
	int		i;
	int		endian;
	int		bppx;
	int		fill_x;
	int		fill_y;
	int		unit_size;
	int		line_length;
	int		map_height;
	int		map_init;
	int		map_width;
	int		curr_x_pos;
	int		curr_y_pos;
	int		curr_score;
	int		step_count;
	int		screen_width;
	int		screen_height;
	int		total_collectible;
	char	*addr;
	char	*map;
	char	*tmp_map;
	char	**arr_map;
	char	*map_path;
	char	**gonna_free;
	char	*step_counter_str;
	void	*mlx;
	void	*win;
	void	*img;
}t_game;

int		exit_with_error(t_game *t, char *msg, int no);
int		sl_is_char_valid(char c);
int		sl_key_handler(int keycode, t_game *t);
int		sl_move_up(t_game *t);
int		sl_move_down(t_game *t);
int		sl_move_right(t_game *t);
int		sl_move_left(t_game *t);
int		sl_is_square_available(t_game *t, char c);
int		check_errors(t_game *t);
int		sl_check_invalid_char(t_game *t);
int		sl_check_walls_is_invalid(t_game *t);
int		sl_check_char_numbers(t_game *t);
int		sl_check_map_shape(t_game *t);
int		sl_check_map_path_valid(char *path);
int		sl_maplen(t_game *t);
void	sl_load_map(t_game *t);
void	sl_init_game(t_game *t);
void	sl_update_map(t_game *t);
void	sl_prepare_window(t_game *t);
void	sl_put_xpm(t_game *t, char *path, int x, int y);
void	sl_move(int key, t_game *t);
void	game_over(t_game *game);
void	sl_draw_collectible(t_game *t);
void	sl_draw_exit(t_game *t);
void	sl_draw_character(t_game *t);
void	sl_draw_wall(t_game *t);
void	sl_print_map_as_ascii(t_game *t);
void	sl_patch_wall(t_game *t);
void	sl_move_success(t_game *t);
void	sl_update_check(t_game *t, char *c);
void	sl_vp_valid_path(t_game *t);
void	sl_vp_find_player(t_game *t);
void	sl_vp_fill(char **strs, int y, int x);
void	sl_vp_find_x(t_game *t, char **strs);
void	sl_vp_find_e(t_game *t, char **strs);
void	sl_vp_fill(char **strs, int y, int x);
void	sl_vp_is_valid(t_game *t, char **strs);
char	**sl_vp_copy(t_game *t);

#endif
