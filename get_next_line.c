/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 11:52:58 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 15:56:49 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int			n_index(const char *str)
{
	int		i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*rest;
	char			*tmp;
	char			buff[BUFF_SIZE + 1];
	int				char_count;
	int				n;
	int				r;

	/* basic tests */
	if (!line || BUFF_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (-1);
	/* rest pre-process */
	if ((n = n_index(rest)) != -1)
	{
		*line = ft_strsub(rest, 0, n);
		rest += n + 1;
		return (1);
	}
	/* rest init */
	if (!rest)
		rest = ft_strdup("");
	r = 0;
	ft_bzero(buff, BUFF_SIZE);
	/* read */
	while ((char_count = read(fd, buff, BUFF_SIZE)))
	{
		r = 1;
		tmp = rest;
		rest = ft_strjoin(rest, buff);
		free(tmp);
		if ((n = n_index(rest)) != -1)
			break ;
		ft_bzero(buff, BUFF_SIZE);
	}
	/* rest after process */
	if ((n = n_index(rest)) != -1)
	{
		*line = ft_strsub(rest, 0, n);
		rest += n + 1;
		return (1);
	}
	else
		*line = rest;
	return (r);
}
