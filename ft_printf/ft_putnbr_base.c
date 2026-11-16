/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 16:46:20 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/06 17:53:35 by ctrzecik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	char	buf[8];
	int		i;
	int		size;

	i = 0;
	if (nbr == 0)
		buf[i++] = base[0];
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
