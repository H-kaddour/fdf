/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:42:43 by hkaddour          #+#    #+#             */
/*   Updated: 2022/04/25 21:44:03 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(float *x, float *y, int z, t_end *t_data)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(t_data->angles_x);
	*y = (prev_x + prev_y) * sin(t_data->angles_y) - z;
}

static void	setting(t_end *t_data)
{
	int	z;
	int	z1;

	z = t_data->map[(int)t_data->y][(int)t_data->x] * t_data->depth;
	z1 = t_data->map[(int)t_data->y1][(int)t_data->x1] * t_data->depth;
	t_data->x *= t_data->zoom;
	t_data->y *= t_data->zoom;
	t_data->x1 *= t_data->zoom;
	t_data->y1 *= t_data->zoom;
	if (t_data->iso == 1)
	{
		isometric(&t_data->x, &t_data->y, z, t_data);
		isometric(&t_data->x1, &t_data->y1, z1, t_data);
	}
	t_data->x += t_data->oppostion_x;
	t_data->y += t_data->oppostion_y;
	t_data->x1 += t_data->oppostion_x;
	t_data->y1 += t_data->oppostion_y;
}

static void	algorhythm(t_end *t_data)
{
	float	dx;
	float	dy;
	float	big;

	setting(t_data);
	dx = t_data->x1 - t_data->x;
	dy = t_data->y1 - t_data->y;
	big = bigg(abs((int)dx), abs((int)dy));
	dx /= big;
	dy /= big;
	while ((int)(t_data->x1 - t_data->x) || (int)(t_data->y1 - t_data->y))
	{
		mlx_pixel_put(t_data->mlx, t_data->window, t_data->x, t_data->y, t_data->loun);
		t_data->x += dx;
		t_data->y += dy;
	}
}

static void	coordinate(int x, int y, int check, t_end *t_data)
{
	if (check == 0)
	{
		t_data->x = x;
		t_data->x1 = x + 1;
		t_data->y = y;
		t_data->y1 = y;
	}
	if (check == 1)
	{
		t_data->x = x;
		t_data->x1 = x;
		t_data->y = y;
		t_data->y1 = y + 1;
	}
	algorhythm(t_data);
}

void	draw(t_end *t_data)
{
	int	x;
	int	y;

	y = 0;
	menu(t_data);
	while (y < t_data->height)
	{
		x = 0;
		while (x < t_data->width)
		{
			color(t_data, x, y);
			if (x < t_data->width - 1)
				coordinate(x, y, 0, t_data);
			if (y < t_data->height - 1)
				coordinate(x, y, 1, t_data);
			x++;
		}
		y++;
	}
}
