/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddallas <ddallas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:35:36 by ddallas           #+#    #+#             */
/*   Updated: 2019/05/31 23:13:53 by ddallas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	char	*newstr;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	while (s[i])
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	i = (i - start < 0) ? start - 1 : i;
	if (!(newstr = (char*)malloc(sizeof(char) * (i - start + 2))))
		return (NULL);
	newstr[i - start + 1] = '\0';
	while (i - start + 1 > 0)
	{
		newstr[i - start] = s[i];
		i--;
	}
	return (newstr);
}
