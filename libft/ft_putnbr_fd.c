/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddallas <ddallas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:14:05 by ddallas           #+#    #+#             */
/*   Updated: 2019/06/01 14:50:16 by ddallas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 10 || n <= -10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(((n % 10) * (-1 + 2 * (n > 0)) + '0'), fd);
	}
	else
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		ft_putchar_fd(((n % 10) * (-1 + 2 * (n > 0)) + '0'), fd);
	}
}
