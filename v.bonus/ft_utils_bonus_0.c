#include "push_swap_bonus.h"

//inicia el stack b y comprueba los argumentos de movimientos
void    ft_checker (t_st *in, int argn, char **arg)
{
    int i;

    i = 2;
    in->b = (int *) malloc (sizeof(int) * in->size_a);
    if (in->b == NULL)
    {
        free (in->a);
        exit (0);
    }
    in->size_b = 0;
    while (i < argn)
    {
        ft_check_mov (in, arg[i]);
        i++;
    }
}

//chequea los argumentos y ejecuta los movimientos
void    ft_check_mov(t_st *in, char *arg)
{
    if (ft_strcmp (arg, "sa") == 1)
        ft_sa(in->a, in->size_a);
    else if (ft_strcmp(arg, "sb") == 1)
        ft_sb(in->b, in->size_b);
    else if (ft_strcmp(arg, "ss") == 1)
        ft_ss(in->a, in->b, in->size_a, in->size_b);
    else if (ft_strcmp(arg, "pa") == 1)
        ft_pa(in);
    else if (ft_strcmp(arg, "pb") == 1)
        ft_pb(in);
    else if (ft_strcmp(arg, "ra") == 1)
        ft_ra(in->a, in->size_a);
    else if (ft_strcmp(arg, "rb") == 1)
        ft_rb(in->b, in->size_b);
    else if (ft_strcmp(arg, "rr") == 1)
        ft_rr(in->a, in->b, in->size_a, in->size_b);
    else if (ft_strcmp(arg, "rra") == 1)
        ft_rra(in->a, in->size_a);
    else if (ft_strcmp(arg, "rrb") == 1)
        ft_rrb(in->b, in->size_b);
    else if (ft_strcmp(arg, "rrr") == 1)
        ft_rrr(in->a, in->b, in->size_a, in->size_b);
    else
        ft_cmd_error (in);
}

//error en caso de haber metido mal algún movimiento
void    ft_cmd_error(t_st *in)
{
    write (1, "Command error\n", 14);
    free (in->a);
    free (in->b);
    exit (0);
}

int    ft_strcmp(char *s1, char *s2)
{
    int i;
    int j;

    i = ft_strlen (s1);
    j = ft_strlen (s2);
    if (i != j)
        return (0);
    while (i >= 0)
    {
        if (s1[i] != s2[i])
            return (0);
        i--;
    }
    return (1);
}

//function to check at the begining the order
int	ft_check(t_st *in)
{
	int	i;

	i = 0;
	while (++i < in->size_a)
	{
		if (in->a[i - 1] > in->a[i])
		{
			write (1, "KO\n", 3);
			return (1);
		}
	}
	write (1, "OK\n", 3);
	return (0);
}