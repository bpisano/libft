/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wputchar.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 13:57:32 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 14:55:37 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_wputchar(wchar_t c)
{
	ft_wputchar_fd(c, 1);
}
