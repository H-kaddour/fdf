/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:48:02 by hkaddour          #+#    #+#             */
/*   Updated: 2022/04/06 21:48:58 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
		i++;
	return (i);
}

//int events(int	key, end *t_data)
//{
//	mlx_destroy_window(t_data->mlx, t_data->window);
//	return (0);
//}

int	key_strokes(int key, end *t_data)
{
	mlx_clear_window(t_data->mlx, t_data->window);
	//zoom miness
	if (key == 24)
	{
		t_data->zoom += 1;
	}
	//mines
	if (key == 27)
	{
		t_data->zoom -= 1;
	}
	if (key == 53)
	{
		//mlx_destroy_window(t_data->mlx, t_data->window);
		exit(1);
	}
	//up
	if (key == 126)
	{
		t_data->oppostion_x += 10;
		//t_data->oppostion_y += 10;
	}
	//down
	if (key == 125)
	{
		//t_data->oppostion_x -= 10;
		t_data->oppostion_y -= 10;
	}
	draw(t_data);
	ft_putnbr_fd(key,1);
	ft_putchar_fd('\n',1);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	end	t_data;

	i = 0;
	j = 0;
	(void) ac;
	t_data.fd = open(av[1], O_RDONLY);
	if (t_data.fd < 0)
		return (0);
	t_data.oppostion_x = WIN_W / 2;
	t_data.oppostion_y = WIN_H / 2 - 500;
	t_data.p = 1;
	t_data.depth = 1;
	t_data.read = read_map(av[1], &t_data);
  //printf("%d\n", t_data.heigh);
  //printf("%d\n", t_data.weigh);
	t_data.mlx = mlx_init();
	t_data.window = mlx_new_window(t_data.mlx, WIN_W, WIN_H, "fdf");
	draw(&t_data);
	//mlx_hook(t_data.window, 2, 1L<<0, events, &t_data);
	mlx_key_hook(t_data.window, key_strokes, &t_data);
	//mlx_mouse_hook(t_data.window, key_strokes, &t_data);
	//mlx_loop_hook(t_data.window, key_strokes, &t_data);
	mlx_loop(t_data.mlx);
	return (0);
}

//print maps:
	//while (1);
	//while (t_data.read[i])
	//{
	//	j = 0;
	//	while (j < 22)
	//	{
	//		printf("%d", t_data.read[i][j]);
	//		j++;
	//	}
	//	printf("\n");
	//	i++;
	//}

	//count lenght of line to print 00000:
	//int k;
	//int	fdd;
	//fdd = open(av[1], O_RDONLY);
	//t_data.weight = grab_line(fdd);
	//t_data.sp = ft_split(t_data.weight, ' ');
	//k = count(t_data.sp);
	//while (t_data.read[i])
	//{
	//	j = 0;
	//	while (j < k)
	//	{
	//		printf("%d", t_data.read[i][j]);
	//		j++;
	//	}
	//	printf("\n");
	//	i++;
	//}
	//j = 0;
	//while (t_data.sp[j])
	//	free(t_data.sp[j++]);
	//free(t_data.sp);
	//while (1);
	/////////////////////////////////////

//pseudo code:
//read maps of color if u find ',' statrt to copy in map of color change the color format to hex
