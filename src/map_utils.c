/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:06:11 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:06:11 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_maplen(t_game *t)
{
	int		fd;
	int		len;
	char	*s;

	fd = open(t->map_path, O_RDONLY);
	s = get_next_line(fd);
	len = 0;
	while (s)
	{
		len += ft_strlen(s);
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (len);
}

void	sl_load_map(t_game *t)
{
	char	*s;
	int		fd;

	t->map_height = 0;
	t->map = calloc(1, 1);
	fd = open(t->map_path, O_RDONLY);
	s = get_next_line(fd);
	if (!s)
		exit(1);
	t->map_width = ft_strlen(s) - 1;
	while (s)
	{
		t->tmp_map = ft_strjoin(t->map, s);
		free(t->map);
		t->map = t->tmp_map;
		free(s);
		s = get_next_line(fd);
		t->map_height++;
	}
	close(fd);
}

void	sl_update_map(t_game *t)
{
	char	*c;

	c = 0;
	sl_prepare_window(t);
	sl_update_check(t, c);
	sl_patch_wall(t);
	ft_putstr_fd("step :", 1);
	ft_putnbr_fd(t->step_count, 1);
	ft_putstr_fd("\n", 1);
	t->step_counter_str = ft_itoa(t->step_count++);
	mlx_string_put(t->mlx, t->win, 15, 20, 0x00FFFFFF, t->step_counter_str);
	free(t->step_counter_str);
}

int	sl_is_char_valid(char c)
{
	return ((c == '0') || (c == '1') || (c == 'C') || (c == 'P') || \
			(c == 'E') || (c == '\n'));
}

int	sl_is_square_available(t_game *t, char c)
{
	return (c != '1' && (c != 'E' || t->curr_score == t->total_collectible));
}
