/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 21:08:49 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 16:38:30 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!(new = malloc(size)))
		return (NULL);
	if (size)
		ft_memcpy(new, ptr, size);
	ft_memdel(&ptr);
	return (new);
}
