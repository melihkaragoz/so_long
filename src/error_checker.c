/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:05:57 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:05:57 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_errors(t_game *t)
{
	if (sl_check_invalid_char(t) || sl_check_char_numbers(t) || \
		t->map[ft_strlen(t->map) - 1] == 10 || sl_check_map_shape(t) || \
			sl_check_walls_is_invalid(t))
	{
		ft_putstr_fd("invalid map\n", 2);
		return (1);
	}
	return (0);
}

int	sl_check_invalid_char(t_game *t)
{
	int		i;
	char	c;

	i = 0;
	while (t->map[i])
	{
		c = t->map[i++];
		if (!(c == '1' || c == '0' || c == 'E' || \
			c == 'C' || c == 'P' || c == '\n'))
			return (1);
	}
	return (0);
}

int	sl_check_walls_is_invalid(t_game *t)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (t->arr_map[0][j])
	{
		if (t->arr_map[0][j++] != '1')
			return (1);
	}
	j = 0;
	while (t->arr_map[t->map_height - 1][j])
	{
		if (t->arr_map[t->map_height - 1][j++] != '1')
			return (1);
	}
	while (t->arr_map[++i])
	{
		if (t->arr_map[i][0] != '1' || t->arr_map[i][t->map_width - 1] != '1')
			return (1);
	}
	return (0);
}

int	sl_check_char_numbers(t_game *t)
{
	int	i;
	int	j;
	int	c_count;
	int	e_count;
	int	p_count;

	i = -1;
	j = -1;
	c_count = 0;
	e_count = 0;
	p_count = 0;
	while (t->arr_map[++i])
	{
		while (t->arr_map[i][++j])
		{
			if (t->arr_map[i][j] == 'C')
				c_count++;
			else if (t->arr_map[i][j] == 'E')
				e_count++;
			else if (t->arr_map[i][j] == 'P')
				p_count++;
		}
		j = 0;
	}
	return (p_count > 1 || e_count != 1 || c_count < 1);
}

void	sl_move_success(t_game *t)
{
	free(t->map);
	t->map = malloc(1);
	t->i = 0;
	while (t->arr_map[t->i])
	{
		t->tmp_map = ft_strjoin(t->map, t->arr_map[(t->i)++]);
		free(t->map);
		t->map = t->tmp_map;
		free(t->tmp_map);
		t->tmp_map = ft_strjoin(t->map, "\n");
		t->map = t->tmp_map;
	}
}
