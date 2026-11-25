/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 10:14:39 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/25 14:10:28 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(t_list **a)
{
	t_list	*first;
	t_list	*second;
	int		mistakes;
	int		total_pairs;

	first = *a;
	mistakes = 0;
	total_pairs = 0;
	while (first && first->next)
	{
		second = first->next;
		while (second)
		{
			total_pairs++;
			if (*(int *)first->content > *(int *)second->content)
				mistakes++;
			second = second->next;
		}
		first = first->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
}
