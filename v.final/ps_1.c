/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:54:56 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/09 09:55:00 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_come_on(t_st *in, t_opt *mov)//arranca el push_swap
{
	int	i;

	in->size_c = in->size_a;
	in->b = ft_put_order (in);
	in->a = ft_put_index (in);//alojar en otra cadena si no se quiere machacar la original con los indices
	ft_restart (in);
	i = ft_check (in);
	if (i == 0)
		exit(0);
	if (in->size_a < 11)
		ft_zero (in, mov);
	else if (in->size_a > 10)
		ft_first (in, mov);
	free (in->b);
}

int	ft_first(t_st *in, t_opt *mov)
{
	ft_max(in, mov);
	if (in->a[0] != mov->ma && in->a[1] != mov->ma)
	{
		ft_pb(in);//paso el primer elemento de a a b
		ft_pb(in);//paso el segundo elemento de a a b
	}
	else
	{
		if (in->a[0] == mov->ma)
			ft_ra(in->a, in->size_a);
		if (in->a[1] == mov->ma)
			ft_rra(in->a, in->size_a);
		ft_pb(in);//paso el primer elemento de a a b
		ft_pb(in);//paso el segundo elemento de a a b
	}
	if (in->b[0] < in->b[1]) //ordeno decreciente el b
		ft_sb(in->b, in->size_b);
	while (in->size_a > 1)
		ft_options (in, mov);
	ft_put_max(in, mov);
	ft_pass(in);
	return (0);
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
	ft_min (in, mov);
	ft_reas_mov(in, mov);
	ft_rebs_mov(in, mov);
	free (mov->c);
	free (mov->d);
	free (mov->e);
	free (mov->mv);
	return (0);
}
