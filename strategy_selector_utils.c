#include "push_swap.h"

size_t	strategy_selector(const char *s)
{
	if (!s)
		error();
	if (!ft_strcmp(s, "--simple"))
		return (SIMPLE);
	else if (!ft_strcmp(s, "--medium"))
		return (MEDIUM);
	else if (!ft_strcmp(s, "--complex"))
		return (COMPLEX);
	else if (!ft_strcmp(s, "--adaptive"))
		return (ADAPTIVE);
	else
		return (DEFAULT);
}

void	call_algorithm(const size_t selector, t_list **stack_a, t_list **stack_b)
{
	if (selector == SIMPLE)
		simple_algorithm(stack_a, stack_b);
	else if (selector == MEDIUM)
		medium_algorithm(stack_a, stack_b);
	else if (selector == COMPLEX)
		complex_algorithm(stack_a, stack_b);
	else if (selector == ADAPTIVE || selector == DEFAULT)
		simple_algorithm(stack_a, stack_b);
}
