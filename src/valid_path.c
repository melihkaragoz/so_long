/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:06:33 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:06:43 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**sl_vp_copy(t_game *t)
{
	char	**copy_map;

	t->i = -1;
	copy_map = malloc(sizeof(char *) * (t->map_height));
	while (++(t->i) < (t->map_height))
		copy_map[t->i] = ft_strdup(t->arr_map[t->i]);
	return (copy_map);
}

void	sl_vp_fill(char **copy_map, int y, int x)
{
	int	start_x;

	start_x = x;
	while (copy_map[y][x + 1] != '1' && copy_map[y][x + 1] != 'E')
		copy_map[y][(x++) + 1] = '*';
	while (copy_map[y][x - 1] != '1' && copy_map[y][x - 1] != 'E')
		copy_map[y][(x--) - 1] = '*';
	x = start_x;
	while (copy_map[y + 1][x] != '1' && copy_map[y + 1][x] != 'E')
		copy_map[(y++) + 1][x] = '*';
	while (copy_map[y - 1][x] != '1' && copy_map[y - 1][x] != 'E')
		copy_map[(y--) - 1][x] = '*';
}

void	sl_vp_is_valid(t_game *t, char **copy_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < t->map_height)
	{
		j = 0;
		while (j < t->map_width)
		{
			if (copy_map[i][j] == 'C')
				exit_with_error(t, "Collectibles's location is invalid\n", 1);
			j++;
		}
		i++;
	}
	sl_vp_find_e(t, copy_map);
}

void	sl_vp_valid_path(t_game *t)
{
	char	**copy_map;
	int		a;

	copy_map = sl_vp_copy(t);
	t->gonna_free = copy_map;
	a = -1;
	sl_vp_find_player(t);
	copy_map[t->curr_y_pos][t->curr_x_pos] = '*';
	if (copy_map[t->curr_y_pos][t->curr_x_pos + 1] != '1' &&
		copy_map[t->curr_y_pos][t->curr_x_pos + 1] != 'E')
		copy_map[t->curr_y_pos][t->curr_x_pos + 1] = '*';
	if (copy_map[t->curr_y_pos][t->curr_x_pos - 1] != '1' &&
		copy_map[t->curr_y_pos][t->curr_x_pos - 1] != 'E')
		copy_map[t->curr_y_pos][t->curr_x_pos - 1] = '*';
	if (copy_map[t->curr_y_pos + 1][t->curr_x_pos] != '1' &&
		copy_map[t->curr_y_pos + 1][t->curr_x_pos] != 'E')
		copy_map[t->curr_y_pos + 1][t->curr_x_pos] = '*';
	if (copy_map[t->curr_y_pos - 1][t->curr_x_pos] != '1' &&
		copy_map[t->curr_y_pos - 1][t->curr_x_pos] != 'E')
		copy_map[t->curr_y_pos - 1][t->curr_x_pos] = '*';
	while (++a < t->map_height * t->map_width)
		sl_vp_find_x(t, copy_map);
	sl_vp_is_valid(t, copy_map);
}
