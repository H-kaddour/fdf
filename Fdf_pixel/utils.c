/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:56:54 by hkaddour          #+#    #+#             */
/*   Updated: 2022/04/25 21:44:26 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	bigg(float dx, float dy)
{
	if (dx > dy)
		return (dx);
	return (dy);
}

void	color(t_end *t_data, int x, int y)
{
	if (t_data->iso == 1 || t_data->iso == 0)
	{
		if (t_data->map[y][x] == 0 && t_data->color[y][x] == 0)
			t_data->loun = 0xFFE300;
		else if (t_data->map[y][x] >= 0 && t_data->color[y][x] > 0)
			t_data->loun = t_data->color[y][x];
		else if (t_data->map[y][x] > 0 && t_data->color[y][x] == 0)
			t_data->loun = 0xFF5403;
		else
			t_data->loun = 0x125B50;
	}
}

void	zoom(t_end *t_data)
{
	if (t_data->height < 100 && t_data->width < 100)
		t_data->zoom = 20;
	else
		t_data->zoom = 10;
}

void	menu(t_end *t_data)
{
	t_data->path = "./background.xpm";
	t_data->img = mlx_xpm_file_to_image(t_data->mlx, t_data->path, \
		&t_data->w, &t_data->h);
	mlx_put_image_to_window(t_data->mlx, t_data->window, t_data->img, 0, 0);
}
