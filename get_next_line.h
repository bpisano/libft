/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 11:53:15 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 15:46:47 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 10

typedef struct		s_fd
{
	int				fd;
	char			*rest;
	struct s_fd		*next;
}					t_fd;

int		get_next_line(const int fd, char **line);
#endif
