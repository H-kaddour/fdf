/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:51:54 by hkaddour          #+#    #+#             */
/*   Updated: 2022/04/25 21:24:37 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_end	t_data;

	if (ac < 2 || ac > 2)
		error("Check arguments!\nUsage: [fdf] map");
	t_data.fd = open(av[1], O_RDONLY);
	if (t_data.fd < 0)
		error("File not existing!");
	t_data.oppostion_x = WIN_W / 2;
	t_data.oppostion_y = WIN_H / 2 - 300;
	t_data.iso = 1;
	t_data.depth = 1;
	t_data.angles_x = 0.5;
	t_data.angles_y = 0.5;
	read_map(av[1], &t_data);
	zoom(&t_data);
	t_data.mlx = mlx_init();
	t_data.window = mlx_new_window(t_data.mlx, WIN_W, WIN_H, "fdf");
	draw(&t_data);
	mlx_hook(t_data.window, 17, 1L << 0, escape, &t_data);
	mlx_key_hook(t_data.window, key_strokes, &t_data);
	mlx_mouse_hook(t_data.window, mouse, &t_data);
	mlx_loop(t_data.mlx);
	return (0);
}
