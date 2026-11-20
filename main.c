#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t		selector;
	bool		benchmark_mode;
	int			idx;
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	idx = 1;
	if (argc == 1)
		return (1);
	benchmark_mode = isbenchmark(argv[idx]);
	if (benchmark_mode)
		idx++;
	selector = strategy_selector(argv[idx]);
	if (selector != DEFAULT)
		idx++;
	fill_stack_a(argc, argv, &stack_a, idx);
	call_algorithm(selector, &stack_a, &stack_b);
	if (benchmark_mode)
		benchmark_output();
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
	return (0);
}
