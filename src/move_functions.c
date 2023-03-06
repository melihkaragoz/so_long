#include "so_long.h"

void sl_move(int key, t_game *t)
{
	if (key == 13 || key == 126)
		sl_move_up(t);
	else if (key == 1 || key == 125)
		sl_move_down(t);
	else if (key == 0 || key == 123)
		sl_move_left(t);
	else if (key == 2 || key == 124)
		sl_move_right(t);
	else
		return;
	printf("konum degisti, yeni konum = x: %d, y: %d\n", t->curr_x_pos, t->curr_y_pos);
	sl_update_map(t);
}

int sl_move_up(t_game *t)
{
	printf("%d:%d\n",t->curr_score,t->total_collectible);
	if (t->map[(t->curr_y_pos / t->img->unit_height) - 1][(t->curr_x_pos / t->img->unit_width)] != '1' &&
		(t->map[(t->curr_y_pos / t->img->unit_height) - 1][(t->curr_x_pos / t->img->unit_width)] != 'E' ||
		t->curr_score == t->total_collectible)
	)
	{
		if (t->map[(t->curr_y_pos / t->img->unit_height) - 1][(t->curr_x_pos / t->img->unit_width)] == 'C')
		{
			t->curr_score++;
			printf("current score : %d\n", t->curr_score);
		}
		t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width)] = '0';
		if(t->map[(t->curr_y_pos / t->img->unit_height)-1][(t->curr_x_pos / t->img->unit_width)] == 'E')
			exit(0);
		t->map[(t->curr_y_pos / t->img->unit_height) - 1][(t->curr_x_pos / t->img->unit_width)] = 'P';
		t->curr_y_pos -= 50;
		return (1);
	}
	else
		printf("height-up overflow");
	return (0);
}

int sl_move_down(t_game *t)
{
	printf("%d:%d\n",t->curr_score,t->total_collectible);
	if (t->map[(t->curr_y_pos / t->img->unit_height) + 1][(t->curr_x_pos / t->img->unit_width)] != '1' &&
		(t->map[(t->curr_y_pos / t->img->unit_height) + 1][(t->curr_x_pos / t->img->unit_width)] != 'E' ||
		t->curr_score == t->total_collectible)
	)
	{
		if (t->map[(t->curr_y_pos / t->img->unit_height) + 1][(t->curr_x_pos / t->img->unit_width)] == 'C')
		{
			t->curr_score++;
			printf("current score : %d\n", t->curr_score);
		}
		t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width)] = '0';
		if(t->map[(t->curr_y_pos / t->img->unit_height)+1][(t->curr_x_pos / t->img->unit_width)] == 'E')
			exit(0);
		t->map[(t->curr_y_pos / t->img->unit_height) + 1][(t->curr_x_pos / t->img->unit_width)] = 'P';
		t->curr_y_pos += 50;
		return (1);
	}
	else
		printf("height-down overflow");
	return (0);
}

int sl_move_left(t_game *t)
{
	printf("%d:%d\n",t->curr_score,t->total_collectible);
	if (t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width) - 1] != '1' &&
		(t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width) - 1] != 'E' ||
		t->curr_score == t->total_collectible)
	)
	{
		if (t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width) - 1] == 'C')
		{
			t->curr_score++;
			printf("current score : %d\n", t->curr_score);
		}
		t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width)] = '0';
		if(t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width) - 1] == 'E')
			exit(0);
		t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width) - 1] = 'P';
		t->curr_x_pos -= 50;
		return (1);
	}
	else
		printf("width-left overflow");
	return (0);
}

int sl_move_right(t_game *t)
{
	printf("%d:%d\n",t->curr_score,t->total_collectible);
	if (t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width) + 1] != '1' &&
		(t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width) + 1] != 'E' ||
		t->curr_score == t->total_collectible)
	)
	{
		if (t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width) + 1] == 'C')
		{
			t->curr_score++;
			printf("current score : %d\n", t->curr_score);
		}
		t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width)] = '0';
		if(t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width) + 1] == 'E')
			exit(0);
		t->map[(t->curr_y_pos / t->img->unit_height)][(t->curr_x_pos / t->img->unit_width) + 1] = 'P';
		t->curr_x_pos += 50;
		return (1);
	}
	else
		printf("width-right overflow");
	return (0);
}
