#include "push_swap.h"

int	ft_reas_mov(t_st *in, t_opt *mov)
{
	int	i;

	i = mov->c[mov->m];
	if (mov->m <= mov->szc / 2)
	{
		while (i > 0)
		{
			ft_ra(in->a, in->size_a);
			mov->szc--;
			i--;
		}
	}
	if (mov->m > mov->szc / 2)
	{
		while (i > 0)
		{
			ft_rra(in->a, in->size_a);
			mov->szc--;
			i--;
		}
	}
	return (0);
}

int	ft_rebs_mov(t_st *in, t_opt *mov)
{
	int	i;

	i =  mov->d[mov->m];
//	if (mov->m <= mov->szd / 2)
	{
		while (i > 0)
		{
			ft_rb(in->b, in->size_b);
			mov->szd--;
			i--;
		}
	}
/*	if (mov->m > mov->szd / 2)
	{
		while (i > 0)
		{
			ft_rrb(in->b, in->size_b);
			mov->szd--;
			i--;
		}
	}*/
	ft_pb(in);
	return (0);
}
	
int	ft_put_max(t_st *in, t_opt *mov)
{
	int	i;

	i = 0;
	while (i < in->size_b && in->b[i] != mov->mb)
		i++;
	if (i <= in->size_b / 2)
	{
		while (in->b[0] != mov->mb)
			ft_rb(in->b, in->size_b);
	}
	else
	{
		while (in->b[0] != mov->mb)
			ft_rrb(in->b, in->size_b);
	}
	return (0);
}

int	ft_pass(t_st *in)
{
	while (in->size_b > 0)
		ft_pa(in);
	return (0);
}

int	ft_rrs_mov(t_st *in, t_opt *mov)
{
	if (/*mov->m <= mov->szc / 2 &&*/ mov->c[mov->m] > 0 && mov->d[mov->m] > 0)
	{
		if (mov->c[mov->m] >= mov->d[mov->m])
		{
			while (mov->d[mov->m] != 0)
			{
				ft_rr(in->a, in->b, in->size_a, in->size_b);
				mov->c[mov->m]--;
				mov->d[mov->m]--;
				mov->szc--;
				mov->szd--;
			}
		}
		else
		{
			while (mov->c[mov->m] != 0)
			{
				ft_rr(in->a, in->b, in->size_a, in->size_b);
				mov->c[mov->m]--;
				mov->d[mov->m]--;
				mov->szc--;
				mov->szd--;
			}
		}
	}
/*/	if (mov->m > mov->szc / 2 && mov->c[mov->m] > 0 && mov->d[mov->m] > 0)
	{
		if (mov->c[mov->m] >= mov->d[mov->m])
		{
			while (mov->d[mov->m] != 0)
			{
				ft_rrr(in->a, in->b, in->size_a, in->size_b);
				mov->c[mov->m]--;
				mov->d[mov->m]--;
				mov->szc--;
				mov->szd--;
			}
		}
		else
		{
			while (mov->c[mov->m] != 0)
			{
				ft_rrr(in->a, in->b, in->size_a, in->size_b);
				mov->c[mov->m]--;
				mov->d[mov->m]--;
				mov->szc--;
				mov->szd--;
			}
		}
	}*/
	return (0);
}