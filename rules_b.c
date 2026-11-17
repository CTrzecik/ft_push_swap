#include "push_swap.h"

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

void	pb(t_list **a, t_list **b)
{
	t_list	*top;

	if (!a || !*a || !b)
		return ;
	top = *a;
	*a = top->next;
	ft_lstadd_front(b, top);
}

void	rb(t_list **b)
{
	t_list *first;

	if (!b)
		return ;
	first = *b;
	ft_lstlast(*b)->next = first;
	*b = first->next;
	first->next = NULL;
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
