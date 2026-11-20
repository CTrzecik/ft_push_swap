/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:44:46 by dibranco          #+#    #+#             */
/*   Updated: 2026/11/06 14:47:08 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numdigit(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	len;
	long	l;

	l = n;
	len = numdigit(l);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	if (l < 0)
		l = -l;
	ptr[len] = '\0';
	while (len > 0)
	{
		ptr[--len] = l % 10 + '0';
		l /= 10;
	}
	if (n < 0)
		ptr[len] = '-';
	return (ptr);
}
