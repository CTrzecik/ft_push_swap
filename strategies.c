/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:31:36 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/16 15:59:01 by ctrzecik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    simple_algorithm(t_list **a, t_list **b)
{
    // t_list  *save_a;
    // t_list  *save_b;

    // save_a = a;
	// save_b = b;
	pb(a, b);
    while(*a)
	{
		pb(a, b);
		if (*(int *)(*b)->content > *(int *)(*b)->next->content)
		{
			sb(b);
		}
		else
			*b = (*b)->next;
	}
}
