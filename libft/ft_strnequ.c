/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddallas <ddallas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:06:32 by ddallas           #+#    #+#             */
/*   Updated: 2019/05/31 21:16:07 by ddallas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (!s1 || !s2)
		return (0);
	if (!n)
		return (1);
	i = 0;
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((s1[i] - s2[i]) == 0 ? 1 : 0);
	}
	return ((s1[i] - s2[i]) == 0 ? 1 : 0);
}
