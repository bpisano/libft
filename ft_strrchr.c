/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:13:58 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/09 15:31:33 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	*ret;

	i = 0;
	str = (char *)s;
	ret = NULL;
	while (str[i])
	{
		if (str[i] == (char)c)
			ret = &str[i];
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (ret);
}
