#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (*(s1++) != *(s2++))
			return ((unsigned int)*s1 - (unsigned int)*s2);
	}
	return (0);
}

int	check_num(const char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*(s++)))
			return (1);
	}
	return (0);
}
