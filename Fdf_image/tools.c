/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:43:43 by hkaddour          #+#    #+#             */
/*   Updated: 2022/04/25 21:34:56 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_main(int key, t_end *t_data)
{
	if (key == 53)
		error("You closed the window :).");
	return (0);
}

int	escape(int key, t_end *t_data)
{
	error("You closed the window :)");
	return (0);
}

int	error(char *error)
{
	ft_putstr_fd(error, 1);
	exit(0);
	return (0);
}
