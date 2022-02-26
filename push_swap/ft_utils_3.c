#include "push_swap.h"

int	ft_reas_mov(t_st *in, t_opt *mov)
{
	int	i;

	i = mov->c[mov->m];
/*	printf ("REAS\n");
	printf ("a: ");
	ft_printf (in->a, in->size_a);
	printf ("b: ");
	ft_printf (in->b, in->size_b);*/
	while (i > 0)
	{
		ft_ra(in->a, in->size_a);
		mov->szc--;
		i--;
	}
/*	printf ("a: ");
	ft_printf (in->a, in->size_a);
	printf ("b: ");
	ft_printf (in->b, in->size_b);*/
	return (0);
}

int	ft_rebs_mov(t_st *in, t_opt *mov)
{
	int	i;

	i =  mov->d[mov->m];
/*	printf ("REBS\n");
	printf ("a: ");
	ft_printf (in->a, in->size_a);
	printf ("b: ");
	ft_printf (in->b, in->size_b);*/
/*	if (in->a[0] > in->b[0] && in->a[0] > in->b[1])
	{
		while (i > 0)
		{
			ft_rrb(in->b, in->size_b);
			mov->szd--;
			i--;
		}
	}*/
//	if (in->a[0] > in->b[0] && in->a[0] < in->b[1])
	{
		while (i > 0)
		{
			ft_rb(in->b, in->size_b);
			mov->szd--;
			i--;
		}
	}
/*	if (in->a[0] < in->b[0] && in->a[0] > in->b[1])
	{
		while (i > 0)
		{
			ft_rb(in->b, in->size_b);
			mov->szd--;
			i--;
		}
	}*/
	ft_pb(in);
/*	printf ("a: ");
	ft_printf (in->a, in->size_a);
	printf ("b: ");
	ft_printf (in->b, in->size_b);*/
	printf ("****size_a = %d****\n", in->size_a);
	return (0);
}
	
