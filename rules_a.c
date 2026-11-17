/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:40:16 by ctrzecik          #+#    #+#             */
<<<<<<< HEAD:rules_a.c
/*   Updated: 2026/11/17 14:02:13 by dibranco         ###   ########.fr       */
=======
/*   Updated: 2026/11/16 17:00:48 by ctrzecik         ###   ########.fr       */
>>>>>>> 77b3ab6949711a0ad81bd530b11884f707754849:functions.c
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

<<<<<<< HEAD:rules_a.c
=======
void	pb(t_list **a, t_list **b)
{
	t_list	*top;

	if (!a || !*a)
		return ;
	top = *a;
	*a = top->next;
	ft_lstadd_front(b, top);
}

>>>>>>> 77b3ab6949711a0ad81bd530b11884f707754849:functions.c
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
