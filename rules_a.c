/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:40:16 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/25 14:10:44 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a, t_benchmark *bm)
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
	print_count_ops(&(bm->total_ops), &(bm->sa_ops), "sa");
}

void	pa(t_list **a, t_list **b, t_benchmark *bm)
{
	t_list	*top;

	if (!b || !*b)
		return ;
	top = *b;
	*b = top->next;
	ft_lstadd_front(a, top);
	print_count_ops(&(bm->total_ops), &(bm->pa_ops), "pa");
}

void	ra(t_list **a, t_benchmark *bm)
{
	t_list	*first;

	if (!a || !*a)
		return ;
	first = *a;
	ft_lstlast(*a)->next = first;
	*a = first->next;
	first->next = NULL;
	print_count_ops(&(bm->total_ops), &(bm->ra_ops), "ra");
}

void	rra(t_list **a, t_benchmark *bm)
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
	print_count_ops(&(bm->total_ops), &(bm->rra_ops), "rra");
}
