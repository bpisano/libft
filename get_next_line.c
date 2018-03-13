/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 11:52:58 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 21:10:00 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		n_index(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

int		copy_rest(char **line, char *rest, int size, int step)
{
	int		n;

	if ((n = n_index(rest)) == -1)
		return (0);
	if (step == 0)
	{
		*line = ft_strnew(n);
		ft_strncpy(*line, rest, n);
		ft_strcpy(rest, rest + n + 1);
	}
	else
	{
		*line = ft_strrealloc(*line, n + size);
		ft_strncat(*line, rest, n);
		ft_strcpy(rest, rest + n + 1);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		rest[BUFF_SIZE + 1];
	int				len;
	int				ret;

	if (BUFF_SIZE < 1 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	if (copy_rest(line, &rest[0], 0, 0) == 1)
		return (1);
	*line = ft_strnew(ft_strlen(rest));
	ft_strcpy(*line, rest);
	while ((ret = read(fd, rest, BUFF_SIZE)))
	{
		rest[ret] = '\0';
		if (copy_rest(line, &rest[0], ret, 1) == 1)
			return (1);
		*line = ft_strrealloc(*line, ft_strlen(*line) + ret);
		ft_strncat(*line, rest, ret);
	}
	return (ret > 0);
}
