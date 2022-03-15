/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:35:52 by hkaddour          #+#    #+#             */
/*   Updated: 2022/03/15 17:55:58 by hkaddour         ###   ########.fr       */
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

typedef struct fdf
{
	int		i;
	int		fd;
	char	*read;
	int		**arr;
	int		**alloc;
	char	**split;
	//////////////
	int		fdd;
	char	*rd;
} end;

#endif
