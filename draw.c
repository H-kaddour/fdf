/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:31:49 by hkaddour          #+#    #+#             */
/*   Updated: 2022/04/06 21:54:11 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(int *x, int *y, int z, end *data)
{
	int	a;

	a = *x;
	*x = ((*x - *y)) * cos(0.5);
	*y = (a + *y) * sin(0.5) - z ;
}

void    setting(end *t_data)
{
    int z;
    int z1;

    z = t_data->map[(int)t_data->y][(int)t_data->x] * t_data->depth;
    z1 = t_data->map[(int)t_data->y1][(int)t_data->x1] * t_data->depth;
    //zoom
    t_data->x *= t_data->zoom;
    t_data->y *= t_data->zoom;
    t_data->x1 *= t_data->zoom;
    t_data->y1 *= t_data->zoom;
    if (t_data->p == 1)
    {
        isometric(&t_data->x, &t_data->y, z, t_data);
        isometric(&t_data->x1, &t_data->y1, z1, t_data);
    }
    //position
    t_data->x += t_data->oppostion_x;
    t_data->y += t_data->oppostion_y;
    t_data->x1 += t_data->oppostion_x;
    t_data->y1 += t_data->oppostion_y;
}

void    algorhythm(end *t_data)
{
    int dx;
    int dy;
    int p;

    setting(t_data);
    dx = abs(t_data->x1 - t_data->x);
    dy = abs(t_data->y1 - t_data->y);
    p = 2 * (dy - dx);
    while (t_data->x < t_data->x1 || t_data->y < t_data->y1)
    {
        mlx_pixel_put(t_data->mlx, t_data->window, t_data->x, t_data->y,
                t_data->loun);
        if (p < 0)
        {
            p = p + 2 * dy;
            t_data->x++;
        }
        else if (p > 0)
        {
            p = p + 2 * (dy - dx);
            t_data->y++;
        }
    }
}

void    coordinate(int x, int y, int check ,end *t_data)
{
    if (check == 0)
    {
        t_data->x = x;
	      t_data->x1 = x + 1;
	      t_data->y = y;
	      t_data->y1 = y;
        algorhythm(t_data);
    }
    if (check == 1)
    {
	      t_data->x = x;
	      t_data->x1 = x;
	      t_data->y = y;
	      t_data->y1 = y + 1;
        algorhythm(t_data);
    }
}

void draw(end *t_data)
{
    int x;
    int y;

    y = 0;
    while (y < t_data->heigh)
    {
        x = 0;
        while (x < t_data->weigh)
        {
            isometric(&t_data->x, &t_data->y, t_data->map[y][x], t_data);
            if (t_data->map[y][x] > 0)
               t_data->loun = 0xff00ff;
            else
               t_data->loun = 0xffffff;
	  	      if (x < t_data->weigh - 1)
                coordinate(x, y, 0, t_data);
	  	      if (y < t_data->heigh - 1)
                coordinate(x, y, 1, t_data);
           x++;
        }
        y++;
    }
}





















//void    magic(end *t_data)
//{
//    int dx;
//    int dy;
//    int p;
//
//    dx = abs(t_data->x1 - t_data->x);
//    dy = abs(t_data->y1 - t_data->y);
//    p = 2 * dy - dx;
//    while (t_data->x <= t_data->x1)
//    {
//        mlx_pixel_put(t_data->mlx, t_data->window, t_data->x, t_data->y, 0xFFFFFF);
//        t_data->x++;
//        if (p < 0)
//        {
//            p += 2 * dy;
//        }
//        else
//        {
//            p += 2 * dy - 2 * dx;
//            t_data->y++;
//        }
//    }
//}
//
//void    coordinate(int x, int y, end *t_data, int check)
//{
//    if (check == 0)
//    {
//        t_data->x = x;
//        t_data->x1 = x + 1;
//        t_data->y = y;
//        t_data->y1 = y;
//    }
//    if (check == 1)
//    {
//        t_data->x = x;
//        t_data->x1 = x;
//        t_data->y = y;
//        t_data->y1 = y + 1;
//    }
//    magic(t_data);
//}
//
//void	draw(end *t_data)
//{
//    int x;
//    int y;
//
//    y = 0;
//    x = 0;
//    while (y < t_data->heigh)
//    {
//        x = 0;
//        while (x < t_data->weigh)
//        {
//            if (x < t_data->weigh - 1)
//                coordinate(x, y, t_data, 0);
//            if (y < t_data->heigh - 1)
//                coordinate(x, y, t_data, 1);
//            x++;
//        }
//        y++;void	algo(t_data *data)



















//}

//pseudo code algo brensenham:
//































//circle draw algo mid point:
//void midPointCircleDraw(int x_centre, int y_centre, int r, void *mlx, void *win)
//{
//    int x = r, y = 0;
//		mlx_pixel_put(mlx, win, x + x_centre, y + y_centre, 0xFFFFFF);
//    if (r > 0)
//    {
//		    mlx_pixel_put(mlx, win, x + x_centre, -y + y_centre, 0xFFFFFF);
//		    mlx_pixel_put(mlx, win, y + x_centre, x + y_centre, 0xFFFFFF);
//		    mlx_pixel_put(mlx, win, -y + x_centre, x + y_centre, 0xFFFFFF);
//    }
//    int P = 1 - r;
//    while (x > y)
//    {
//        y++;
//        if (P <= 0)
//            P = P + 2*y + 1;
//        else
//        {
//            x--;
//            P = P + 2*y - 2*x + 1;
//        }
//        if (x < y)
//            break;
//		        mlx_pixel_put(mlx, win, x + x_centre, y + y_centre, 0xFFB33D);
//		        mlx_pixel_put(mlx, win, -x + x_centre, y + y_centre, 0xF500E4);
//		        mlx_pixel_put(mlx, win, x + x_centre, -y + y_centre, 0xF500E4);
//		        mlx_pixel_put(mlx, win, -x + x_centre, -y + y_centre, 0xFFB33D);
//        if (x != y)
//        {
//		        mlx_pixel_put(mlx, win, y + x_centre, x + y_centre, 0xB23CF9);
//		        mlx_pixel_put(mlx, win, -y + x_centre, x + y_centre, 0x22F519);
//		        mlx_pixel_put(mlx, win, y + x_centre, -x + y_centre, 0xB23CF9);
//		        mlx_pixel_put(mlx, win, -y + x_centre, -x + y_centre, 0x22F519);
//        }
//    }
//}
//
//void    circle_draw(int x, int y, int r, void *mlx, void *win)
//{
//    int i;
//    int h;
//    int h1;
//    int x1;
//    int y1;
//    int hold;
//
//    i = 0;
//    h = 1 - r;
//    h1 = 1 - r;
//    //y = r;
//    mlx_pixel_put(mlx, win, x, r, 0xFFFFFF);
//    x++;
//    y++;
//    while (x < 550 && y < 450)
//    {
//       hold = h1; 
//        if (h1 < 0)
//        {
//            h1 = hold + 2 * x +3;
//            x1 = (x - 1) + 1;
//            y1 = y - 1;
//		        mlx_pixel_put(mlx, win, x1, y1, 0x22F519);
//        }
//        else if (h1 >= 0)
//        {
//            h1 = hold + 2 * (x - y) + 5;
//            x1 = (x - 1) + 1;
//            y1 = (y - 1) - 1;
//		        mlx_pixel_put(mlx, win, x1, y1, 0xF500E4);
//        }
//        x++;
//        y++;
//    } 
//}
//
//int	main()
//{
//	void *mlx;
//	void *win;
//
//	mlx = mlx_init();
//	win = mlx_new_window(mlx, 1080, 900, "fuck");
//	//midPointCircleDraw(500, 400, 300, mlx, win);
//  circle_draw(500, 400, 500, mlx, win);
//	mlx_loop(mlx);
//}

