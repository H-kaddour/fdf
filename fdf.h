/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:35:52 by hkaddour          #+#    #+#             */
/*   Updated: 2022/03/17 00:24:09 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"
//# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct grab_line
{
	char		*ptr;
	char		*tmp;
	char		*buff;
	char		*line;
} line;

typedef struct fdf
{
	/////
	int		fd;
	int		**read;
	/////
	//int		fd;
	//char	*read;
	int		**ptr;
	int		**map;
	char	**split;
	//////////////
	int		fdd;
	char	*rd;
} end;

int	**read_map(char *av, end *t_data);
char	*grab_line(int fd);

#endif
