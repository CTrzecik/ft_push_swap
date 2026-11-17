/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:31:36 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/16 17:14:15 by ctrzecik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    simple_algorithm(t_list **a, t_list **b)
{
	t_list	*save_b;

	
	while(disorder(a, ft_lstsize(*a)) != 0)
	{
		pb(a, b);
		save_b = *b;
		while(*a)
		{
			pb(a, b);
			if (*(int *)(*b)->content < *(int *)(*b)->next->content)
			{
				sb(b);
			}
		}
		*b = save_b;
		while(*b)
			pa(a, b);
		ra(a);
	}
}
