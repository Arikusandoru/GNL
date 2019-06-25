/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddallas <ddallas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:16:34 by ddallas           #+#    #+#             */
/*   Updated: 2019/05/18 14:56:09 by ddallas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	j = 0;
	while (haystack[j])
	{
		i = 0;
		while (needle[i] == haystack[j + i])
		{
			if (needle[i + 1] == '\0')
				return ((char*)haystack + j);
			i++;
		}
		j++;
	}
	return (NULL);
}
