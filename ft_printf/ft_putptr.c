/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:20:26 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/13 16:20:27 by ctrzecik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_hex_long(unsigned long nbr)
{
	char	buf[16];
	char	*base;
	int		i;
	int		size;

	base = "0123456789abcdef";
	i = 0;
	if (nbr == 0)
		buf[i++] = '0';
	while (nbr > 0)
	{
		buf[i++] = base[nbr % 16];
		nbr /= 16;
	}
	size = i;
	while (i > 0)
	{
		if (ft_putchar(buf[--i]) == -1)
			return (-1);
	}
	return (size);
}

int	ft_putptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	len = ft_putnbr_hex_long((unsigned long)ptr);
	if (len == -1)
		return (-1);
	return (len + 2);
}
