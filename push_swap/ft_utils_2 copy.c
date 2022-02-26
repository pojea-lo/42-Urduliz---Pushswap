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
	free (in->a);
	free (in->b);
	write (1, "OK\n", 3);
	return (0);//si esta ordenado
}

int	ft_options(t_st *in)
{
	t_opt	mov;

	mov.c = (int *) malloc (sizeof (int) * (in->size_c - 1));
	mov.d = (int *) malloc (sizeof (int) * (in->size_c - 1));
	if (mov.c == NULL || mov.d == NULL)
	{
		free (in->a);
		free (in->b);
		exit (0);
	}
	ft_reas (in, &mov);
	ft_rebs (in, &mov);
	ft_add (in, &mov);
	ft_min (&mov);
	ft_reas_mov(in, &mov);
	ft_rebs_mov(in, &mov);
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
//	printf ("mov ra: ");
//	ft_printf(mov->c, mov->szc);
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
		j = 1;
		k = 0;
		while (j < (in->size_b))
		{
			if (in->a[i] == in->b[j - 1] - 1 && in->a[i] == in->b[j] + 1)
			{
				k = j - 1;
				printf ("a[%d] = %d, medio menor mayor y k = %d\n", i, in->a[i], k);
				break;
			}
			if (in->a[i] == in->b[j - 1] + 1  && in->a[i] == in->b[j] - 1)
			{
				k = j - 1;
				printf ("a[%d] = %d, medio mayor menor y k = %d\n", i, in->a[i], k);
				break;
			}
			j++;
		}
		j = 1;
		while (j < (in->size_b))
		{
			if (in->a[i] == in->b[j - 1] - 1)
			{
				k = j - 1;
				printf ("a[%d] = %d, medio MENOR y k = %d\n", i, in->a[i], k);
				break;
			}
			if (in->a[i] == in->b[j - 1] + 1)
			{
				k = j;
				printf ("a[%d] = %d, medio MAYOR y k = %d\n", i, in->a[i], k);
				break;
			}
			j++;
		}
		if (k == 0)
		{
			if (in->a[i] < in->b[0])
			{
				printf ("a[%d] = %d, menor\n", i, in->a[i]); 
				k = 0;
			}
			else
			{
				printf ("a[%d] = %d, mayor\n", i, in->a[i]); 
				k = 0;
			}
		}
		//coletilla 1
		mov->d[i] = k;
		mov->szd++;
		i++;
	}
	mov->szd--;
	printf ("mov rb: ");
	ft_printf(mov->d, mov->szd);
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
	printf ("mov e: ");
	ft_printf(mov->e, mov->sze);
	return (0);
}

int	ft_min(t_opt *mov)//encuentra el minimo movimiento y su posicion
{
	int	i;
	int	j;

	i = 1;
	j = 0;
/*	mov->e[0] = 8;
	mov->e[1] = 7;
	mov->e[2] = 5;
	mov->e[3] = 1;*/
//	ft_printf (mov->e, mov->sze);
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
	printf ("m %d\n", mov->m);
	return (0);
}

