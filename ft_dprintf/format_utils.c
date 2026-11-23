#include "ft_dprintf.h"

int putfloat(int fd, double num)
{
	int		qnt;

	qnt = 0;
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
		qnt++;
	}
	if (num >= 10)
		qnt += ft_putnbr(fd, num / 10);
	qnt += ft_putchar(fd, ((int)num % 10) + '0');
	qnt += ft_putchar(fd, '.');
	qnt += ft_putnbr(fd, (int)(num * 10) % 10);
	qnt += ft_putnbr(fd, (int)(num * 100) % 10);
	return (qnt);
}

int	base16(int fd, unsigned long l, char *base, size_t count)
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

int	address(int fd, const void *s)
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
	if (c == CHAR)
		return (ft_putchar(fd, va_arg(args, int)));
	else if (c == STR)
		return (ft_putstr(fd, va_arg(args, char *)));
	else if (c == POINTER)
		return (address(fd, va_arg(args, void *)));
	else if (c == DEC || c == INT)
		return (ft_putnbr(fd, va_arg(args, int)));
	else if (c == UDEC)
		return (ft_putnbru(fd, va_arg(args, int)));
	else if (c == HEXL)
		return (base16(fd, va_arg(args, unsigned int), BASEHEXL, 0));
	else if (c == HEXU)
		return (base16(fd, va_arg(args, unsigned int), BASEHEXU, 0));
	else if (c == PERCENT)
		return (ft_putchar(fd, '%'));
	else if (c == FLOAT)
		return (putfloat(fd, va_arg(args, double)));
	else
		return (ft_putchar(fd, '%'), ft_putchar(fd, c), 2);
}

int	print(int fd, const char *s, va_list args)
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

