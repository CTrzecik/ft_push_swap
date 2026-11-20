/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:07:41 by dibranco          #+#    #+#             */
/*   Updated: 2026/11/20 14:59:23 by dibranco         ###   ########.fr       */
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
	PERCENT = '%'
}	t_fs;

int	ft_printf(const char *s, ...);

int	ft_putchar(const char c);

int	ft_putstr(const char *s);

int	ft_putnbr(const int n);

int	ft_putnbru(const unsigned int n);

#endif
