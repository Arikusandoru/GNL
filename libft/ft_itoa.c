/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddallas <ddallas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:53:46 by ddallas           #+#    #+#             */
/*   Updated: 2019/05/31 15:14:46 by ddallas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	i;
	int		neg;
	char	*str;
	int		var;

	neg = (n >= 0) ? 0 : 1;
	i = 1;
	n = n * ((n >= 0) ? -1 : 1);
	var = n;
	while (var > 9 || var < -9)
	{
		var = var / 10;
		++i;
	}
	if (!(str = (char*)malloc(sizeof(char) * (i + neg + 1))))
		return (NULL);
	str[i + neg] = '\0';
	while (i > 0)
	{
		str[--i + neg] = -(n % 10) + '0';
		n = n / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
