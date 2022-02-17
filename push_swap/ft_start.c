#include "push_swap.h"

static int	*ft_conv_int_1 (int i, char **s);
static int	*ft_conv_int_2 (char **s);

int	*ft_int (int i, char **s)
{
	t_st	in;

	if (i < 2)
	{
		write (1, "Error\n", 6);
		exit (0);
	}
	if (i == 2)
		in.a = ft_conv_int_2 (s);
	else if (i > 2)
		in.a = ft_conv_int_1 (i, s);
	return (in.a);
}
	
static int	*ft_conv_int_1 (int i, char **s)
{
	int	*a;
	int	j;

	j = 0;
	a = (int *) malloc(sizeof(int) * (i - 1));
	if (a == 0)
		return (NULL);
	while (j < i - 1)
	{
		a[j] = ft_atoi(s[j + 1]);
		printf ("%d ", a[j]);
		j++;
	}
	printf ("\n");
	return (a);
}

static int	*ft_conv_int_2 (char **s)
{
	int		*a;
	int		i;
	char	**c;

	i = 0;
	a = (int *) malloc (sizeof(int) * ft_strlen(s[1]));
	if (a == 0)
		return (NULL);
	c = ft_split (s[1], ' ');
	while (*c != 00)
	{
		a[i] = ft_atoi(*c);
		free (*c);
		printf ("%d ", a[i]);
		i++;
		c++;
	}
//	free (c);//por que no esta bien este free aqui???
	printf ("\n");
	return (a);
}
