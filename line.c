/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:44:30 by hkaddour          #+#    #+#             */
/*   Updated: 2022/03/16 23:25:52 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_line(char *str, line *t_line)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[0] == '\0')
		return (NULL);
	t_line->ptr = malloc(sizeof(char) * i + 1);
	if (!t_line->ptr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		t_line->ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		t_line->ptr[i++] = '\n';
	t_line->ptr[i] = 0;
	return (t_line->ptr);
}

char	*next_line(char *str, line *t_line)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(str);
	if (!str)
		return (NULL);
	while (str[j] != '\n' && str[j])
		j++;
	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	t_line->ptr = malloc(sizeof(char) * (i - j));
	if (!t_line->ptr)
		return (NULL);
	i = 0;
	j++;
	while (str[j])
		t_line->ptr[i++] = str[j++];
	t_line->ptr[i] = '\0';
	free(str);
	return (t_line->ptr);
}

int	newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*read_line(char *str, int fd, line *t_line)
{
	int		i;

	i = 1;
	while (i != 0)
	{
		i = read(fd, t_line->buff, 1);
		if (i == -1)
		{
			free(t_line->buff);
			return (NULL);
		}
		t_line->buff[i] = 0;
		t_line->tmp = str;
		if (!t_line->tmp)
		{
			t_line->tmp = malloc(sizeof(char) * 1);
			t_line->tmp[0] = 0;
		}
		str = ft_strjoin(t_line->tmp, t_line->buff);
		free(t_line->tmp);
		if (newline(str) == 1)
			break ;
	}
	free(t_line->buff);
	return (str);
}

char	*grab_line(int fd)
{
	static char	*str;
	line		t_line;

	if (fd < 0)
		return (NULL);
	t_line.buff = malloc(sizeof(char) * 2);
	if (!t_line.buff)
		return (NULL);
	str = read_line(str, fd, &t_line);
	if (!str)
		return (NULL);
	t_line.line = get_line(str, &t_line);
	str = next_line(str, &t_line);
	return (t_line.line);
}

//main to print
//int	main(int ac, char **av)
//{
//	int	i;
//	int	fd;
//	char *rd;
//
//	i = 0;
//	fd = open(av[1], O_RDONLY);
//	if (fd < 0)
//		return (0);
//	rd = grab_line(fd);
//	while (rd)
//	{
//		printf("%s", rd);
//		rd = grab_line(fd);
//	}
//	return (0);
//}
