#include "push_swap.h"

void	ss(t_list **a, t_list **b, t_benchmark *bm)
{
	sa(a, bm);
	sb(b, bm);
	print_count_ops(&(bm->total_ops), &(bm->ss_ops), "ss");
}

void	rr(t_list **a, t_list **b, t_benchmark *bm)
{
	ra(a, bm);
	rb(b, bm);
	print_count_ops(&(bm->total_ops), &(bm->rr_ops), "rr");
}

void	rrr(t_list **a, t_list **b, t_benchmark *bm)
{
	rra(a, bm);
	rrb(b, bm);
	print_count_ops(&(bm->total_ops), &(bm->rrr_ops), "rrr");
}
