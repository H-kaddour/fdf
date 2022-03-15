/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:25:44 by hkaddour          #+#    #+#             */
/*   Updated: 2022/03/04 16:10:42 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int		i;
	int		*ptr;
	int		fd;
	int		at;
	char	**split;
	char	*read;

	i = 0;
	fd = open("fd.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	read = get_next_line(fd);
	while (read[i])
		i++;
	ptr = malloc(sizeof(int) * i + 1);
	split = ft_split(read, ' ');
	i = 0;
	while(split[i] != NULL)
	{
		at = ft_atoi(split[i]);
		ptr[i] = at;
		//printf("%d", ptr[i]);
		i++;
	}
	//printf("\n");
	ptr[i] = 0;
	i = 0;
	while (i < 11)
	{
		printf("%d", *ptr);
		ptr++;
		i++;
	}
	return (0);
}
