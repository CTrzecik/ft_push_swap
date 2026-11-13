#include "push_swap.h"

size_t	stratsel_verif(const char *s)
{
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

void	stratsel(const char *s, t_stack stack_a, t_stack stack_b)
{
	/*if (!ft_strcmp(s, "--simple"))
	else if (!ft_strcmp(s, "--medium"))
	else if (!ft_strcmp(s, "--complex"))
	else if (!ft_strcmp(s, "--adaptive"))*/
}
