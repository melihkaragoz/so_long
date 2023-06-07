/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:06:28 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:06:29 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_put_xpm(t_game *t, char *path, int x, int y)
{
	void	*xpm;
	int		w;

	w = 50;
	xpm = mlx_xpm_file_to_image(t->mlx, path, &w, &w);
	mlx_put_image_to_window(t->mlx, t->win, xpm, x, y);
}

int	sl_key_handler(int keycode, t_game *t)
{
	if (keycode == 53)
		exit_with_error(t, "game exit with ESC\n", 1);
	else
		sl_move(keycode, t);
	return (0);
}

void	sl_init_game(t_game *t)
{
	t->i = 0;
	t->curr_x_pos = 0;
	t->curr_y_pos = 0;
	t->curr_score = 0;
	t->total_collectible = 0;
	t->step_count = 0;
	t->unit_size = 50;
	t->map_init = 0;
	t->fill_x = 0;
	t->fill_y = 0;
	t->screen_width = t->map_width * t->unit_size;
	t->screen_height = t->map_height * t->unit_size;
	t->arr_map = ft_split(t->map, '\n');
}

void	sl_prepare_window(t_game *t)
{
	mlx_clear_window(t->mlx, t->win);
	free(t->addr);
	free(t->img);
	t->img = mlx_new_image(t->mlx, t->unit_size * t->map_width,
			t->unit_size * t->map_height);
	t->addr = mlx_get_data_addr(t->img, &t->bppx,
			&t->line_length, &t->endian);
}

void	game_over(t_game *game)
{
	ft_putstr_fd("Congrats... The game is over.\n", 1);
	exit_with_error(game, "", 0);
}
