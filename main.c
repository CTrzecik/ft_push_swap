#include "push_swap.h"

void	fill_stack_a(char **argv, t_stack *stack_a, size_t idx)
{
	while (*argv)
	{
		/* Something */
	}
}

int	main(int argc, char **argv)
{
	size_t		selector;
	size_t		index;
	t_stack		*stack_a;
	t_stack		*stack_b;

	index = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 0)
		error();
	selector = stratsel_verif(argv[1]);
	if (selector != DEFAULT)
		index = 2;
	fill_stack_a(argv, stack_a, index);
	return (0);
}
