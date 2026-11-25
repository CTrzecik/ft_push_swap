#include "push_swap.h"

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

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
	int	len;

	len = 0;
	while (max != 0)
	{
		max /= 2;
		len++;
	}
	return (len);
}

void	ranking(t_list *a)
{
	int		idx;
	t_list	*temp;
	int		*arr;

	idx = 0;
	temp = a;
	arr = malloc(ft_lstsize(a) * sizeof(int));
	if (!arr)
		error();
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
	free(arr);
}
