/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:19:58 by dibranco          #+#    #+#             */
/*   Updated: 2026/11/01 18:37:50 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	qnt;

	qnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			qnt++;
		while (*s && *s != c)
			s++;
	}
	return (qnt);
}

static size_t	word_len(char const *s, char c)
{
	char const	*start;

	start = s;
	while (*s && *s != c)
		s++;
	return ((size_t)s - (size_t)start);
}

static void	free_nwstr(char **nwstr, size_t i)
{
	while (i-- > 0)
		free(nwstr[i]);
	free(nwstr);
}

static char	*cpy_word(char **nwstr, size_t idx, char const *s, size_t len)
{
	nwstr[idx] = (char *)malloc(len + 1);
	if (!nwstr[idx])
	{
		free_nwstr(nwstr, idx);
		return (NULL);
	}
	ft_memcpy(nwstr[idx], s, len);
	nwstr[idx][len] = '\0';
	return (nwstr[idx]);
}

char	**ft_split(char const *s, char c)
{
	char	**nwstr;
	size_t	wordc;
	size_t	wordl;
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	wordc = count_words(s, c);
	nwstr = malloc((wordc + 1) * sizeof(char *));
	if (!nwstr)
		return (NULL);
	while (++i < wordc)
	{
		while (*s == c)
			s++;
		wordl = word_len(s, c);
		if (!cpy_word(nwstr, i, s, wordl))
			return (NULL);
		s += wordl;
	}
	nwstr[wordc] = NULL;
	return (nwstr);
}
