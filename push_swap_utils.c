#include "push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

size_t	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*(s1++) != *(s2++))
			return ((unsigned int)*s1 - (unsigned int)*s2);
	}
	return (0);
}
