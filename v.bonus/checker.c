#include "push_swap_bonus.h"

static int	*ft_conv_int_1_bonus(char **s, t_st *in);
static void	ft_free_bonus(long int b, t_st *in);
static void	ft_double(t_st *in);


int	main(int argc, char *argv[])
{
	ft_int_bonus (argc, argv);
	return (0);
}

int	*ft_int_bonus(int argn, char **arg)
{
	t_st	in;

	if (argn < 2)
	{
		write (1, "ERROR\n", 6);
		exit (0);
	}
	if (argn >= 2)
		in.a = ft_conv_int_1_bonus (arg, &in);
	ft_double (&in);
	printf ("El stack al inicio es: ");
  	ft_printf (in.a, in.size_a);
	ft_checker (&in, argn, arg);
	printf ("El stack al final es: ");
  	ft_printf (in.a, in.size_a);
	ft_check(&in);
	free (in.a);
	free (in.b);
	return (in.a);
}

//number arguments with "
static int	*ft_conv_int_1_bonus(char **s, t_st *in)
{
	long int	b;

	in->p = -1;
	in->size_a = ft_count(s[1], ' ');
	if (in->size_a == 1)
	{
		if ((((s[1][0] < 48 && s[1][0] != 43 && s[1][0] != 45) || \
		s[1][0] > 57)) || ((s[1][0] == '-' || s[1][0] == '+') && \
		s[1][1] == 00) || (ft_atoi(&s[1][0]) == 2147483648))
			write (1, "Error\n", 6);
		exit (0);
	}
	in->a = (int *) malloc (sizeof(int) * in->size_a);
	if (in->a == NULL)
		exit (0);
	in->s = ft_split (s[1], ' ');
	while (in->s[++in->p] != 00)
	{
		b = ft_atoi(in->s[in->p]);
		free (in->s[in->p]);
		ft_free_bonus (b, in);
		in->a[in->p] = (int) b;
	}
	free (in->s);
    return (in->a);
}

//frees of errors exits with "
static void	ft_free_bonus(long int b, t_st *in)
{
	if (b == 2147483648)
	{
		write (1, "Error\n", 6);
		while (in->s[++in->p] != 00)
			free (in->s[in->p]);
		free (in->s);
		free (in->a);
		exit (0);
	}
}

//check duplicity
static void	ft_double(t_st *in)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < in->size_a)
	{
		j = i + 1;
		while (j < in->size_a)
		{
			if (in->a[i] == in->a[j])
			{
				write (1, "Error\n", 6);
				free (in->a);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

//printf the stacks
void	ft_printf(int *a, int sza)
{
	int	i;

	i = -1;
	while (++i < sza)
		printf ("%d - ", a[i]);
	printf ("\n");
}