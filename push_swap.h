#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h> 
# include <unistd.h>
# include "libft/libft.h"
//# include "ft_printf.h"

/*
typedef struct s_stack
{
	int	num;
	struct	s_a *next;
}	t_stack;
*/

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
int	check_num(const char *s);

// Utilities from ss
void	call_algo(const char *s, t_list stack_a, t_list stack_b);
size_t	strategy_selector(const char *s);

#endif
