/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:47:23 by hkaddour          #+#    #+#             */
/*   Updated: 2022/04/03 22:00:13 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    drawing(void *mlx, void *win, int x, int y, int x1, int y1)
{
    int dx;
    int dy;
    int p;

    dx = x1 - x;
    dy = y1 - y;
    p = 2 * (dy - dx);
    while (x <= x1)
    {
        if (p < 0)
        {
            mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
            //printf("(%d, %d) || (%d, %d)\n\n", x, y, x1, y1); p = p * 2 * dy;
            x++;
        }
        else if (p >= 0)
        {
            mlx_pixel_put(mlx, win, x, y, 0xFFFFF);
            //printf("(%d, %d) || (%d, %d)\n", x, y, x1, y1);
            y++;
            x++;
            p = p + 2 * (dy - dx);
        }
        x++;
    }
}

int main()
{
    void *mlx;
    void *win;
    int x = 100;
    int y = 100;
    int x1 = 250;
    int y1 = 250;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1290, 900, "draw test");
    drawing(mlx, win, x, y, x1, y1);
    mlx_loop(mlx);
}
