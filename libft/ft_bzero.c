/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 16:56:03 by dibranco          #+#    #+#             */
/*   Updated: 2026/11/06 12:06:59 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *a, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	if (!a)
		return ;
	ptr = (unsigned char *)a;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
