/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:06:16 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:06:16 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_move(int key, t_game *t)
{
	t->i = 0;
	if (key == 13 || key == 126)
		t->i = sl_move_up(t);
	else if (key == 1 || key == 125)
		t->i = sl_move_down(t);
	else if (key == 0 || key == 123)
		t->i = sl_move_left(t);
	else if (key == 2 || key == 124)
		t->i = sl_move_right(t);
	else
		return ;
	if (t->i)
	{
		sl_move_success(t);
		sl_update_map(t);
	}
}

int	sl_move_up(t_game *t)
{
	if (sl_is_square_available(t, t->arr_map[t->curr_y_pos - 1][t->curr_x_pos]))
	{
		if (t->arr_map[t->curr_y_pos - 1][t->curr_x_pos] == 'C')
			t->curr_score++;
		if (t->curr_score == t->total_collectible && \
			t->arr_map[t->curr_y_pos - 1][t->curr_x_pos] == 'E')
			game_over(t);
		t->arr_map[t->curr_y_pos - 1][t->curr_x_pos] = 'P';
		t->arr_map[t->curr_y_pos][t->curr_x_pos] = '0';
		t->curr_y_pos--;
		return (1);
	}
	return (0);
}

int	sl_move_down(t_game *t)
{
	if (sl_is_square_available(t, t->arr_map[t->curr_y_pos + 1][t->curr_x_pos]))
	{
		if (t->arr_map[t->curr_y_pos + 1][t->curr_x_pos] == 'C')
			t->curr_score++;
		if (t->curr_score == t->total_collectible && \
			t->arr_map[t->curr_y_pos + 1][t->curr_x_pos] == 'E')
			game_over(t);
		t->arr_map[t->curr_y_pos + 1][t->curr_x_pos] = 'P';
		t->arr_map[t->curr_y_pos][t->curr_x_pos] = '0';
		t->curr_y_pos++;
		return (1);
	}
	return (0);
}

int	sl_move_left(t_game *t)
{
	if (sl_is_square_available(t, t->arr_map[t->curr_y_pos][t->curr_x_pos - 1]))
	{
		if (t->arr_map[t->curr_y_pos][t->curr_x_pos - 1] == 'C')
			t->curr_score++;
		if (t->curr_score == t->total_collectible && \
			t->arr_map[t->curr_y_pos][t->curr_x_pos - 1] == 'E')
			game_over(t);
		t->arr_map[t->curr_y_pos][t->curr_x_pos - 1] = 'P';
		t->arr_map[t->curr_y_pos][t->curr_x_pos] = '0';
		t->curr_x_pos--;
		return (1);
	}
	return (0);
}

int	sl_move_right(t_game *t)
{
	if (sl_is_square_available(t, t->arr_map[t->curr_y_pos][t->curr_x_pos + 1]))
	{
		if (t->arr_map[t->curr_y_pos][t->curr_x_pos + 1] == 'C')
			t->curr_score++;
		if (t->curr_score == t->total_collectible && \
			t->arr_map[t->curr_y_pos][t->curr_x_pos + 1] == 'E')
			game_over(t);
		t->arr_map[t->curr_y_pos][t->curr_x_pos + 1] = 'P';
		t->arr_map[t->curr_y_pos][t->curr_x_pos] = '0';
		t->curr_x_pos++;
		return (1);
	}
	return (0);
}
