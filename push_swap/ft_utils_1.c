#include "push_swap.h"

static int	*ft_put_order(t_st *in);
static int	*ft_put_index(t_st *in);

void	ft_double (t_st *in)//comprueba duplicidad de números
{
	int	i;
	int j;

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

void	ft_come_on (t_st *in)//arranca el push_swap
{
	int	i;

	in->size_c = in->size_a;
	in->b = ft_put_order (in);
	in->a = ft_put_index (in);//alojar en otra cadena si no se quiere machacar la original
	in->size_b = 0;
	i = -1;//bucle de impresión de indices
	while (++i < in->size_a)
		printf ("%d ", in->a[i]);
	printf ("\n");
	in->b = (int *) malloc (sizeof (int) * in->size_c);
	if (in->b == NULL)
	{	
		free (in->a);
		exit (0);
	}
	ft_pb (in);
	ft_pb (in);
	ft_pb (in);
	printf ("size_a %d - size_b %d - size_c %d\n", in->size_a, in->size_b, in->size_c);
	ft_pb (in);
/*	i = -1;//bucle de impresión de indices
	while (++i < in->size_a)
		printf ("%d ", in->a[i]);
	printf ("\n");
	i = -1;//bucle de impresión de indices
	while (++i < in->size_b)
		printf ("%d ", in->b[i]);
	printf ("\n");*/
}

static int	*ft_put_index(t_st *in)//pone los indices en la b auxiliar
{
	int	i;
	int j;
	int	*c;

	c = (int *) malloc(sizeof(int) * in->size_c);
	if (c == NULL)
		exit (0);
	i = 0;
	while (i < in->size_c)
	{
		j = 0;
		while (j < in->size_c)
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
	free (in->b);
	return (c);
}

static int	*ft_put_order(t_st *in)//ordena la cadena b de copia
{
	int i;
	int	j;
	int	k;

	in->b = ft_transpas (in->a, in->b, in->size_c);
	i = 0;
	while (i < in->size_c)
	{
		j = 0;
		while (j < in->size_c)
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

 int	*ft_transpas(int *a, int *b, int sz)//copia la cadena de int a otra
{
	int	i;

	b = (int *) malloc (sizeof (int) * sz);
	if (b == NULL)
	{	
		free (a);
		exit (0);
	}
	i = -1;
	while (++i < sz)
		b[i] = a[i];
	return (b);
}
