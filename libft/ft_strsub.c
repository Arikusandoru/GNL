/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddallas <ddallas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:10:44 by ddallas           #+#    #+#             */
/*   Updated: 2019/05/24 18:34:12 by ddallas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (s)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			newstr[i] = s[start + i];
			i++;
		}
		newstr[i] = '\0';
		return (newstr);
	}
	return (NULL);
}
