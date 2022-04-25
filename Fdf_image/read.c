/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:04:46 by hkaddour          #+#    #+#             */
/*   Updated: 2022/04/25 21:31:33 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_weight(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
}

static int	ft_hex_dec(char *str)
{
	int	len;
	int	base;
	int	rslt;

	len = ft_strlen(str) - 1;
	base = 1;
	rslt = 0;
	while (str[len] && len >= 0)
	{
		if (str[len] >= '0' && str[len] <= '9')
			rslt += (str[len] - 48) * base;
		else if (str[len] >= 'A' && str[len] <= 'F')
			rslt += (str[len] - 55) * base;
		else if (str[len] >= 'a' && str[len] <= 'f')
			rslt += (str[len] - 87) * base;
		base *= 16;
		len--;
	}
	return (rslt);
}

static void	fill_map_helper(int i, t_end *t_data)
{
	int	k;

	k = 0;
	while (t_data->split[i])
	{
		k = 0;
		t_data->map[t_data->j][i] = ft_atoi(t_data->split[i]);
		while (t_data->split[i][k] != ',' && t_data->split[i][k])
			k++;
		if (t_data->split[i][k++] == ',')
			t_data->color[t_data->j][i] = ft_hex_dec(&t_data->split[i][k]);
		else
			t_data->color[t_data->j][i] = ft_atoi("0");
		free(t_data->split[i]);
		i++;
	}
	free(t_data->split);
}

static void	fill_map(t_end *t_data, char *av)
{
	int	i;

	t_data->j = 0;
	t_data->fd = open(av, O_RDONLY);
	t_data->read = grab_line(t_data->fd);
	while (t_data->read)
	{
		i = 0;
		t_data->split = ft_split(t_data->read, ' ');
		t_data->width = ft_weight(t_data->split);
		t_data->map[t_data->j] = malloc(sizeof(int) * t_data->width);
		t_data->color[t_data->j] = malloc(sizeof(int) * t_data->width);
		fill_map_helper(i, t_data);
		free(t_data->read);
		t_data->read = grab_line(t_data->fd);
		t_data->j++;
	}
	free(t_data->read);
	close(t_data->fd);
}

void	read_map(char *av, t_end *t_data)
{
	t_data->height = 0;
	t_data->read = grab_line(t_data->fd);
	if (t_data->read == 0)
		error("Empty file");
	while (t_data->read)
	{
		free(t_data->read);
		t_data->read = grab_line(t_data->fd);
		t_data->height++;
	}
	free(t_data->read);
	close(t_data->fd);
	t_data->map = (int **) malloc(sizeof(int *) * t_data->height + 1);
	t_data->color = (int **) malloc(sizeof(int *) * t_data->height + 1);
	fill_map(t_data, av);
}
