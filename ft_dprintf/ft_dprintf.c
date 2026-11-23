/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:59:04 by dibranco          #+#    #+#             */
/*   Updated: 2026/11/23 14:24:41 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

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
