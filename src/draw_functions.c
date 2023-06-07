/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:05:28 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:05:29 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_draw_collectible(t_game *t)
{
	if (!(t->map_init))
		t->total_collectible++;
	sl_put_xpm(t, "../assets/cat.xpm", t->fill_x, t->fill_y);
	t->fill_x += 50;
}

void	sl_draw_exit(t_game *t)
{
	sl_put_xpm(t, "../assets/exit.xpm", t->fill_x, t->fill_y);
	t->fill_x += 50;
}

void	sl_draw_character(t_game *t)
{
	sl_put_xpm(t, "../assets/cv.xpm", t->fill_x, t->fill_y);
	t->curr_x_pos = t->fill_x / t->unit_size;
	t->curr_y_pos = t->fill_y / t->unit_size;
	t->fill_x += 50;
}

void	sl_draw_wall(t_game *t)
{
	sl_put_xpm(t, "../assets/wall.xpm", t->fill_x, t->fill_y);
	t->fill_x += 50;
}

int	sl_check_map_path_valid(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("invalid map path\n", 2);
		exit(1);
	}
	return (0);
}
