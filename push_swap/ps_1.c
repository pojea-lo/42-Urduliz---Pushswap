#include "push_swap.h"

void	ft_come_on (t_st *in, t_opt *mov)//arranca el push_swap
{
//	int	i;

	in->size_c = in->size_a;
	in->b = ft_put_order (in);
	in->a = ft_put_index (in);//alojar en otra cadena si no se quiere machacar la original con los indices
	ft_restart (in);
//	ft_check (in);
	ft_first (in, mov);
}

int	ft_first (t_st *in, t_opt *mov)
{
//	ft_printf (in->a, in->size_a);
	ft_pb(in);//paso el primer elemento de a a b
	ft_pb(in);//paso el segundo elemento de a a b
	if (in->b[0] < in->b[1])
		ft_sb(in->b, in->size_b);
//	printf ("inicial a: ");
//	ft_printf (in->a, in->size_a);
//	printf ("inicial b: ");
//	ft_printf (in->b, in->size_b);
	while (in->size_a != 0)
	{
		ft_options (in, mov);
//		printf ("intermedia a: ");
//		ft_printf (in->a, in->size_a);
//		printf ("intermedia b: ");
//		ft_printf (in->b, in->size_b);
	}
	ft_put_max(in, mov);
	ft_pass(in);
	ft_check(in);
//	printf ("final a: ");
//	ft_printf (in->a, in->size_a);
//	printf ("final b: ");
//	ft_printf (in->b, in->size_b);
	return (0);
}

int	ft_options(t_st *in, t_opt *mov)
{
	mov->c = (int *) malloc (sizeof (int) * (in->size_c - 1));
	mov->d = (int *) malloc (sizeof (int) * (in->size_c - 1));
	if (mov->c == NULL || mov->d == NULL)
	{
		free (in->a);
		free (in->b);
		exit (0);
	}
	ft_reas (in, mov);
	ft_rebs (in, mov);
	ft_add (in, mov);
	ft_min (mov);
//	ft_rrr_mov (in, mov);
	ft_reas_mov(in, mov);
	ft_rebs_mov(in, mov);
	return (0);
}
