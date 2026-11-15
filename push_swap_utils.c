#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 || *s2)
	{
		if (*(s1++) != *(s2++))
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}

int	isdigit_str(const char *s)
{
	if (!s)
		return (1);
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*(s++)))
			return (0);
	}
	return (1);
}

int	is_within_int_limit(const long nbr)
{
	if (nbr <= INT_MAX && nbr >= INT_MIN)
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	int		sign;
	long	result;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (!is_within_int_limit(result))
			return (result * sign);
		i++;
	}
	return (result * sign);
}

int	isrepeat(const int nbr, const t_list *stack_a)
{
	while (stack_a)
	{
		if (*(int *)stack_a->content == nbr)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
