/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddallas <ddallas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:19:28 by ddallas           #+#    #+#             */
/*   Updated: 2019/05/24 18:04:01 by ddallas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t		i;
	long long	n;
	int			neg;

	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	neg = 0;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	n = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10;
		if (n > n * 10)
			return (neg == 0 ? -1 : 0);
		n = n + str[i] - '0';
		i++;
	}
	if (neg == 1)
		n = n * -1;
	return (n);
}
