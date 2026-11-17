/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 10:14:39 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/16 16:08:11 by ctrzecik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(t_list **a, int size)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;
    
	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i <= size - 1)
	{
		j = i + 1;
		while (j <= size - 1)
		{
			total_pairs++;
			if (*(int *)(*a)->content > *(int *)(*a)->next->content)
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total_pairs);
}
