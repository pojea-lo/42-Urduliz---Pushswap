#include "push_swap.h"

int	ft_rra(int *i, int sz)
{
	int	j;
	int	k;

//	if (sz < 2)Hace falta esto??que no haga nada si hay un elemento
//		return (0);
	j = 0;
	k = i[sz - 1];
	while (++j < sz)
		i[sz - j] = i[sz -j - 1];
	i[0] = k;
//	write (1, "rra\n", 4);
	return (0);
}

int	ft_rrb(int *i, int sz)
{
	int	j;
	int	k;

//	if (sz < 2)Hace falta esto??que no haga nada si hay un elemento
//		return (0);
	j = 0;
	k = i[sz - 1];
	while (++j < sz)
		i[sz - j] = i[sz - j - 1];
	i[0] = k;
//	write (1, "rrb\n", 4);
	return (0);
}

int	ft_rrr(int *i, int *j, int szi, int szj)
{
	int k;
	int	l;

	l = 0;
	if (szi > 1)//condición de no hacer nada si hay 1 elemento
	{
		k = i[szi - 1];
		while (++l < szi)
			i[szi - l] = i[szi - l -1];
		i[0] = k;
	}
	if (szj > 1)//condición de no hacer nada si hay 1 elemento
	{
		l = 0;
		k = j[szj - 1];
		while (++l < szj)
			j[szj - l] = j[szj - l -1];
		j[0] = k;
	}
//	if (l != 0)
//		write (1, "rrr\n", 4);
	return (0);
}
