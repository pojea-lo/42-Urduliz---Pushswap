/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:54:56 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/16 17:12:38 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_come_on(t_st *in, t_opt *mov)
{
	int	i;

	in->size_c = in->size_a;
	in->b = ft_put_order (in);
	in->a = ft_put_index (in);
	ft_restart (in);
	i = ft_check (in);
	if (i == 0)
	{
		free (in->a);
		free (in->b);
		exit(0);
	}
	if (in->size_a < 11)
		ft_zero (in, mov);
	else if (in->size_a > 10)
		ft_first (in, mov);
	free (in->b);
}

int	ft_first(t_st *in, t_opt *mov)
{
	ft_minmax(in, mov);
	ft_pb(in);
	ft_pb(in);
	while (in->size_a != 0)
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
	ft_min (mov);
	ft_rres_mov(in, mov);
	ft_rrres_mov(in, mov);
	ft_reas_mov(in, mov);
	ft_rebs_mov(in, mov);
	free (mov->c);
	free (mov->d);
	free (mov->e);
	free (mov->mv);
	return (0);
}
