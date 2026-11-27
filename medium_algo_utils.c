#include "push_swap.h"

int	ft_sqrt_int(int nb)
{
	long	i;

	if (nb < 0)
		return (-1);
	i = 0;
	while ((i + 1) * (i + 1) <= nb)
		i++;
	return ((int)i);
}

int	count_smaller(t_list *cur, int n)
{
	int	count;

	count = 0;
	while (cur)
	{
		if (*(int *)cur->content < n)
			count++;
		cur = cur->next;
	}
	return (count);
}

void	push_chunks(t_list **a, t_list **b, int size, t_benchmark *bm)
{
	int	i;
	int	pushed;
	int	n;
	int	rank;
	int	chunks;

	chunks = ft_sqrt_int(size);
	pushed = 0;
	i = -1;
	while (++i < chunks)
	{
		while (pushed < ((i + 1) * size / chunks))
		{
			n = *(int *)(*a)->content;
			rank = count_smaller(*a, n) + count_smaller(*b, n);
			if (rank < ((i + 1) * size / chunks))
			{
				pb(a, b, bm);
				pushed++;
			}
			else
				ra(a, bm);
		}
	}
}

int	find_max_pos(t_list *cur)
{
	int	max;
	int	pos;
	int	max_pos;

	max = *(int *)cur->content;
	max_pos = 0;
	pos = 0;
	while (cur)
	{
		if (*(int *)cur->content > max)
		{
			max = *(int *)cur->content;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

void	push_back_max(t_list **a, t_list **b, t_benchmark *bm)
{
	int	pos;
	int	size;

	while (*b)
	{
		size = ft_lstsize(*b);
		pos = find_max_pos(*b);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(b, bm);
		}
		else
		{
			while (pos++ < size)
				rrb(b, bm);
		}
		pa(a, b, bm);
	}
}
