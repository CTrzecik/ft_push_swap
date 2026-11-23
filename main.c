#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			idx;
	t_list		*stack_a;
	t_list		*stack_b;
	t_benchmark	bm;

	stack_a = NULL;
	stack_b = NULL;
	idx = 1;
	if (argc == 1)
		return (1);
	init_bench(&bm);
	bm.benchmark_mode = isbenchmark(argv[idx]);
	if (bm.benchmark_mode)
		idx++;
	bm.selector = strategy_selector(argv[idx]);
	if (bm.selector != DEFAULT)
		idx++;
	fill_stack_a(argc, argv, &stack_a, idx);
	bm.disorder = disorder(&stack_a);
	call_algorithm(&bm, &stack_a, &stack_b);
	if (bm.benchmark_mode)
		benchmark_output(bm);
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
	return (0);
}
