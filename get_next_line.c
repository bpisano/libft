/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 11:52:58 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 16:49:07 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		n_index(const char *str)
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

static t_list	*current_file(int fd, t_list **list)
{
	if (!*list)
	{
		*list = ft_lstnew(NULL, 0);
		(*list)->content_size = fd;
		return (*list);
	}
	if ((*list)->content_size != (size_t)fd)
		return (current_file(fd, &(*list)->next));
	return (*list);
}

static int		read_rest(char **rest, char **line)
{
	int		n;

	if ((n = n_index(*rest)) == -1)
		return (0);
	*line = ft_strsub(*rest, 0, n);
	*rest += n + 1;
	return (1);
}

static int		read_buff(int fd, char **rest)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				char_count;
	int				n;
	int				r;

	r = 0;
	while ((char_count = read(fd, buff, BUFF_SIZE)))
	{
		r = 1;
		buff[char_count] = '\0';
		tmp = *rest;
		*rest = ft_strjoin(tmp, buff);
		free(tmp);
		if ((n = n_index(*rest)) != -1)
			break ;
	}
	return (r);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file_lst;
	t_list			*file;
	int				r;

	if (!line || BUFF_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (-1);
	file = current_file(fd, &file_lst);
	if (read_rest((char **)&(file->content), line))
		return (1);
	if (!file->content)
		file->content = ft_strdup("");
	else
		file->content = ft_strdup((char *)(file->content));
	r = read_buff(fd, (char **)&(file->content));
	//if (!r && ft_strlen(file->content))
		//r = 1;
	if (read_rest((char **)&(file->content), line))
		return (1);
	*line = (char *)(file->content);
	return (r);
}
