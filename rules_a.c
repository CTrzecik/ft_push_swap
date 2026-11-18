/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:40:16 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/18 08:41:57 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	pa(t_list **a, t_list **b)
{
	t_list	*top;

	if (!b || !*b)
		return ;
	top = *b;
	*b = top->next;
	ft_lstadd_front(a, top);
}

void	ra(t_list **a)
{
	t_list *first;

	if (!a || !*a)
		return ;
	first = *a;
	ft_lstlast(*a)->next = first;
	*a = first->next;
	first->next = NULL;
}

void	rra(t_list **a)
{
	t_list	*prev;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = *a;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *a;
	*a = last;
}
