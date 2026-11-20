#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t		selector;
	int			idx;
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	idx = 1;
	if (argc == 1)
		exit(1);
	selector = strategy_selector(argv[1]);
	if (selector != DEFAULT)
		idx = 2;
	fill_stack_a(argc, argv, &stack_a, idx);
	call_algorithm(selector, &stack_a, &stack_b);
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
	return (0);
}
