/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddallas <ddallas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 19:12:23 by ddallas           #+#    #+#             */
/*   Updated: 2019/06/01 17:32:48 by ddallas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_zero(int start, int end, char **strarr)
{
	if (end == start)
	{
		strarr[0] = NULL;
		return (0);
	}
	return (1);
}

static	int		ft_words(const char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			words++;
		i++;
	}
	return (words);
}

static	char	*ft_filler(char const *s, int start, int end)
{
	int		i;
	char	*newstr;

	if (!(newstr = (char*)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**strarr;

	if (!s || !(strarr = (char**)malloc(sizeof(strarr) * (ft_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (!(ft_check_zero(start, i, strarr)))
			return (strarr);
		strarr[j] = ft_filler(s, start, i);
		j++;
		while (s[i] == c)
			i++;
	}
	strarr[j] = NULL;
	return (strarr);
}
