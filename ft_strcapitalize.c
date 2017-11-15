/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:27:26 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/13 11:15:28 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	int		i;

	i = 0;
	if (ft_islower(s[i]))
		s[i] = ft_toupper(s[i]);
	i = 1;
	while (s[i])
	{
		s[i] = ft_tolower(s[i]);
		if (ft_islower(s[i]) &&
			!ft_isdigit(s[i - 1]) &&
			!ft_islower(s[i - 1]) &&
			!ft_isupper(s[i - 1]))
			s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}
