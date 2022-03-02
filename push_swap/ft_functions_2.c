#include "push_swap.h"

int	ft_ra(int *i, int sz)
{
	int	j;
	int	k;

//	if (sz < 2)Hace falta esto??que no haga nada si hay un elemento
//		return (0);
	j = 0;
	k = i[j];
	while (++j < sz)
		i[j - 1] = i[j];
	i[j - 1] = k;
	write (1, "ra\n", 3);
	return (0);
}

int	ft_rb(int *i, int sz)
{
	int	j;
	int	k;

//	if (sz < 2)Hace falta esto??que no haga nada si hay un elemento
//		return (0);
	j = 0;
	k = i[j];
	while (++j < sz)
	{
		i[j - 1] = i[j];
	}
	i[j - 1] = k;
	write (1, "rb\n", 3);
	return (0);
}

int	ft_rr(int *i, int *j, int szi, int szj)
{
	int k;
	int	l;

	l = 0;
	if (szi > 1)//condición de no hacer nada si hay 1 elemento
	{
		k = i[l];
		while (++l < szi)
			i[l - 1] = i[l];
		i[l - 1] = k;
	}
	if (szj > 1)//condición de no hacer nada si hay 1 elemento
	{
		l = 0;
		k = j[l];
		while (++l < szj)
			j[l - 1] = j[l];
		j[l - 1] = k;
	}
	if (l != 0)
		write (1, "rr\n", 3);
	return (0);
}
