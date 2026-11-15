#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h> 
# include <unistd.h>
# include "libft/libft.h"

typedef enum e_stratsel
{
	SIMPLE = 1,
	MEDIUM = 2,
	COMPLEX = 3,
	ADAPTIVE = 4,
	DEFAULT = 5
}	t_stratsel;

// Utilities
void	error(void);
int		ft_strcmp(const char *s1, const char *s2);
int		isdigit_str(const char *s);
int		is_within_int_limit(long nbr);
long	ft_atol(const char *nptr);
int		isrepeat(const int nbr, const t_list *stack_a);

// Utilities from ss
void	call_algo(const char *s, t_list stack_a, t_list stack_b);
size_t	strategy_selector(const char *s);

#endif
