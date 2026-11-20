/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrzecik <ctrzecik@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:31:36 by ctrzecik          #+#    #+#             */
/*   Updated: 2026/11/20 11:25:09 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	find_min(t_list *a, int *min)
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

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int temp;

	i = 0;
	while (i < size -1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
int	max_passes(unsigned int max)
{
	int len;
	
	len = 0;
	while (max != 0)
	{
		max /= 2;
		len++;
	}
	return (len);
}

void	ranking(t_list *a, int *arr)
{
	int 	idx;
	t_list	*temp;

	idx = 0;
	temp = a;
	while (temp)	
	{
		arr[idx++] = *(int *)temp->content;
		temp = temp->next;
	}
	sort_arr(arr, idx);
	idx = 0;
	while (a)
	{
		while (*(int *)a->content != arr[idx])
			idx++;
		*(int *)a->content = idx;
		idx = 0;
		a = a->next;
	}
}

void	simple_algorithm(t_list **a, t_list **b)
{
	int				min;
	unsigned int	pos;
	unsigned int	size;

	if (!a || !*a || disorder(a) == 0)
		return ;
	size = ft_lstsize(*a);
	while (size > 1)
	{
		pos = find_min(*a, &min);
		if (pos <= size / 2)
			while (min != *(int *)(*a)->content)
				ra(a);
		else
			while (min != *(int *)(*a)->content)
				rra(a);
		pb(a, b);
		size--;
	}
	while (*b)
		pa(a, b);
}

static int	ft_sqrt_int(int nb)
{
	long	i;

	if (nb < 0)
		return (-1);
	i = 0;
	while ((i + 1) * (i + 1) <= nb)
		i++;
	return ((int)i);
}

void	medium_algorithm(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size < 2)
		return ;
	push_chunks(a, b, size, ft_sqrt_int(size));
	push_back_max(a, b);
}

void	complex_algorithm(t_list **a, t_list **b)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	nbr_passes;
	int				*arr;

	if (!a || !*a || disorder(a) == 0)
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
				pb(a, b);
			else
				ra(a);
		}
		while (*b)
			pa(a, b);
		i++;
	}
	free(arr);
}

void	adaptive_algorithm(t_list **a, t_list **b)
{
	(void)a;
	(void)b;
	return ;
}
