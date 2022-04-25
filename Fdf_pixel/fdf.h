/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:35:52 by hkaddour          #+#    #+#             */
/*   Updated: 2022/04/25 22:17:28 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_W	2560
# define WIN_H	1700
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct grab_line
{
	char		*ptr;
	char		*tmp;
	char		*buff;
	char		*line;
}	t_gnl;

typedef struct fdf
{
	int		**color;
	int		fd;
	char	*read;
	int		**map;
	char	**split;
	void	*mlx;
	void	*window;
	int		height;
	int		width;
	int		loun;
	int		zoom;
	int		oppostion_x;
	int		oppostion_y;
	int		depth;
	int		iso;
	void	*img;
	char	*path;
	float	x1;
	float	y1;
	float	x;
	float	y;
	float	angles_x;
	float	angles_y;
	int		j;
	int		w;
	int		h;
}	t_end;

void	read_map(char *av, t_end *t_data);
char	*grab_line(int fd);
void	draw(t_end *t_data);
int		key_strokes(int key, t_end *t_data);
int		mouse(int mouse, int x, int y, t_end *t_data);
void	menu(t_end *t_data);
float	bigg(float dx, float dy);
void	zoom(t_end *t_data);
void	color(t_end *t_data, int x, int y);
int		escape(int key, t_end *t_data);
int		key_main(int key, t_end *t_data);
int		error(char *error);

#endif
