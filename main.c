/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:48:02 by hkaddour          #+#    #+#             */
/*   Updated: 2022/03/16 23:54:35 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int	i;
	int	j;
	end	t_data;

	i = 0;
	j = 0;
	t_data.fd = open(av[1], O_RDONLY);
	if (t_data.fd < 0)
		return (0);
	t_data.read = read_map(av[1], &t_data);
	while (t_data.read[i])
	{
		j = 0;
		while (j < 19)
		{
			printf("%d", t_data.read[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
