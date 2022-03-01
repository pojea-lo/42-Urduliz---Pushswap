#include "push_swap.h"

static int	*ft_conv_int_1(int i, char **s, t_st *in);
static int	*ft_conv_int_2(char **s, t_st *in);

int	*ft_int(int i, char **s)
{
	t_st	in;
	t_opt	mov;

	if (i < 2)
	{
		write (1, "Error\n", 6);
		exit (0);
	}
	if (i == 2)
		in.a = ft_conv_int_2 (s, &in);
	else if (i > 2)
		in.a = ft_conv_int_1 (i, s, &in);
	ft_double (&in);
	ft_come_on (&in, &mov);
	return (in.a);
}

static int	*ft_conv_int_1(int i, char **s, t_st *in)//argumentos sin "
{
	int			*a;
	int			j;
	int			b;

	j = 0;
	in->size_a = i - 1;
	a = (int *) malloc(sizeof(int) * (i - 1));
	if (a == 0)
		return (NULL);
	while (j < i - 1)
	{
		b = ft_atoi(s[j + 1]);
		a[j] = (int) b;
//		printf ("%d ", a[j]);
		j++;
	}
//	printf ("\n");
	return (a);
}

static int	*ft_conv_int_2(char **s, t_st *in)//argumentos entre "
{
	int			*a;
	int			i;
	int			b;
	char		**c;

	i = 0;
	in->size_a = ft_count(s[1], ' ');
	a = (int *) malloc (sizeof(int) * in->size_a);
	if (a == 0)
		return (NULL);
	c = ft_split (s[1], ' ');
	while (c[i] != 00)
	{
		b = ft_atoi(c[i]);
		a[i] = (int) b;
		free (c[i]);
//		printf ("%d ", a[i]);
		i++;
	}
	free (c);
//	printf ("\n");
	return (a);
}