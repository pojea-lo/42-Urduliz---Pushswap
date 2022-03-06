#include "push_swap.h"

void	ft_come_on (t_st *in, t_opt *mov)//arranca el push_swap
{
	int	i;

	in->size_c = in->size_a;
	in->b = ft_put_order (in);
	in->a = ft_put_index (in);//alojar en otra cadena si no se quiere machacar la original con los indices
	ft_restart (in);
	i = ft_check (in);
	if (i == 0)
		exit(0);
	if (in->size_a < 6)
		ft_zero (in, mov);
	else if (in->size_a > 5)
		ft_first (in, mov);
	ft_check(in);
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
//	printf ("final a: ");
//	ft_printf (in->a, in->size_a);
//	printf("size_a %d\n", in->size_a);
//	printf ("final b: ");
//	ft_printf (in->b, in->size_b);
	return (0);
}
