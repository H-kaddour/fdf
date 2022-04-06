/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:35:52 by hkaddour          #+#    #+#             */
/*   Updated: 2022/04/06 21:48:30 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"
#define WIN_W 1280
#define WIN_H 900
//# include "printf/ft_printf.h"

typedef struct grab_line
{
	char		*ptr;
	char		*tmp;
	char		*buff;
	char		*line;
} line;

typedef struct fdf
{
	int		**color;
	/////
	int		fd;
	int		**read;
	/////
	int		**ptr;
	int		**map;
	int		**matrix;
	char	**split;
	/////////////
	int		fdd;
	char	*rd;
	///////////
	//count line to print
	char	*weight;
	char	**sp;
	//mlx var
	void	*mlx;
	void	*window;
	//height len for the map to draw
	int		heigh;
	int		weigh;
	//draw
	int	x1;
	int		y1;
	int		x;
	int		y;
	int loun;
	//setting and keystroke
	int	zoom;
	int oppostion_x;
	int oppostion_y;
	int	depth;
	int	p;
} end;

int	**read_map(char *av, end *t_data);
char	*grab_line(int fd);
void	draw(end *t_data);

#endif
