/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:59:04 by dibranco          #+#    #+#             */
/*   Updated: 2026/11/20 15:42:26 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	base16(int fd, unsigned long l, char *base, size_t count)
{
	int	qnt;

	qnt = 0;
	if (l == 0 && count == 0)
	{
		write(1, "0", 1);
		return (++qnt);
	}
	else if (l != 0)
	{
		qnt += base16(fd, l / 16, base, ++count);
		write(fd, &base[l % 16], 1);
		qnt++;
	}
	return (qnt);
}

static int	address(int fd, const void *s)
{
	unsigned long	ptr;
	int				qnt;

	qnt = 0;
	if (!s)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	ptr = (unsigned long)s;
	write(1, "0x", 2);
	qnt += 2;
	qnt += base16(fd, ptr, BASEHEXL, 0);
	return (qnt);
}

int	format(int fd, const char c, va_list args)
{
	int	qnt;

	qnt = 0;
	if (c == CHAR)
		qnt += ft_putchar(fd, va_arg(args, int));
	else if (c == STR)
		qnt += ft_putstr(fd, va_arg(args, char *));
	else if (c == POINTER)
		qnt += address(fd, va_arg(args, void *));
	else if (c == DEC || c == INT)
		qnt += ft_putnbr(fd, va_arg(args, int));
	else if (c == UDEC)
		qnt += ft_putnbru(fd, va_arg(args, int));
	else if (c == HEXL)
		qnt += base16(fd, va_arg(args, unsigned int), BASEHEXL, 0);
	else if (c == HEXU)
		qnt += base16(fd, va_arg(args, unsigned int), BASEHEXU, 0);
	else if (c == PERCENT)
		qnt += ft_putchar(fd, '%');
	else
	{
		qnt += ft_putchar(fd, '%');
		qnt += ft_putchar(fd, c);
	}
	return (qnt);
}

static int	print(int fd, const char *s, va_list args)
{
	int	qnt_of_chars;
	int	index;

	index = 0;
	qnt_of_chars = 0;
	while (s[index])
	{
		if (s[index] == PERCENT && s[index + 1])
		{
			qnt_of_chars += format(fd, s[index + 1], args);
			index += 2;
		}
		else
		{
			write(fd, s + index, 1);
			qnt_of_chars++;
			index++;
		}
	}
	return (qnt_of_chars);
}

int	ft_dprintf(int fd, const char *s, ...)
{
	va_list	args;
	int		qnt_of_chars;

	if (!s)
		return (ERROR);
	va_start(args, s);
	qnt_of_chars = print(fd, s, args);
	va_end(args);
	return (qnt_of_chars);
}
