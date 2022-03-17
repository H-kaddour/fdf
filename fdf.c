/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:28:16 by hkaddour          #+#    #+#             */
/*   Updated: 2022/03/16 16:37:01 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_weight(char *av, char **split)
{
	int	i;

	i = 0;
	av = NULL;
	while (split[i] != NULL)
		i++;
	return (i);
}

int	**ft_alloc(end *ptr, char *av)
{
	int	i;
	int	j;
	int	fd;
	char *rd;
	end lo;

	j = 0;
	/*ptr->fd*/ fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	/*ptr->read*/ rd = get_next_line(fd);
	//printf("%s", rd);
	while (/*ptr->read*/ rd)
	{
		i = 0;
		lo.split = ft_split(rd, ' ');
		ptr->arr[j] = malloc(sizeof(int) * ft_weight(av, lo.split));
		//printf("okk");
		while (lo.split[i])
		{
			ptr->arr[j][i] = ft_atoi(lo.split[i]);
			i++;
		}
		//int s = ft_strlen((char *)ptr->arr);
		//printf("%d\n", s);
		//i = 0;
		//while (i < 11)
		//{
		//	printf("%d", ptr->arr[j][i]);
		//	i++;
		//}
		//printf("\n");
		/*ptr->read*/ rd = get_next_line(fd);
		j++;
	}
	ptr->arr[j] = NULL;
	//i = 0;
	//j = 0;
	//while (ptr->arr[i] != NULL)
	//{
	//	printf("%d", ptr->arr[j][i]);
	//	i++;
	//}
	return (ptr->arr);
}

int	main(int ac, char **av)
{
	end ptr;

	int	k = 0;
	int	j = 0;
	//ptr.i = 0;
	int	i = 0;
	ptr.fd = open(av[1], O_RDONLY);
	if (ptr.fd < 0)
		return (0);
	ptr.read = get_next_line(ptr.fd);
	while (ptr.read)
	{
		ptr.read = get_next_line(ptr.fd);
		//ptr.i++;
		i++;
	}
	ptr.arr = (int **) malloc(sizeof(int *) * i + 1);
	/*ptr.alloc =*/ ft_alloc(&ptr, av[1]);
	//printf("%d", ptr.arr[3][5]);
	//printf("%d", ptr.arr[3][6]);
	//printf("%d", ptr.arr[3][7]);
	return (0);
}

//int	**ft_alloc(end *ptr, char *av)
//{
//	int	i;
//	int	j;
//	int	fd;
//	char *rd;
//
//	j = 0;
//	/*ptr->fd*/ fd = open(av, O_RDONLY);
//	if (ptr->fd < 0)
//		return (0);
//	/*ptr->read*/ rd = get_next_line(ptr->fd);
//	while (/*ptr->read*/ rd)
//	{
//		i = 0;
//		ptr->split = ft_split(ptr->read, ' ');
//		ptr->arr[j] = malloc(sizeof(int) * ft_weight(av, ptr->split));
//		while (ptr->split[i])
//		{
//			ptr->arr[j][i] = ft_atoi(ptr->split[i]);
//			i++;
//		}
//		i = 0;
//		while (i < 16)
//		{
//			printf("%d", ptr->arr[j][i]);
//			i++;
//		}
//		printf("\n");
//		/*ptr->read*/ rd = get_next_line(fd);
//		j++;
//	}
//	ptr->arr[j] = NULL;
//	return (ptr->arr);
//}






























































//int	ft_width(int fd)
//{
//	int		i;
//	char	*line;
//	//char	*ptr;
//
//	i = 0;
//	line = get_next_line(fd);
//	while (line[i] != '\n')
//		i++;
//	//ptr = malloc(sizeof(char) * i + 1);
//	//i = 0;
//	//while (line[i])
//	//{
//	//	ptr[i] = line[i];
//	//	i++;
//	//}
//	//ptr[i] = 0;
//	return (i);
//}
//
//int	ft_height(char *av)
//{
//	int		i;
//	int		fd;
//	char	*height;
//
//	i = 0;
//	fd = open(av, O_RDONLY);
//	if (fd < 0)
//		return (0);
//	height = get_next_line(fd);
//	while (height)
//	{
//		height = get_next_line(fd);
//		i++;
//	}
//	return (i);
//}
//
//int	ft_read_map(char *av, int width, int height, int **ptr)
//{
//	int		i;
//	int		fd;
//	char	*read;
//	char	**split;
//	int		in;
//
//	i = 0;
//	fd = open(av, O_RDONLY);
//	if (fd < 0)
//		return (0);
//	read = get_next_line(fd);
//	while (read)
//	{
//		read = get_next_line(fd);
//
//	}
//	i = 0;
//	//printf("%s\n", split[i]);
//	return (i);
//}
//
//int	main(int ac, char **av)
//{
//	int	fd;
//	int	width;
//	int	height;
//	int	map;
//	int	**ptr;
//
//	fd = open(av[1], O_RDONLY);
//	if (fd < 0)
//		return (0);
//	width = ft_width(fd);
//	height = ft_height(av[1]);
//	ptr = malloc(sizeof(int *) * height + 1);
//	map = ft_read_map(av[1], width, height, ptr);
//	return (0);
//}



	//void	*mlx;
	//void	*window;
	//mlx = mlx_init();
	//window = mlx_new_window(mlx, 1800, 900, "okay");
	//mlx_loop(mlx);

//steps to make fdf;
//1. first you need to read the map with get_next_line
//2. split it in 2d arrays
//3. you need to open the window
//
//to read the map
