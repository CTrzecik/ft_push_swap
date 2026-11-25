#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_arr(int *arr, int low, int high)
{
	int pivot = arr[high];
	int	start = low;
	int	end = high;

	if (low >= high)
		return ;
	while (start < end)
	{
		while (arr[start] < pivot)
			start++;
		while (arr[end] > pivot)
			end--;
		if (start < end)
		{
			swap(&arr[start], &arr[end]);
			start++;
		}
	}
	sort_arr(arr, low, start - 1);
	sort_arr(arr, start, high);
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
	sort_arr(arr, 0, idx - 1);
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
