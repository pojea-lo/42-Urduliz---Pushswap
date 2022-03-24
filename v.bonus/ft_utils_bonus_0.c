#include "push_swap_bonus.h"

//inicia el stack b y comprueba los argumentos de movimientos
void    ft_checker (t_st *in)
{
//	in->cmd = get_next_line(0);
	scanf("%s", in->cmd);
	ft_check_mov (in, in->cmd);
	if (in->size_b == 0)
		ft_printf (in, 1);
	else
		ft_printf (in, 2);
}

//chequea los cmdumentos y ejecuta los movimientos
void    ft_check_mov(t_st *in, char *cmd)
{
    if (ft_strcmp (cmd, "sa") == 1)
        ft_sa(in->a, in->size_a);
    else if (ft_strcmp(cmd, "sb") == 1)
        ft_sb(in->b, in->size_b);
    else if (ft_strcmp(cmd, "ss") == 1)
        ft_ss(in->a, in->b, in->size_a, in->size_b);
    else if (ft_strcmp(cmd, "pa") == 1)
        ft_pa_bonus(in);
    else if (ft_strcmp(cmd, "pb") == 1)
        ft_pb_bonus(in);
    else if (ft_strcmp(cmd, "ra") == 1)
        ft_ra(in->a, in->size_a);
    else if (ft_strcmp(cmd, "rb") == 1)
        ft_rb(in->b, in->size_b);
    else if (ft_strcmp(cmd, "rr") == 1)
        ft_rr(in->a, in->b, in->size_a, in->size_b);
    else if (ft_strcmp(cmd, "rra") == 1)
        ft_rra(in->a, in->size_a);
    else if (ft_strcmp(cmd, "rrb") == 1)
        ft_rrb(in->b, in->size_b);
    else if (ft_strcmp(cmd, "rrr") == 1)
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
	free (in->cmd);
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
int	ft_check_bonus(t_st *in)
{
	int	i;

	i = 0;
	while (++i < in->size_a)
	{
		if (in->a[i - 1] > in->a[i])
		{
			printf ("*************************** KO **\n\n");
			return (1);
		}
	}
	if (in->size_b == 0)
	{
		printf ("*************************** OK **\n");
		return (0);
	}
	return (1);
}