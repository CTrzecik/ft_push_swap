/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:07:41 by dibranco          #+#    #+#             */
/*   Updated: 2026/11/23 14:25:43 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# define BASEHEXL "0123456789abcdef"
# define BASEHEXU "0123456789ABCDEF"
# define ERROR -1

# include <unistd.h>
# include <stdarg.h>

typedef enum e_fs
{
	CHAR = 'c',
	STR = 's',
	POINTER = 'p',
	DEC = 'd',
	INT = 'i',
	UDEC = 'u',
	HEXL = 'x',
	HEXU = 'X',
	FLOAT = 'f',
	PERCENT = '%'
}	t_fs;

int	ft_dprintf(int fd, const char *s, ...);

int	ft_putchar(int fd, const char c);

int	ft_putstr(int fd, const char *s);

int	ft_putnbr(int fd, const int n);

int	ft_putnbru(int fd, const unsigned int n);

int	base16(int fd, unsigned long l, char *base, size_t count);

int	address(int fd, const void *s);

int	format(int fd, const char c, va_list args);

int	print(int fd, const char *s, va_list args);

#endif
