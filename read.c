/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:04:46 by hkaddour          #+#    #+#             */
/*   Updated: 2022/04/05 16:35:49 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int ft_hex_dec(char *str)
{
	int len;
	int base;
	int rslt;

	len = ft_strlen(str) - 1;
	base = 1;
	rslt = 0;
//	while (str[len] == '\n')
//		len--;
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

int	ft_weight(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
}

int	**fill_map(end *t_data, char *av)
{
	int	i;
	int	j;
	int k;

	j = 0;
	t_data->fd = open(av, O_RDONLY);
	if (t_data->fd < 0)
		return (0);
	t_data->rd = grab_line(t_data->fd);
	while (t_data->rd)
	{
		i = 0;
		t_data->split = ft_split(t_data->rd, ' ');
		t_data->weigh = ft_weight(t_data->split);
		t_data->map[j] = malloc(sizeof(int) * /*ft_weight(t_split)*/ t_data->weigh);
		t_data->color[j] = malloc(sizeof(int) * t_data->weigh);
		while (t_data->split[i])
		{
			k = 0;
			t_data->map[j][i] = ft_atoi(t_data->split[i]);
			while (t_data->split[i][k] != ',' && t_data->split[i][k])
				k++;
			if (t_data->split[i][k++] == ',')
			{
				t_data->color[j][i] = ft_hex_dec(&t_data->split[i][k]);
				//printf("%d", t_data->color[j][i]);
			}
			else
				t_data->color[j][i] = ft_atoi("0");
			i++;
		}
		//free(t_data->rd);
		t_data->rd = grab_line(t_data->fd);
		j++;
	}
	t_data->map[j] = NULL;
	t_data->color[j] = NULL;
	return (t_data->map);
}

int	**read_map(char *av, end *t_data)
{
	//int	i;

	//i = 0;
	t_data->rd = grab_line(t_data->fd);
	while (t_data->rd)
	{
		t_data->rd = grab_line(t_data->fd);
		t_data->heigh++;
	}
	t_data->map = (int **) malloc(sizeof(int *) * t_data->heigh + 1);
	t_data->color = (int **) malloc(sizeof(int *) * t_data->heigh + 1);
	t_data->matrix = fill_map(t_data, av);
	return (t_data->matrix);
}


//print map color:
	//free(t_data->rd);
	//i = 0;
	//while (t_data->color[i])
	//{
	//	j = 0;
	//	while (j < 8)
	//	{
	//		printf("%d", t_data->color[i][j]);
	//		j++;
	//	}
	//	printf("\n");
	//	i++;
	//}
	//j = 0;
	//while(t_data->split[j])
	//	free(t_data->split[j++]);
	//free(t_data->split);
	//while (1);

//pseudo code:
//allocation for color maps and turn hex to int
//pass commas
//mines
