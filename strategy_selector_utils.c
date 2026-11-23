#include "push_swap.h"

bool	isbenchmark(const char *s)
{
	if (!s)
		error();
	if (!ft_strcmp(s, "--bench"))
		return (TRUE);
	return (FALSE);
}

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

void	call_algorithm(t_benchmark *bm, t_list **stack_a, t_list **stack_b)
{
	if (bm->selector == SIMPLE)
		simple_algorithm(stack_a, stack_b, bm);
	else if (bm->selector == MEDIUM)
		medium_algorithm(stack_a, stack_b, bm);
	else if (bm->selector == COMPLEX)
		complex_algorithm(stack_a, stack_b, bm);
	else if (bm->selector == ADAPTIVE || bm->selector == DEFAULT)
		adaptive_algorithm(stack_a, stack_b, bm);
}
