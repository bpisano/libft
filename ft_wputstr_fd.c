/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wputstr_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 15:01:45 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 15:05:12 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_wputstr_fd(wchar_t *str, int fd)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_wputchar_fd(str[i], fd);
		i++;
	}
}
