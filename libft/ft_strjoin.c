/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 08:47:54 by dibranco          #+#    #+#             */
/*   Updated: 2026/11/06 12:10:23 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*strj;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strj = (char *)malloc(s1_len + s2_len + 1);
	if (!strj)
		return (NULL);
	ft_strlcpy(strj, s1, s1_len + 1);
	ft_strlcpy(&strj[s1_len], s2, s2_len + 1);
	return (strj);
}
