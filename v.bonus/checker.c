#include "push_swap_bonus.h"

static int	*ft_conv_int_1_bonus(char **s, t_st *in);
static void	ft_free_bonus(long int b, t_st *in);
static void	ft_double(t_st *in);


int	main(int argc, char *argv[])
{
	ft_int_bonus (argc, argv);
	return (0);
}

void	ft_int_bonus(int argn, char **arg)
{
	t_st	in;

	in.b = (int *) malloc (sizeof (int) * in.size_a);
	in.cmd = (char *) malloc (sizeof (char) * 50);
	if (in.b == NULL || in.cmd == NULL)
	{
		ft_free_bonus_1 (&in);
		exit (0);
	}
	if (argn != 2)
	{
		write (1, "Arguments error\n", 16);
		ft_free_bonus_1 (&in);
		exit (0);
	}
	if (argn == 2)
		in.a = ft_conv_int_1_bonus (arg, &in);
	ft_double (&in);
	in.size_b = 0;
  	ft_printf (&in, 1);
}

//number arguments with "
static int	*ft_conv_int_1_bonus(char **s, t_st *in)
{
	long int	b;

	in->p = -1;
	in->size_a = ft_count(s[1], ' ');
	if (in->size_a == 1)
	{
		if ((((s[1][0] < 48 && s[1][0] != 43 && s[1][0] != 45) ||
		s[1][0] > 57)) || ((s[1][0] == '-' || s[1][0] == '+') && 
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
void	ft_printf(t_st *in, int j)
{
	int	i;

	i = -1;
	if (j == 1)
	{
		printf ("\n** Stack A **********************\n\n");
		while (++i < (in->size_a - 1))
			printf ("%d - ", in->a[i]);
		printf ("%d\n\n", in->a[i]);
	}
	else if (j == 2)
	{
		printf ("\n** Stack A-B ********************\n\n");
		while (++i < (in->size_a - 1))
			printf ("%d - ", in->a[i]);
		printf ("%d\n\n", in->a[i]);
		i = -1;
		while (++i < (in->size_b - 1))
			printf ("%d - ", in->b[i]);
		printf ("%d\n\n", in->b[i]);
	}
	if (ft_check_bonus(in) == 1)
		printf ("****************** Put command **\n\n");
	else
	{
		ft_free_bonus_1 (in);
		exit (1);
	}
	ft_checker (in);
}

void	ft_free_bonus_1(t_st *in)
{
	free (in->a);
	if (in->b != NULL)
		free (in->b);
	if (in->cmd != NULL)
		free (in->cmd);
}
