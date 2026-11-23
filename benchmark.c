#include "push_swap.h"
#include <stdio.h>

void	benchmark_output(t_benchmark bm)
{
	dprintf(2, "[bench] disorder: %.2lf%%\n", bm.disorder);
	if (bm.selector == SIMPLE)
		ft_dprintf(2, "[bench] strategy: Simple / O(n2)\n");
	else if (bm.selector == MEDIUM)
		ft_dprintf(2, "[bench] strategy: Medium / O(nsqrt(n))\n");
	else if (bm.selector == COMPLEX)
		ft_dprintf(2, "[bench] strategy: Complex / O(nlog(n))\n");
	ft_dprintf(2, "[bench] total_ops: %d\n", bm.total_ops);
	ft_dprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb %d\n",
		bm.sa_ops, bm.sb_ops, bm.ss_ops, bm.pa_ops, bm.pb_ops);
	ft_dprintf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb %d rrr %d\n",
		bm.ra_ops, bm.rb_ops, bm.rr_ops, bm.rra_ops, bm.rrb_ops, bm.rrr_ops);
}

void	init_bench(t_benchmark *bm)
{
	bm->total_ops = 0;
	bm->sa_ops = 0;
	bm->sb_ops = 0;
	bm->ss_ops = 0;
	bm->pa_ops = 0;
	bm->pb_ops = 0;
	bm->ra_ops = 0;
	bm->rb_ops = 0;
	bm->rr_ops = 0;
	bm->rra_ops = 0;
	bm->rrb_ops = 0;
	bm->rrr_ops = 0;
}

void	print_count_ops(size_t	*total_ops, size_t *rule_op, char *op)
{
	(*total_ops)++;
	(*rule_op)++;
	ft_dprintf(1, "%s\n", op);
}
