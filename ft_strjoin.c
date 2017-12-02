/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:31:58 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 13:32:00 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	return (join);
}
