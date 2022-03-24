/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 07:08:49 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/24 07:29:37 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	*ft_conv_int_1_bonus(char **s, t_st *in);
static void	ft_free_bonus(long int b, t_st *in);
static void	ft_double(t_st *in);

int	main(int argc, char *argv[])
{
	ft_int_bonus (argc, argv);
	return (0);
}

void	ft_int_bonus(int argn, char **arg)
{
	t_st	in;

	if (argn != 2)
	{
		write (1, "Argument error\n", 15);
		exit (0);
	}
	if (argn == 2)
		in.a = ft_conv_int_1_bonus (arg, &in);
	ft_double (&in);
	in.b = (int *) malloc (sizeof (int) * in.size_a);
	if (in.b == NULL)
	{
		free (in.a);
		exit (0);
	}
	in.size_b = 0;
	in.cmd = NULL;
	ft_print (&in, 1);
}

//number arguments with "
static int	*ft_conv_int_1_bonus(char **s, t_st *in)
{
	long int	b;

	in->p = -1;
	in->size_a = ft_count(s[1], ' ');
	if (in->size_a == 1)
	{
		if ((((s[1][0] < 48 && s[1][0] != 43 && s[1][0] != 45) ||
		s[1][0] > 57)) || ((s[1][0] == '-' || s[1][0] == '+') &&
		s[1][1] == 00) || (ft_atoi(&s[1][0]) == 2147483648))
			write (1, "Data error\n", 11);
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
		ft_free_bonus (b, in);
		in->a[in->p] = (int) b;
	}
	free (in->s);
	return (in->a);
}

//frees of errors exits with "
static void	ft_free_bonus(long int b, t_st *in)
{
	if (b == 2147483648)
	{
		write (1, "Data error\n", 11);
		while (in->s[++in->p] != 00)
			free (in->s[in->p]);
		free (in->s);
		free (in->a);
		exit (0);
	}
}

//check duplicity
static void	ft_double(t_st *in)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < in->size_a)
	{
		j = i + 1;
		while (j < in->size_a)
		{
			if (in->a[i] == in->a[j])
			{
				write (1, "Duplicate error\n", 16);
				free (in->a);
				exit (0);
			}
			j++;
		}
		i++;
	}
}
