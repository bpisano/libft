/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:47:44 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/15 13:22:59 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		begin;
	int		end;
	char	*trim;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	begin = 0;
	end = len;
	while (ft_isspace(s[begin]))
		begin++;
	while (ft_isspace(s[end - 1]))
		end--;
	if (end - begin <= 0)
		return (ft_strdup(""));
	trim = ft_strsub(s, begin, end - begin);
	return (trim);
}
