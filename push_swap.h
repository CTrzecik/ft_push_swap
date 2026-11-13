#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h> 
# include <unistd.h>
# include "libft/libft.h"
//# include "ft_printf.h"

typedef struct s_stack
{
	int	num;
	struct	s_a *next;
}	t_stack;

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
size_t	ft_strcmp(const char *s1, const char *s2);

// Utilities from ss
void	stratsel(const char *s, t_stack stack_a, t_stack stack_b);
size_t	stratsel_verif(const char *s);

#endif
