/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 16:46:20 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/06 16:52:40 by ctrzecik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	char			buf[11];
	unsigned long	nb;
	int				i;
	int				len;

	nb = n;
	len = 0;
	i = 0;
	if (nb == 0)
		buf[i++] = '0';
	while (nb > 0)
	{
		buf[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	len += i;
	while (i > 0)
	{
		if (ft_putchar(buf[--i]) == -1)
			return (-1);
	}
	return (len);
}
