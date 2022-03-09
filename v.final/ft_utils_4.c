/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:21:43 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/09 11:28:08 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//functioon that make the movements of the stack a
void	ft_reas_mov(t_st *in, t_opt *mov)
{
	int	i;

	i = mov->c[mov->m];
	if (mov->m <= mov->szc / 2)
	{
		while (i > 0)
		{
			ft_ra(in->a, in->size_a);
			mov->szc--;
			i--;
		}
	}
	if (mov->m > mov->szc / 2)
	{
		while (i > 0)
		{
			ft_rra(in->a, in->size_a);
			mov->szc--;
			i--;
		}
	}
}

//functioon that make the movements of the stack b
void	ft_rebs_mov(t_st *in, t_opt *mov)
{
	int	i;

	if (mov->mv[mov->m] == 'u')
	{
		i = mov->d[mov->m];
		while (i > 0)
		{
			ft_rb(in->b, in->size_b);
			mov->szd--;
			i--;
		}
	}
	if (mov->mv[mov->m] == 'd')
	{
		i = mov->d[mov->m];
		while (i > 0)
		{
			ft_rrb(in->b, in->size_b);
			mov->szd--;
			i--;
		}
	}
	ft_pb(in);
}

//function that put the maxim value of the stack b in the top
void	ft_put_max(t_st *in, t_opt *mov)
{
	int	i;

	i = 0;
	ft_minmax (in, mov);
	while (i < in->size_b && in->b[i] != mov->mb)
	{
		i++;
	}
	if (i <= in->size_b / 2)
	{
		while (in->b[0] != mov->mb)
			ft_rb(in->b, in->size_b);
	}
	else
	{
		while (in->b[0] != mov->mb)
			ft_rrb(in->b, in->size_b);
	}
}

//functions that makes the pa movements
void	ft_pass(t_st *in)
{
	while (in->size_b > 0)
		ft_pa(in);
}

//function that makes rr movements before ra or rb movements
void	ft_rrs_mov(t_st *in, t_opt *mov)
{
	if (mov->c[mov->m] > 0 && mov->d[mov->m] > 0)
	{
		if (mov->c[mov->m] >= mov->d[mov->m])
		{
			while (mov->d[mov->m] != 0)
			{
				ft_rr(in->a, in->b, in->size_a, in->size_b);
				mov->c[mov->m]--;
				mov->d[mov->m]--;
				mov->szc--;
				mov->szd--;
			}
		}
		else
		{
			while (mov->c[mov->m] != 0)
			{
				ft_rr(in->a, in->b, in->size_a, in->size_b);
				mov->c[mov->m]--;
				mov->d[mov->m]--;
				mov->szc--;
				mov->szd--;
			}
		}
	}
}
