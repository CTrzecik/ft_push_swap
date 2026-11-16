/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:20:51 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/13 16:20:52 by ctrzecik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	size_nbr(long nb, char *buf, int i)
{
	while (nb > 0)
	{
		buf[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	buf[11];
	long	nb;
	int		i;
	int		len;

	nb = n;
	len = 0;
	i = 0;
	if (nb == 0)
		buf[i++] = '0';
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb = -nb;
		len = 1;
	}
	i = size_nbr(nb, buf, i);
	len += i;
	while (i > 0)
	{
		if (ft_putchar(buf[--i]) == -1)
			return (-1);
	}
	return (len);
}
