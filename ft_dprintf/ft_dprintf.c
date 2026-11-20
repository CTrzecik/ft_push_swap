/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:59:04 by dibranco          #+#    #+#             */
/*   Updated: 2026/11/20 14:59:30 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	base16(unsigned long l, char *base, size_t count)
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
		qnt += base16(l / 16, base, ++count);
		write(1, &base[l % 16], 1);
		qnt++;
	}
	return (qnt);
}

int	address(const void *s)
{
	unsigned long	ptr;
	int				qnt;

	qnt = 0;
	if (!s)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ptr = (unsigned long)s;
	write(1, "0x", 2);
	qnt += 2;
	qnt += base16(ptr, BASEHEXL, 0);
	return (qnt);
}

int	format(const char c, va_list args)
{
	int	qnt;

	qnt = 0;
	if (c == CHAR)
		qnt += ft_putchar(va_arg(args, int));
	else if (c == STR)
		qnt += ft_putstr(va_arg(args, char *));
	else if (c == POINTER)
		qnt += address(va_arg(args, void *));
	else if (c == DEC || c == INT)
		qnt += ft_putnbr(va_arg(args, int));
	else if (c == UDEC)
		qnt += ft_putnbru(va_arg(args, int));
	else if (c == HEXL)
		qnt += base16(va_arg(args, unsigned int), BASEHEXL, 0);
	else if (c == HEXU)
		qnt += base16(va_arg(args, unsigned int), BASEHEXU, 0);
	else if (c == PERCENT)
		qnt += ft_putchar('%');
	else
	{
		qnt += ft_putchar('%');
		qnt += ft_putchar(c);
	}
	return (qnt);
}

int	print(const char *s, va_list args)
{
	int	qnt_of_chars;
	int	index;

	index = 0;
	qnt_of_chars = 0;
	while (s[index])
	{
		if (s[index] == PERCENT && s[index + 1])
		{
			qnt_of_chars += format(s[index + 1], args);
			index += 2;
		}
		else
		{
			write(1, s + index, 1);
			qnt_of_chars++;
			index++;
		}
	}
	return (qnt_of_chars);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		qnt_of_chars;

	if (!s)
		return (ERROR);
	va_start(args, s);
	qnt_of_chars = print(s, args);
	va_end(args);
	return (qnt_of_chars);
}
