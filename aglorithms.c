/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aglorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:31:36 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/17 14:09:45 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_algorithm(t_list **a, t_list **b)
{
	t_list	**cur;
	int		*first;
	int		*second;
	size_t	len;

	if (!a || !*a)
		return ;
	cur = a;
	len = ft_lstsize(*cur);
	while (len--)
	{
		while (*cur && (*cur)->next)
		{
			first = (*cur)->content;
			second = (*cur)->next->content;
			if (*first < *second)
				sa(cur);
			cur = &(*cur)->next;
		}
		pb(cur, b);
		cur = a;
	}
	len = ft_lstsize(*b);
	while (len--)
		pa(a, b);
}

void	medium_algorithm(t_list **a, t_list **b)
{
	(void)a;
	(void)b;
	return ;
}

void	complex_algorithm(t_list **a, t_list **b)
{
	(void)a;
	(void)b;
	return ;
}
