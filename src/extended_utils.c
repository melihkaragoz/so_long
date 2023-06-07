/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:06:01 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:06:02 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_print_map_as_ascii(t_game *t)
{
	int	i;

	i = 0;
	while (t->map[i])
	{
		printf("%i|", t->map[i]);
		if (t->map[i] == 10)
			ft_putstr_fd("\n", 1);
		i++;
	}
}

int	sl_check_map_shape(t_game *t)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(t->arr_map[i]);
	while (t->arr_map[i])
	{
		if (len != ft_strlen(t->arr_map[i]))
			return (1);
		len = ft_strlen(t->arr_map[i]);
		i++;
	}
	return (0);
}

void	sl_patch_wall(t_game *t)
{
	t->map_init = 1;
	t->fill_x = t->screen_width - 50;
	t->fill_y = 0;
	sl_draw_wall(t);
	t->fill_x = 0;
}

int	exit_with_error(t_game *t, char *msg, int no)
{
	ft_putstr_fd(msg, 2);
	free(t->map);
	free(t->addr);
	free(t->img);
	t->i = 0;
	while ((t->arr_map[t->i]))
		free(t->arr_map[t->i++]);
	exit(no);
}

void	sl_update_check(t_game *t, char *c)
{
	t->i = 0;
	c = (t->map + (t->i));
	while (*(c++))
	{
		if (sl_is_char_valid(*c))
		{
			if (*c == '1')
				sl_draw_wall(t);
			else if (*c == 'C')
				sl_draw_collectible(t);
			else if (*c == 'P')
				sl_draw_character(t);
			else if (*c == 'E')
				sl_draw_exit(t);
			else if (*c == '\n')
			{
				t->fill_x = 0;
				t->fill_y += 50;
			}
			else
				t->fill_x += 50;
		}
	}
}
