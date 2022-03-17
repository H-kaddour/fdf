/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:53:41 by hkaddour          #+#    #+#             */
/*   Updated: 2022/03/16 16:11:33 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//int	*ft_alloc(int at, int **ptr)
//{
//	int	i;
//
//	i = 0;
//	ptr[i++] = malloc(sizeof(int) * 1);
//	return (ptr[i]);
//}

int	ft_weight(char *av, char **split)
{
	int		i;
	int		fd;
	//char	*ptr;
	//char	*read;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	while (split[i] != NULL)
		i++;
	//printf("%d\n", i);
	//read = get_next_line(fd);
	//while (read[i])
	//	i++;
	//ptr = malloc(sizeof(int) * i + 1);
	//while (ptr[i])
	//{
	//	ptr[i] = read[i];
	//	i++;
	//}
	//ptr[i] = 0;
	//printf("%d", i);
	return (i);
}

int	main(int ac, char **av)
{
	int		i;
	int		k;
	int		fd;
	int		fdd;
	int		**ptr;
	char	*read;
	char	**split;
	char	*ok;

	i = 0;
	k = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	read = get_next_line(fd);
	while (read)
	{
		read = get_next_line(fd);
		//printf("%s", read);
		i++;
	}
	ptr = (int **) malloc(sizeof(int *) * i + 1);
	fdd = open(av[1], O_RDONLY);
	ok = get_next_line(fdd);
	while (ok)
	{
		i = 0;
		split = ft_split(ok, ' ');
		ptr[k] = malloc(sizeof(int) * ft_weight(av[1], split));
		//printf("%d", ft_weight(av, split));
		//while (ptr[k][i])
		while (split[i])
		{
			ptr[k][i] = ft_atoi(split[i]);
			i++;
		}
		//ptr[k][i] = 0;
		i = 0;
		while (i < 16)
		{
			printf("%3.d", ptr[k][i]);
			i++;
		}
		printf("\n");
		ok = get_next_line(fdd);
		k++;
		//break ;
		//printf("%d", ptr[k][i]);
		//while (at)
		//{
		//	at = ft_atoi(split[i]);
		//	printf("%d", at);
		//	printf("%d", at);
		//	printf("%d", at);
		//	i++;
		//}
		//while (split[i] != NULL)
		//while (at)
		//{
		//	at = ft_atoi(split[i]);
		//	printf("%d", at);
		//	//ft_alloc(at, ptr);
		//	//printf("%s", split[i]);
		//	i++;
		//	printf("%d", i);
		//	//at = ft_atoi(split[i]);
		//}
	}
	ptr[k] = NULL;
	void	*mlx;
	void	*window;
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1800, 900, "okay");
	int x = 1;
	while (x < 100)
	{
		mlx_pixel_put(mlx, window, x, 20, 0xeaff00);
		x++;
	}
	mlx_loop(mlx);

	//int	j = 0;
	//i = 0;
	//while (split[i])
	//{
	//	printf("%d", ptr[j][i]);
	//	i++;
	//	//j++;
	//}
	//printf("%d\n", ptr[0][0]);
	//printf("%d\n", ptr[1][0]);
	//printf("%d\n", ptr[2][0]);
	//printf("%d\n", ptr[3][0]);
	//printf("%d\n", ptr[4][0]);
	//printf("%d\n", ptr[5][0]);
	return (0);
}

//pseudo code:
//read the file to get the hight
//allocate the in 2d array
//Rasterization the coordination 
