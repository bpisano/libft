/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 11:52:58 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 16:48:51 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		n_index(char *str, int *n)
{
	int		i;

	i = -1;
	*n = -1;
	while (str[++i])
		if (str[i] == '\n')
			return ((*n = i));
	return (-1);
}

void	copy_rest(char **line, char *rest)
{
	*line = ft_strrealloc(*line, ft_strlen(*line) + BUFF_SIZE);
	ft_strcat(*line, rest);
	ft_bzero(rest, BUFF_SIZE);
}

void	copy_rest_to_n(char **line, char *rest, int n)
{
	*line = ft_strrealloc(*line, ft_strlen(*line) + n);
	ft_strncat(*line, rest, n);
	ft_strcpy(rest, rest + n + 1);
}

int		get_next_line(const int fd, char **line)
{
	static char		rest[BUFF_SIZE + 1];
	int				n;
	int				ret;

	if (BUFF_SIZE < 1 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	*line = ft_strnew(0);
	if (n_index(rest, &n) != -1)
	{
		copy_rest_to_n(line, &rest[0], n);
		return (1);
	}
	if (ft_strlen(rest) > 0)
		copy_rest(line, rest);
	while ((ret = read(fd, rest, BUFF_SIZE)) && (n_index(rest, &n) != -1))
	{
		rest[ret] = '\0';
		n != -1 ? copy_rest_to_n(line, &rest[0], n) : copy_rest(line, &rest[0]);
		if (n != -1)
			return (1);
	}
	n != -1 ? copy_rest_to_n(line, &rest[0], n) : copy_rest(line, &rest[0]);
	ret += ft_strlen(*line);
	return (ret > 0);
}
