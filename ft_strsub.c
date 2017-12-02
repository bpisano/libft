/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:38:45 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 13:38:46 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t size)
{
	unsigned int	i;
	char			*str;
	char			*cpy;

	if (!s)
		return (NULL);
	if (!(cpy = ft_memalloc(size + 1)))
		return (NULL);
	i = 0;
	str = (char *)s;
	while (i < start)
	{
		str++;
		i++;
	}
	ft_strncpy(cpy, str, size);
	return (cpy);
}
