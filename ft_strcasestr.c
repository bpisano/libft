/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:48:48 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/13 11:52:24 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(char const *haystack, char const *needle)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (ft_tolower(str[i + j]) == ft_tolower(needle[j]))
		{
			if (needle[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
