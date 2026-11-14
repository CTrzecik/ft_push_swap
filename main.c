#include "push_swap.h"
#include <stdio.h>

void	fill_stack_a(int argc, char **argv, t_list *stack_a, int idx)
{
	int		*num;
	t_list	*nw;

	while (idx < argc)
	{
		if (check_num(argv[idx]))
		{
			printf("hey");
			ft_lstclear(&stack_a, &free);
			error();
		}
		else
		{
			num = (int *)malloc(sizeof(int));
			if (!num)
				error();
			*num = ft_atoi(argv[idx]);
			nw = ft_lstnew(num);
			printf("%d\n", *(int *)nw->content);
			ft_lstadd_back(&stack_a, nw);
		}
		idx++;
	}
	ft_lstlast(stack_a)->next = NULL;
}

int	main(int argc, char **argv)
{
	size_t		selector;
	int			index;
	t_list		*stack_a;
	//t_list		*stack_b;
	t_list		*temp;

	index = 1;
	stack_a = NULL;
	//stack_b = NULL;
	if (argc == 1)
		error();
	selector = strategy_selector(argv[1]);
	if (selector != DEFAULT)
		index = 2;
	fill_stack_a(argc, argv, stack_a, index);
	while (stack_a)
	{
		temp = stack_a->next;
		printf("%d\n", *(int *)stack_a->content);
		ft_lstdelone(stack_a, &free);
		stack_a = temp;
	}
	return (0);
}
