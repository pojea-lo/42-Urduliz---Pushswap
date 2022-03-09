/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 06:29:01 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/09 07:04:37 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_conv_int_2(int i, char **s, t_st *in);
static int	*ft_conv_int_1(char **s, t_st *in);
static void	ft_free(long int b, t_st *in);

int	main(int argc, char *argv[])
{
	int	*a;

	a = ft_int (argc, argv);
	free (a);
	return (0);
}

int	*ft_int(int i, char **s)
{
	t_st	in;
	t_opt	mov;

	if (i < 2)
		exit (0);
	if (i == 2)
		in.a = ft_conv_int_1 (s, &in);
	else if (i > 2)
		in.a = ft_conv_int_2 (i, s, &in);
	ft_double (&in);
	ft_come_on (&in, &mov);
	return (in.a);
}

static int	*ft_conv_int_1(char **s, t_st *in)//argumentos entre "
{
	long int	b;

	in->p = -1;
	in->size_a = ft_count(s[1], ' ');
	if (in->size_a == 1)
	{
		if ((s[1][0] < 48 && s[1][0] != 43 && s[1][0] != 45) || s[1][0] > 57)
			write (1, "Error\n", 6);
		if ((s[1][0] == '-' || s[1][0] == '+') && s[1][1] == 00)
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
		ft_free (b, in);
		in->a[in->p] = (int) b;
	}
	free (in->s);
	return (in->a);
}

static int	*ft_conv_int_2(int i, char **s, t_st *in)//argumentos sin "
{
	int			j;
	long int	b;

	j = 0;
	in->size_a = i - 1;
	in->p = 0;
	in->a = (int *) malloc(sizeof(int) * (i - 1));
	if (in->a == NULL)
		exit(0);
	while (j < i - 1)
	{
		b = ft_atoi(s[j + 1]);
		if (b == 2147483648)
		{
			write (1, "Error\n", 6);
			free (in->a);
			exit (0);
		}
		in->a[j] = (int) b;
		j++;
	}
	return (in->a);
}

static void	ft_free(long int b, t_st *in)//libera las salidas de errores con "
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
