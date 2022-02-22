#include "push_swap.h"

static int	*ft_transpas(t_st *in);

void	ft_double (t_st *in)//comprueba duplicidad de números
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < in->size)
	{
		j = i + 1;
		while (j < in->size)
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

void	ft_come_on (t_st *in)
{
	int	i;

	i = -1;
	in->b = ft_put_order (in);
	in->b = ft_put_index (in);
	while (++i < in->size)
		printf ("%d ", in->b[i]);
	free (in->b);
}

int	*ft_put_index(t_st *in)//pone los indices en la b auxiliar
{
	int	i;
	int j;
	int	*c;

	c = (int *) malloc(sizeof(int) * in->size);
	if (c == NULL)
		exit (0);
	i = 0;
	while (i < in->size)
	{
		j = 0;
		while (j < in->size)
		{
			if (in->a[i] == in->b[j])
			{
				c[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	return (c);
}

int	*ft_put_order(t_st *in)//ordena la cadena b de copia
{
	int i;
	int	j;
	int	k;

	i = 0;
	ft_transpas (in);
	while (i < in->size)
	{
		j = 0;
		while (j < in->size)
		{
			if (in->b[i] < in->b[j])
			{
				k = in->b[j];
				in->b[j] = in->b[i];
				in->b[i] = k;
			}
			j++;
		}
		i++;
	}
	i = -1;
	return (in->b);
}

static int	*ft_transpas(t_st *in)//copia la cadena de int a otra
{
	int	i;

	in->b = (int *) malloc (sizeof (int) * in->size);
	if (in->b == NULL)
	{	
		free (in->a);
		exit (0);
	}
	i = -1;
	while (++i < in->size)
		in->b[i] = in->a[i];
	return (in->b);
}
