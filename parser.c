#include "push_swap.h"

char **split_numbers(char **argv, int idx)
{
    int     i;
    char    space;

    space = 0;
    i = 0;
    while(argv[idx][i])
    {
        if (argv[idx][i] == ' ' || (argv[idx][i] >= 9 && argv[idx][i] <= 13))
        {
            if(space != 0 && space != argv[idx][i])
                error();
            space = argv[idx][i];
            i++;
        }
        else if(ft_isdigit(argv[idx][i]))
            i++;
        else
            error();
    }
    return(ft_split(argv[idx], space));
}

void string_split(char **argv, t_list **stack_a, int idx, int *num)
{
    
    char    **numbers_split;
    int     i;

    i = 0;
    numbers_split = split_numbers(argv, idx);
    if(!numbers_split)
        error();
    i = 0;
    while (numbers_split[i])
    {
         if (isrepeat(ft_atol(numbers_split[i]), *stack_a))
             error();
        num = (int *)malloc(sizeof(int));
		if (!num)
			error();
		*num = ft_atol(numbers_split[i]);
		ft_lstadd_back(stack_a, ft_lstnew(num));
        i++;
    }
}

void	fill_stack_a(int argc, char **argv, t_list **stack_a, int idx)
{
	int		*num;
    while (idx < argc)
	{
        if (ft_strlen(argv[idx]) > 2)
        {
            string_split(argv, stack_a, idx, num);
            idx++;
        }
        else
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
	}
	ft_lstadd_back(stack_a, NULL);
}

