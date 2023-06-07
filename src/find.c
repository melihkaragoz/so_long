/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:06:06 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:06:07 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_vp_find_player(t_game *t)
{
	int	i;
	int	j;

	i = -1;
	while (++i < t->map_height)
	{
		j = -1;
		while (++j < t->map_width)
		{
			if (t->arr_map[i][j] == 'P')
			{
				t->curr_y_pos = i;
				t->curr_x_pos = j;
			}
		}
	}
}

void	sl_vp_find_x(t_game *t, char **copy_map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < t->map_height)
	{
		j = -1;
		while (++j < t->map_width)
		{
			if (copy_map[i][j] == '*')
				sl_vp_fill(copy_map, i, j);
		}
	}
}

void	sl_vp_find_e(t_game *t, char **copy_map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < t->map_height)
	{
		j = -1;
		while (++j < t->map_width)
		{
			if (copy_map[i][j] == 'E')
			{
				if (copy_map[i][j + 1] != '*' && copy_map[i][j - 1] != '*' && \
					copy_map[i + 1][j] != '*' && copy_map[i - 1][j] != '*')
					exit_with_error(t, "map's path is invalid\n", 1);
			}
		}
	}
}
