/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddallas <ddallas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:10:34 by ddallas           #+#    #+#             */
/*   Updated: 2019/05/22 15:56:22 by ddallas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*newstr;

	i = 0;
	if (s && f)
	{
		while (s[i])
			i++;
		if (!(newstr = (char*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			newstr[i] = f(s[i]);
			i++;
		}
		newstr[i] = '\0';
		return (newstr);
	}
	return (NULL);
}
