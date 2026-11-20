#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h> 
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef enum e_stratsel
{
	SIMPLE = 1,
	MEDIUM = 2,
	COMPLEX = 3,
	ADAPTIVE = 4,
	DEFAULT = 5
}	t_stratsel;

int		ft_strcmp(const char *s1, const char *s2);
int		isdigit_str(const char *s);
int		is_within_int_limit(long nbr);
int		isrepeat(const int nbr, const t_list *stack_a);
long	ft_atol(const char *nptr);
void	error(void);

int	count_smaller(t_list *cur, int n);
void	push_chunks(t_list **a, t_list **b, int size, int chunks);
int	find_max_pos(t_list *cur);
void	push_back_max(t_list **a, t_list **b);

size_t	strategy_selector(const char *s);
void	call_algorithm(const size_t selector, t_list **stack_a, t_list **stack_b);
double	disorder(t_list **a, int size);
void    simple_algorithm(t_list **a, t_list **b);
void	medium_algorithm(t_list **a, t_list **b);
void	complex_algorithm(t_list **a, t_list **b);

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void    ra(t_list **a);
void    rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
