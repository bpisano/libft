/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:13:56 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/07 18:34:07 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t size)
{
	unsigned int	i;
	char			*str;
	char			*cpy;

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
