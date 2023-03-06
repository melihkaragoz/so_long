#include "so_long.h"

void sl_move(int key, t_game *t)
{
	int r;

	r = 0;
	if (key == 13 || key == 126)
		r = sl_move_up(t);
	else if (key == 1 || key == 125)
		r = sl_move_down(t);
	else if (key == 0 || key == 123)
		r = sl_move_left(t);
	else if (key == 2 || key == 124)
		r = sl_move_right(t);
	else
		return;
	if (r)
	{
		sl_update_map(t);
		mlx_string_put(t->mlx, t->win, 15, 20, 0x000000FF, ft_itoa(++(t->step_count)));
		printf("step : %d\n", t->step_count);
	}
}

int sl_move_up(t_game *t)
{
	int x_index;
	int y_index;

	x_index = t->curr_x_pos / t->img->unit_width;
	y_index = t->curr_y_pos / t->img->unit_height;
	if (t->map[(y_index - 1)][x_index] != '1' && (t->map[y_index - 1][x_index] != 'E' ||
												  t->curr_score == t->total_collectible)) // eger bir ust kare duvar degilse, ve (exit degilse veya tum nesneler toplandiysa) yukari git.
	{
		if (t->map[y_index - 1][x_index] == 'C')
			printf("current score = %d:%d\n", ++(t->curr_score), t->total_collectible);
		t->map[y_index][x_index] = '0';
		if (t->map[y_index - 1][x_index] == 'E')
			exit(0);
		t->map[y_index - 1][x_index] = 'P';
		t->curr_y_pos -= 50;
		return (1);
	}
	return (0);
}

int sl_move_down(t_game *t)
{
	int x_index;
	int y_index;

	x_index = t->curr_x_pos / t->img->unit_width;
	y_index = t->curr_y_pos / t->img->unit_height;
	if (t->map[y_index + 1][x_index] != '1' && (t->map[y_index + 1][x_index] != 'E' ||
												t->curr_score == t->total_collectible)) // eger bir alt kare duvar degilse, ve (exit degilse veya tum nesneler toplandiysa) asagi git.
	{
		if (t->map[y_index + 1][x_index] == 'C')
			printf("current score = %d:%d\n", ++(t->curr_score), t->total_collectible);
		t->map[y_index][x_index] = '0'; // eski konumdaki kareyi bos hale getir.
		if (t->map[y_index + 1][x_index] == 'E')
			exit(0);
		t->map[y_index + 1][x_index] = 'P';
		t->curr_y_pos += 50;
		return (1);
	}
	return (0);
}

int sl_move_left(t_game *t)
{
	int x_index;
	int y_index;

	x_index = t->curr_x_pos / t->img->unit_width;
	y_index = t->curr_y_pos / t->img->unit_height;
	if (t->map[y_index][x_index - 1] != '1' && (t->map[y_index][x_index - 1] != 'E' ||
												t->curr_score == t->total_collectible)) // eger bir sol kare duvar degilse ve (exit degilse veya tum nesneler toplandiysa) sola git.
	{
		if (t->map[y_index][x_index - 1] == 'C')
			printf("current score = %d:%d\n", ++(t->curr_score), t->total_collectible);
		t->map[y_index][x_index] = '0';
		if (t->map[y_index][x_index - 1] == 'E')
			exit(0);
		t->map[y_index][x_index - 1] = 'P';
		t->curr_x_pos -= 50;
		return (1);
	}
	return (0);
}

int sl_move_right(t_game *t)
{
	int x_index;
	int y_index;

	x_index = t->curr_x_pos / t->img->unit_width;
	y_index = t->curr_y_pos / t->img->unit_height;
	if (t->map[y_index][x_index + 1] != '1' && (t->map[y_index][x_index + 1] != 'E' ||
												t->curr_score == t->total_collectible)) // eger bir sag kare duvar degilse ve (exit degilse veya tum nesneler toplandiysa) saga git.
	{
		if (t->map[y_index][x_index + 1] == 'C')
			printf("current score = %d:%d\n", ++(t->curr_score), t->total_collectible);
		t->map[y_index][x_index] = '0';
		if (t->map[y_index][x_index + 1] == 'E')
			exit(0);
		t->map[y_index][x_index + 1] = 'P';
		t->curr_x_pos += 50;
		return (1);
	}
	return (0);
}
