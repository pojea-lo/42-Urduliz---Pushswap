/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:37:35 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/09 10:41:21 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function to get the better movement
void	ft_five(t_st *in, t_opt *mov)
{
	t_num	fv;

	fv.i = 0;
	while (fv.i < in->size_b)
	{
		fv.k = -1;
		fv.k = ft_five_top (in, mov, &fv);
		fv.j = -1;
		if (fv.k == -1)
		{
			while (++fv.j < in->size_a)
			{
				if ((in->b[fv.i] > in->a[fv.j] && in->b[fv.i] < \
				in->a[fv.j + 1]) && fv.j < in->size_a - 1)
					fv.k = ft_five_return (fv.j + 1, in, mov);
			}
		}
		ft_five_mov (in, mov, &fv);
	}
	if (ft_check(in) != 0)
		ft_put_mina (in, mov);
}

//continuation of the ft_five
int	ft_five_top(t_st *in, t_opt *mov, t_num *fv)
{
	ft_minmax(in, mov);
	fv->j = 0;
	while (fv->j < in->size_a)
	{
		if (in->b[fv->i] < mov->na)
		{
			if (in->a[fv->j] == mov->na)
				return (ft_five_return (fv->j, in, mov));
		}
		if (in->b[fv->i] > mov->ma)
		{
			if (in->a[fv->j] == mov->ma)
				return (ft_five_return (fv->j + 1, in, mov));
		}
		fv->j++;
	}
	return (-1);
}

//get the information of the type of movement, ra or rra
int	ft_five_return(int mv, t_st *in, t_opt *mov)
{
	if (mv < 2)
	{
		mov->cc = 'u';
		return (mv);
	}
	else
	{
		mov->cc = 'd';
		return (in->size_a - mv);
	}
}

//function that makes the movements
void	ft_five_mov(t_st *in, t_opt *mov, t_num *fv)
{
	while (fv->k > 0)
	{
		if (mov->cc == 'u')
			ft_ra(in->a, in->size_a);
		if (mov->cc == 'd')
			ft_rra(in->a, in->size_a);
		fv->k--;
	}
	ft_pa(in);
}
