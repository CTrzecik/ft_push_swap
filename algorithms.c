/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:31:36 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/24 19:36:02 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_algorithm(t_list **a, t_list **b, t_benchmark *bm)
{
	int				min;
	unsigned int	pos;
	unsigned int	size;

	if (!a || !*a || bm->disorder == 0)
		return ;
	size = ft_lstsize(*a);
	while (size > 1)
	{
		pos = find_min(*a, &min);
		if (pos <= size / 2)
			while (min != *(int *)(*a)->content)
				ra(a, bm);
		else
			while (min != *(int *)(*a)->content)
				rra(a, bm);
		pb(a, b, bm);
		size--;
	}
	while (*b)
		pa(a, b, bm);
}


void	medium_algorithm(t_list **a, t_list **b, t_benchmark *bm)
{
	int	size;
    if (!a || !*a || bm->disorder == 0)
		return ;        
	size = ft_lstsize(*a);
	if (size < 2)
		return ;
	push_chunks(a, b, size, ft_sqrt_int(size), bm);
	push_back_max(a, b, bm);
}

void	complex_algorithm(t_list **a, t_list **b, t_benchmark *bm)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	nbr_passes;
	int				*arr;

	if (!a || !*a || bm->disorder == 0)
		return ;
	arr = malloc(ft_lstsize(*a) * sizeof(int));
	if (!arr)
		error();
	ranking(*a, arr);
	nbr_passes = max_passes(ft_lstsize(*a) - 1);
	i = 0;
	while (nbr_passes > i)
	{
		size = ft_lstsize(*a);
		while (size--)
		{
			if ((*(int *)(*a)->content & (0x1u << i)) == 0)
				pb(a, b, bm);
			else
				ra(a, bm);
		}
		while (*b)
			pa(a, b, bm);
		i++;
	}
	free(arr);
}

void	adaptive_algorithm(t_list **a, t_list **b, t_benchmark *bm)
{
	if (bm->disorder < 0.2)
		simple_algorithm(a, b, bm);
	else if (bm->disorder >= 0.2 && bm->disorder < 0.5)
		medium_algorithm(a, b, bm);
	else
		complex_algorithm(a, b, bm);
}
