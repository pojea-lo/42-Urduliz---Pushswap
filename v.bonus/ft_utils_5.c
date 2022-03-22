/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:31:45 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/16 17:36:30 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function that make the movements of the stack a
void	ft_reas_mov(t_st *in, t_opt *mov)
{
	int	i;

	i = mov->c[mov->m];
	if (mov->m <= mov->szc / 2)
	{
		while (i > 0)
		{
			ft_ra(in->a, in->size_a);
			i--;
		}
	}
	if (mov->m > mov->szc / 2)
	{
		while (i > 0)
		{
			ft_rra(in->a, in->size_a);
			i--;
		}
	}
	mov->szc--;
}

//function that make the movements of the stack b
void	ft_rebs_mov(t_st *in, t_opt *mov)
{
	int	i;

	if (mov->mv[mov->m] == 'u')
	{
		i = mov->d[mov->m];
		while (i > 0)
		{
			ft_rb(in->b, in->size_b);
			i--;
		}
	}
	if (mov->mv[mov->m] == 'd')
	{
		i = mov->d[mov->m];
		while (i > 0)
		{
			ft_rrb(in->b, in->size_b);
			i--;
		}
	}
	mov->szd--;
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

//function that makes rr movements before ra or rb movements
void	ft_rres_mov(t_st *in, t_opt *mov)
{
	if (mov->c[mov->m] > 0 && mov->d[mov->m] > 0)
	{
		if (mov->c[mov->m] >= mov->d[mov->m] && mov->m <= mov->szc / 2 && \
		mov->mv[mov->m] == 'u')
		{
			while (mov->d[mov->m] != 0)
				ft_rres_mov_aux (in, mov);
		}
		else if (mov->c[mov->m] < mov->d[mov->m] && mov->m <= mov->szc / 2 && \
		mov->mv[mov->m] == 'u')
		{
			while (mov->c[mov->m] != 0)
				ft_rres_mov_aux (in, mov);
		}
		if (mov->c[mov->m] == 0)
			mov->szc--;
		if (mov->d[mov->m] == 0)
			mov->szd--;
	}
}

//function that makes rrr movements before ra or rb movements
void	ft_rrres_mov(t_st *in, t_opt *mov)
{
	if (mov->c[mov->m] > 0 && mov->d[mov->m] > 0)
	{
		if (mov->c[mov->m] >= mov->d[mov->m] && mov->m > mov->szc / 2 && \
		mov->mv[mov->m] == 'd')
		{
			while (mov->d[mov->m] != 0)
				ft_rrres_mov_aux (in, mov);
		}
		else if (mov->c[mov->m] < mov->d[mov->m] && mov->m > mov->szc / 2 && \
		mov->mv[mov->m] == 'd')
		{
			while (mov->c[mov->m] != 0)
				ft_rrres_mov_aux (in, mov);
		}		
		if (mov->c[mov->m] == 0)
			mov->szc--;
		if (mov->d[mov->m] == 0)
			mov->szd--;
	}
}
