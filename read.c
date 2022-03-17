/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:04:46 by hkaddour          #+#    #+#             */
/*   Updated: 2022/03/17 03:09:05 by hkaddour         ###   ########.fr       */
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

int	**ft_alloc(end *t_data, char *av)
{
	int	i;
	int	j;

	j = 0;
	t_data->fd = open(av, O_RDONLY);
	if (t_data->fd < 0)
		return (0);
	t_data->rd = grab_line(t_data->fd);
	while (t_data->rd)
	{
		i = 0;
		t_data->split = ft_split(t_data->rd, ' ');
		t_data->ptr[j] = malloc(sizeof(int) * ft_weight(av, t_data->split));
		while (t_data->split[i])
		{
			t_data->ptr[j][i] = ft_atoi(t_data->split[i]);
			i++;
		}
		t_data->rd = grab_line(t_data->fd);
		j++;
	}
	t_data->ptr[j] = NULL;
	return (t_data->ptr);
}

int	**read_map(char *av, end *t_data)
{
	int	i;

	i = 0;
	t_data->rd = grab_line(t_data->fd);
	while (t_data->rd)
	{
		t_data->rd = grab_line(t_data->fd);
		i++;
	}
	t_data->ptr = (int **) malloc(sizeof(int *) * i + 1);
	t_data->map = ft_alloc(t_data, av);
	return (t_data->map);
}

//pseudo code:
//allocation for color maps and turn hex to int
//pass commas
//mines
