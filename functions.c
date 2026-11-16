/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:40:16 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/16 13:47:09 by ctrzecik         ###   ########.fr       */
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

void	sb(t_list **b)
{
	t_list	*first;
	t_list	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}

void	pa(t_list **a, t_list **b)
{
	if(!b)
		return ;
	ft_lstadd_front(a, *b);
}

void	pb(t_list **a, t_list **b)
{
	t_list *new;
	if(!a)
		return ;
	new = ft_lstnew((*a)->content);
	ft_lstadd_front(b, new);
}

void	ra(t_list **a)
{
	if(!a)
		return ;
	t_list *last_addres;
	t_list *first;
	
	last_addres = ft_lstlast(*a);
	first = *a;
	last_addres->next = first;
	*a = first->next;
	first->next = NULL;
}

void	rb(t_list **b)
{
	t_list *last_addres;
	t_list *first;
	if(!b)
		return ;
	last_addres = ft_lstlast(*b);
	first = *b;
	last_addres->next = first;
	*b = first->next;
	first->next = NULL;
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
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

void	rrb(t_list **b)
{
	t_list	*prev;
	t_list	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	prev = *b;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *b;
	*b = last;
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}