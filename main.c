#include "push_swap.h"

void	fill_stack_a(int argc, char **argv, t_list **stack_a, int idx)
{
	int		*num;

	while (idx < argc)
	{
		if (!isdigit_str(argv[idx])
			|| !is_within_int_limit(ft_atol(argv[idx]))
			|| isrepeat(ft_atol(argv[idx]), *stack_a))
		{
			ft_lstclear(stack_a, &free);
			error();
		}
		num = (int *)malloc(sizeof(int));
		if (!num)
			error();
		*num = ft_atol(argv[idx]);
		ft_lstadd_back(stack_a, ft_lstnew(num));
		idx++;
	}
	ft_lstadd_back(stack_a, NULL);
}

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
