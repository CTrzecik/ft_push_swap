#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h> 
# include <unistd.h>
# include <curses.h>
# include "libft/libft.h"
# include "ft_dprintf/ft_dprintf.h"

typedef enum e_stratsel
{
	SIMPLE = 1,
	MEDIUM = 2,
	COMPLEX = 3,
	ADAPTIVE = 4,
	DEFAULT = 5
}	t_stratsel;

typedef struct s_benchmark
{
	size_t	selector;
	bool	benchmark_mode;
	double	disorder;
	size_t	total_ops;
	size_t	sa_ops;
	size_t	sb_ops;
	size_t	ss_ops;
	size_t	pa_ops;
	size_t	pb_ops;
	size_t	ra_ops;
	size_t	rb_ops;
	size_t	rr_ops;
	size_t	rra_ops;
	size_t	rrb_ops;
	size_t	rrr_ops;
}	t_benchmark;

int		ft_strcmp(const char *s1, const char *s2);
int		isdigit_str(const char *s);
int		is_within_int_limit(long nbr);
int		isrepeat(const int nbr, const t_list *stack_a);
long	ft_atol(const char *nptr);
void	error(void);

int		count_smaller(t_list *cur, int n);
int		find_max_pos(t_list *cur);
void	push_chunks(t_list **a, t_list **b, int size, t_benchmark *bm);
void	push_back_max(t_list **a, t_list **b, t_benchmark *bm);
int		ft_sqrt_int(int nb);
int		find_min(t_list *a, int *min);
void	sort_arr(int *arr, int low, int high);
void	swap(int *a, int *b);
int		max_passes(unsigned int max);
void	ranking(t_list *a);

bool	isbenchmark(const char *s);
void	benchmark_output(t_benchmark bm);
void	init_bench(t_benchmark *bm);
void	print_count_ops(size_t	*total_ops, size_t *rule_op, char *op);
size_t	strategy_selector(const char *s);
void	call_algorithm(t_benchmark *bm,
			t_list **stack_a, t_list **stack_b);
double	disorder(t_list **a);
void	simple_algorithm(t_list **a, t_list **b, t_benchmark *bm);
void	medium_algorithm(t_list **a, t_list **b, t_benchmark *bm);
void	complex_algorithm(t_list **a, t_list **b, t_benchmark *bm);
void	adaptive_algorithm(t_list **a, t_list **b, t_benchmark *bm);

char	**split_numbers(char **argv, int idx);
void	string_split(char **argv, t_list **stack_a, int idx, int *num);
void	fill_stack_a(int argc, char **argv, t_list **stack_a, int idx);

void	sa(t_list **a, t_benchmark *bm);
void	sb(t_list **b, t_benchmark *bm);
void	ss(t_list **a, t_list **b, t_benchmark *bm);
void	pa(t_list **a, t_list **b, t_benchmark *bm);
void	pb(t_list **a, t_list **b, t_benchmark *bm);
void	ra(t_list **a, t_benchmark *bm);
void	rb(t_list **b, t_benchmark *bm);
void	rr(t_list **a, t_list **b, t_benchmark *bm);
void	rra(t_list **a, t_benchmark *bm);
void	rrb(t_list **b, t_benchmark *bm);
void	rrr(t_list **a, t_list **b, t_benchmark *bm);

#endif
