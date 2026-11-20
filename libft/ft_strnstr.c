/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:40:14 by dibranco          #+#    #+#             */
/*   Updated: 2026/11/06 12:16:58 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_i;
	size_t	lit_i;

	big_i = 0;
	lit_i = 0;
	if (!big || !little)
		return (NULL);
	if (!ft_strlen(little))
		return ((char *)big);
	while (big_i < len && big[big_i])
	{
		while (big[big_i + lit_i] == little[lit_i]
			&& big_i + lit_i < len && big[big_i + lit_i])
			lit_i++;
		if (little[lit_i] == '\0')
			return ((char *)&big[big_i]);
		else
			lit_i = 0;
		big_i++;
	}
	return (NULL);
}
