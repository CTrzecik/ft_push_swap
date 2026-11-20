#include "push_swap.h"

int	find_min(t_list *a, int *min)
{
	int	pos;
	int	i;

	*min = *(int *)a->content;
	i = 0;
	pos = i;
	while (a)
	{
		if (*min > *(int *)a->content)
		{
			*min = *(int *)a->content;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}
