#include "push_swap.h"

int	ft_max(t_st *in, t_opt *mov)//encuentra el maximo yminimo de a
{
	int	i;

	i = 1;
	mov->ma = in->a[0];
	while (i < in->size_a)
	{
		if (mov->ma < in->a[i])
			mov->ma = in->a[i];
		i++;
	}
	return (0);
}

int	ft_minmax(t_st *in, t_opt *mov)//encuentra el maximo y minimo de b
{
	int	i;

	i = 1;
	mov->ma = in->a[0];
	mov->na = in->a[0];
	while (i < in->size_a)
	{
		if (mov->ma < in->a[i])
			mov->ma = in->a[i];
		if (mov->na > in->a[i])
			mov->na = in->a[i];
		i++;
	}
	i = 1;
	mov->mb = in->b[0];
	mov->nb = in->b[0];
	while (i < in->size_b)
	{
		if (mov->mb < in->b[i])
			mov->mb = in->b[i];
		if (mov->nb > in->b[i])
			mov->nb = in->b[i];
		i++;
	}
	return (0);
}

int ft_reas(t_st *in, t_opt *mov)//funcion que cuenta los movimientos de pa necesarios para cada caso
{
	int	i;
	int	j;

	i = -1;
	while (++i <= (in->size_a / 2))
		mov->c[i] = i;
	mov->szc = i;
	if ((in->size_a % 2) == 0)
	{
		j = -1;
		while (++j < (in->size_a / 2) - 1)
		{
			mov->c[i + j] = (i - (j + 2));
			mov->szc++;
		}
	}
	else
	{		
		j = -1;
		while (++j < (in->size_a / 2))
		{
			mov->c[i + j] = (i - (j + 1));
			mov->szc++;
		}
	}
	i = mov->szc;
	while (i < in->size_c - 1)//pongo a 0 el resto de la cadena c
	{
		mov->c[i] = 0;
		i++;
	}
	return (0);
}

int	ft_rebs_tops(t_st *in, t_opt *mov, t_num *rb)//subfuncion del rebs para los maximos
{
	ft_minmax (in, mov);
	if (in->a[rb->i] < mov->nb || in->a[rb->i] > mov->mb)
	{
		if ((in->a[rb->i] < mov->nb && in->b[0] == mov->mb) || (in->a[rb->i] > mov->mb && in->b[0] == mov->mb))
		{
			mov->mv[rb->i] = 'u';
			return (rb->k = 0);
		}
		else if ((in->a[rb->i] < mov->nb && in->b[0] == mov->nb) || (in->a[rb->i] > mov->mb && in->b[0] == mov->nb))
		{
			mov->mv[rb->i] = 'u';
			return (rb->k = 1);
		}
		else
		{
			rb->j = 1;
			while (rb->j < in->size_b - 1)
			{
				if (in->b[rb->j] == mov->nb && in->b[rb->j + 1] == mov->mb)
				{
					if (rb->j <= in->size_b/2)
					{
						mov->mv[rb->i] = 'u';
						return (rb->k = rb->j + 1);
					}
					if (rb->j > in->size_b/2)
					{
						mov->mv[rb->i] = 'd';
						return (rb->k = in->size_b - (rb->j + 1));
					}
				}
				rb->j++;
			}
		}
	}
	return (rb->k);
}

int ft_rebs(t_st *in, t_opt *mov)//funcion que cuenta los movimientos de pb necesarios para cada caso
{
	t_num	rb;//estructura de contadores para rb

	mov->mv = (char *) malloc(sizeof (char) * (mov->szc + 1));
	if (mov->mv == NULL)
		return (0);
	rb.i = 0;
	mov->szd = 0;
	while (rb.i < (in->size_a))
	{
		rb.k = -1;
		rb.j = 0;
		rb.k = ft_rebs_tops(in, mov, &rb);
		if (rb.k == -1)
		{
			while (rb.j < in->size_b - 1)
			{
				if (in->a[rb.i] == in->b[rb.j] - 1 && in->a[rb.i] == in->b[rb.j + 1] + 1)
				{
					rb.k = rb.j + 1;
					if (rb.j < in->size_b / 2)
					{
						mov->mv[rb.i] = 'u';
						rb.k = rb.j + 1;
					}
					if (rb.j >= in->size_b / 2)
					{
						mov->mv[rb.i] = 'd';
						rb.k = in->size_b - (rb.j + 1);
					}
					break;
				}
				if (in->a[rb.i] < in->b[rb.j] && in->a[rb.i] > in->b[rb.j + 1])
				{
					rb.k = rb.j + 1;
					if (rb.j <= in->size_b / 2)
					{
						mov->mv[rb.i] = 'u';
						rb.k = rb.j + 1;
					}
					if (rb.j > in->size_b / 2)
					{
						mov->mv[rb.i] = 'd';
						rb.k = in->size_b - (rb.j + 1);
					}
				}
				rb.j++;
			}
		}
		rb.j = 0;
		if (rb.k == -1 && in->a[rb.i] > in->b[0] && in->a[rb.i] < in->b[in->size_b - 1])
		{
			mov->mv[rb.i] = 'u';
			rb.k = 0;
		}
		mov->d[rb.i] = rb.k;
		mov->szd++;
		rb.i++;
	}
	mov->mv[rb.i] = 00;
	rb.i = mov->szd;
	while (rb.i < in->size_c - 1)//pongo a 0 el resto de la cadena d
	{
		mov->d[rb.i] = 0;
		rb.i++;
	}
	return (0);
}

int	ft_add(t_st *in, t_opt *mov)//suma las cadenas c y d
{
	int	i;

	i = -1;
	mov->sze = mov->szc;
	mov->e = (int *) malloc (sizeof (int) * mov->sze);
	if (mov->e == NULL)
	{
		free(in->a);
		free(in->b);
		free(mov->c);
		free(mov->d);
		exit(0);
	}
	while (++i < mov->sze)
		mov->e[i] = mov->c[i] + mov->d[i];
	return (0);
}

int	ft_min(t_st *in, t_opt *mov)//encuentra el minimo movimiento y su posicion
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	ft_max(in, mov);
	mov->m = 0;
	if (in->a[0] == mov->ma)
		mov->m = 1;
	while (i < mov->sze)
	{
		if (mov->e[j] > mov->e[i] && in->a[i] != mov->ma)
		{
			mov->m = i;
			j = i;
		}
		++i;
	}
	return (0);
}
