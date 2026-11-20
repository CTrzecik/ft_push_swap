/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 08:16:33 by dibranco          #+#    #+#             */
/*   Updated: 2026/11/20 14:59:36 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

int	ft_putnbr(const int n)
{
	long	l;
	int		qnt;

	qnt = 0;
	l = n;
	if (l < 0)
	{
		l = -l;
		write(1, "-", 1);
		qnt++;
	}
	if (l >= 10)
		qnt += ft_putnbr(l / 10);
	qnt += ft_putchar((l % 10) + '0');
	return (qnt);
}

int	ft_putnbru(const unsigned int n)
{
	unsigned long	l;
	int				qnt;

	qnt = 0;
	l = n;
	if (l >= 10)
		qnt += ft_putnbr(l / 10);
	qnt += ft_putchar((l % 10) + '0');
	return (qnt);
}
