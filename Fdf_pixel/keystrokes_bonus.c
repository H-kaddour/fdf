/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystrokes_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:25:53 by hkaddour          #+#    #+#             */
/*   Updated: 2022/04/25 21:43:41 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse(int mouse, int x, int y, t_end *t_data)
{
	mlx_clear_window(t_data->mlx, t_data->window);
	if (mouse == 5)
		t_data->zoom += 1;
	if (mouse == 4)
		t_data->zoom -= 1;
	if (mouse == 1)
	{
		t_data->oppostion_x = x;
		t_data->oppostion_y = y;
	}
	draw(t_data);
	return (0);
}

static void	key_helper(int key, t_end *t_data)
{
	if (key == 34)
	{
		if (t_data->iso == 1)
			t_data->iso -= 1;
		else if (t_data->iso == 0)
			t_data->iso += 1;
	}
	if (key == 4)
		t_data->angles_x += 0.2;
	if (key == 9)
		t_data->angles_y += 0.2;
	if (key == 40)
		t_data->depth += 1;
	if (key == 38)
		t_data->depth -= 1;
}

int	key_strokes(int key, t_end *t_data)
{
	mlx_clear_window(t_data->mlx, t_data->window);
	if (key == 24)
		t_data->zoom += 1;
	if (key == 27)
		t_data->zoom -= 1;
	if (key == 53)
		escape(53, t_data);
	if (key == 126)
		t_data->oppostion_y -= 10;
	if (key == 125)
		t_data->oppostion_y += 10;
	if (key == 123)
		t_data->oppostion_x -= 20;
	if (key == 124)
		t_data->oppostion_x += 20;
	key_helper(key, t_data);
	draw(t_data);
	return (0);
}
