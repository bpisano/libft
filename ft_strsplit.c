/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 22:54:38 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/14 19:29:08 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_words_count(const char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
		i++;
	}
	if (str[0] != '\0')
		count++;
	return (count);
}

static	char	*ft_fill_word(const char *str, char c, int *i)
{
	char	*word;
	int		j;

	if (!(word = (char *)malloc(sizeof(char) * (ft_strlen(str)))))
		return (NULL);
	j = 0;
	while (str[*i] != c && str[*i])
	{
		word[j] = str[*i];
		(*i)++;
		j++;
	}
	word[j] = '\0';
	while (str[*i] == c && str[*i])
		(*i)++;
	return (word);
}

char			**ft_strsplit(const char *str, char c)
{
	char	**words;
	int		i;
	int		j;
	int		w_count;

	i = 0;
	j = 0;
	w_count = ft_words_count(str, c);
	if (!(words = (char **)malloc(sizeof(char *) * (w_count + 2))) || !str)
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (j < w_count && str[i])
	{
		words[j] = ft_fill_word(str, c, &i);
		j++;
	}
	words[j] = NULL;
	return (words);
}
