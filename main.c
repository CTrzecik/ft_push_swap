#include "push_swap.h"
#include <stdio.h>

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
	t_list		*temp;

	stack_a = NULL;
	stack_b = NULL;
	idx = 1;
	if (argc == 1)
		exit(1);
	selector = strategy_selector(argv[1]);
	if (selector != DEFAULT)
		idx = 2;
	fill_stack_a(argc, argv, &stack_a, idx);
	printf("sel: %lu\n", selector);
    printf("\nstack_a: disorder[%.2f]\n\n", disorder(&stack_a, ft_lstsize(stack_a)));
    simple_algorithm(&stack_a, &stack_b);
	while (stack_a)
	{
		temp = stack_a->next;
		printf("%d\n", *((int *)stack_a->content));
		ft_lstdelone(stack_a, &free);
		stack_a = temp;
	}
    // printf("\nstack_b\n\n");
    // while (stack_b)
	// {
	// 	temp = stack_b->next;
	// 	printf("%d\n", *((int *)stack_b->content));
	// 	ft_lstdelone(stack_b, &free);
	// 	stack_b = temp;
	// }
	return (0);
}
