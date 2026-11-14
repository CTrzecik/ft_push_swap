#include "push_swap.h"
#include <stdio.h>

void	fill_stack_a(int argc, char **argv, t_list **stack_a, int idx)
{
	int		*num;
	t_list	*nw;

	while (idx < argc)
	{
		if (check_num(argv[idx]))
		{
			ft_lstclear(stack_a, &free);
			error();
		}
		else
		{
			num = (int *)malloc(sizeof(int));
			if (!num)
				error();
			*num = ft_atoi(argv[idx]);
			nw = ft_lstnew(num);
			ft_lstadd_back(stack_a, nw);
		}
		idx++;
	}
	ft_lstadd_back(stack_a, NULL);
}

int	main(int argc, char **argv)
{
	size_t		selector;
	int			idx;
	t_list		*stack_a;
	//t_list		*stack_b;
	t_list		*temp;

	stack_a = NULL;
	idx = 1;
	if (argc == 1)
		error();
	selector = strategy_selector(argv[1]);
	if (selector != DEFAULT)
		idx = 2;
	fill_stack_a(argc, argv, &stack_a, idx);
	while (stack_a)
	{
		temp = stack_a->next;
		printf("%d\n", *((int *)stack_a->content));
		ft_lstdelone(stack_a, &free);
		stack_a = temp;
	}
	return (0);
}
