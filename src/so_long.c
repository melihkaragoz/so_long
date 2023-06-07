/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:06:20 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:06:20 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	t;

	if (ac < 2)
	{
		ft_putstr_fd("Couldn't find a map path.\n", 2);
		exit(1);
	}
	t.map_path = av[1];
	sl_check_map_path_valid(av[1]);
	sl_load_map(&t);
	sl_init_game(&t);
	if (check_errors(&t))
		exit_with_error(&t, "invalid map\n", 1);
	sl_vp_valid_path(&t);
	t.mlx = mlx_init();
	t.win = mlx_new_window(t.mlx, t.screen_width, t.screen_height, "so long");
	t.img = mlx_new_image(t.mlx, t.screen_width, t.screen_height);
	t.addr = mlx_get_data_addr(t.img, &t.bppx, &t.line_length, &t.endian);
	sl_update_map(&t);
	mlx_hook(t.win, 2, 1L << 0, sl_key_handler, &t);
	mlx_hook(t.win, 17, 0, &exit_with_error, &t);
	mlx_loop(t.mlx);
	return (0);
}
