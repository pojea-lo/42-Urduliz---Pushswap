#include "push_swap.h"

int	ft_check(t_st *in)
{
	int	i;

	i = 0;
	while (++i < in->size_a)
	{
		if (in->a[i - 1] > in->a[i])
		{
			write (1, "KO\n", 3);
			return (0);//devuelve 1 si no esta ordenado
		}
	}
//	free (in->a);
//	free (in->b);
	write (1, "OK\n", 3);
	return (0);//si esta ordenado
}

int	ft_options(t_st *in, t_opt *mov)
{
	mov->c = (int *) malloc (sizeof (int) * (in->size_c - 1));
	mov->d = (int *) malloc (sizeof (int) * (in->size_c - 1));
	if (mov->c == NULL || mov->d == NULL)
	{
		free (in->a);
		free (in->b);
		exit (0);
	}
	ft_reas (in, mov);
	ft_rebs (in, mov);
	ft_add (in, mov);
	ft_min (mov);
//	ft_rrs_mov (in, mov);
	ft_reas_mov(in, mov);
	ft_rebs_mov(in, mov);
	return (0);
}

int ft_reas(t_st *in, t_opt *mov)//funcion que cuenta los movimientos de pa necesarios para cada caso
{
	int	i;
	int	j;

	i = -1;
//	printf ("a: ");
//	ft_printf(in->a, in->size_a);
	while (++i <= (in->size_a / 2))
	{
		mov->c[i] = i;
//		printf ("mov[%d] = %d\n", i, mov->c[i]);
	}
	mov->szc = i;
	if ((in->size_a % 2) == 0)
	{
		j = -1;
		while (++j < (in->size_a / 2) - 1)
		{
			mov->c[i + j] = (i - (j + 2));
//			printf ("mov[%d] = %d\n", i + j, mov->c[i + j]);
			mov->szc++;
		}
	}
	else
	{		
		j = -1;
		while (++j < (in->size_a / 2))
		{
			mov->c[i + j] = (i - (j + 1));
//			printf ("mov[%d] = %d\n", i + j, mov->c[i + j]);
			mov->szc++;
		}
	}
	i = mov->szc;
	while (i < in->size_c)//pongo a 0 el resto de la cadena c
	{
		mov->c[i] = 0;
		i++;
	}
//	printf ("mov ra: ");
//	ft_printf(mov->c, mov->szc);
	return (0);
}

int	ft_minmax(t_st *in, t_opt *mov)//encuentra el maximo y minimo de b
{
	int	i;

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
//	printf ("max de b = %d\n", mov->mb);
	return (0);
}

int ft_rebs(t_st *in, t_opt *mov)//funcion que cuenta los movimientos de pb necesarios para cada caso
{
	int	i;
	int	j;
	int	k;

//	ft_printf(in->a, in->size_a);
//	ft_printf(in->b, in->size_b);
	i = 0;
	mov->szd = 1;
	while (i < (in->size_a))
	{
		if (in->a[i] > in->b[0] && in->a[i] < in->b[in->size_b -1])
		{
			k = 0;	
//			printf ("a[%d] = %d, fin menor mayor y k = %d\n", i, in->a[i], k);
		}
		j = 0;
		k = 0;
		while (j < in->size_b)
		{
			ft_minmax (in, mov);
			if (in->a[i] == in->b[j] - 1 && in->a[i] == in->b[j + 1] +1)
			{
				k = j + 1;
//				printf ("a[%d] = %d, exacto y k = %d\n", i, in->a[i], k);
				break;
			}
			if (in->a[i] == in->b[0] +1 && in->a[i] == in->b[in->size_b - 1] - 1)
			{
				k = 0;
//				printf ("a[%d] = %d, extremo exacto y k = %d\n", i, in->a[i], k);
				break;				
			}
			if (in->a[i] < in->b[j] && in->a[i] > in->b[j + 1])
			{
				k = j + 1;	
//				printf ("a[%d] = %d, medio menor mayor y k = %d\n", i, in->a[i], k);
				break;
			}
			if (in->a[i] < in->b[j] || in->a[i] > in->b[j])
			{
				k = -1;
//				printf ("HOLA");
			}
			j++;
		}
		if (k == -1)
		{
			j = 0;
			while (j < in->size_b && k == -1)
			{
				printf("la a[%d] = %d\n", i, in->a[i]);
				if (in->a[i] > mov->mb && in->b[j] == mov->mb)
				{
					k = j;
//					printf ("a[%d] = %d, delante max y k = %d\n", i, in->a[i], k);
				}
				if (in->a[i] < mov->nb && in->b[j] == mov->nb)
				{
//					printf ("el minimo es: %d y j: %d\n", mov->nb, j);
					k = j + 1;
//					printf ("a[%d] = %d, detras min y k = %d\n", i, in->a[i], k);
				}
				j++;
			}
		}
		//coletilla 1
		mov->d[i] = k;
		mov->szd++;
		i++;
	}
	i = mov->szd;
	while (i < in->size_c)//pongo a 0 el resto de la cadena d
	{
		mov->c[i] = 0;
		i++;
	}
	mov->szd--;
//	printf ("mov rb: ");
//	ft_printf(mov->d, mov->szd);
	return (0);
}
//en este punto se puede optimizar la k comparandola con la mitad del largo de la cadena, para ver si bajamos el nuevo elemento o lo subimos

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
//	printf ("mov e: ");
//	ft_printf(mov->e, mov->sze);
	return (0);
}

int	ft_min(t_opt *mov)//encuentra el minimo movimiento y su posicion
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	mov->m = 0;
	while (i < mov->sze)
	{
		if (mov->e[j] > mov->e[i])
		{
			mov->m = i;
			j = i;
		}
		++i;
	}
//	printf ("m %d\n", mov->m);
	return (0);
}

