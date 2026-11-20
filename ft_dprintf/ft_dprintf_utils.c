/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 08:16:33 by dibranco          #+#    #+#             */
/*   Updated: 2026/11/20 15:46:53 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_putchar(int fd, const char c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr(int fd, const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
		i++;
	write(fd, s, i);
	return (i);
}

int	ft_putnbr(int fd, const int n)
{
	long	l;
	int		qnt;

	qnt = 0;
	l = n;
	if (l < 0)
	{
		l = -l;
		write(fd, "-", 1);
		qnt++;
	}
	if (l >= 10)
		qnt += ft_putnbr(fd, l / 10);
	qnt += ft_putchar(fd, (l % 10) + '0');
	return (qnt);
}

int	ft_putnbru(int fd, const unsigned int n)
{
	unsigned long	l;
	int				qnt;

	qnt = 0;
	l = n;
	if (l >= 10)
		qnt += ft_putnbr(fd, l / 10);
	qnt += ft_putchar(fd, (l % 10) + '0');
	return (qnt);
}
