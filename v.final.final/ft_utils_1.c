/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:35:10 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/09 10:37:06 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function to check at the begining the order
int	ft_check(t_st *in)
{
	int	i;

	i = 0;
	while (++i < in->size_a)
	{
		if (in->a[i - 1] > in->a[i])
		{
			return (1);
		}
	}
	return (0);
}

//start of the p_s to <10 numbers
void	ft_zero(t_st *in, t_opt *mov)
{
	while (in->size_a > 3)
		ft_pb(in);
	ft_three (in, mov);
	if (in->size_b != 0)
	{
		ft_five (in, mov);
	}
	ft_check(in);
}

//function to put order 3 numbers
void	ft_three(t_st *in, t_opt *mov)
{
	ft_minmax(in, mov);
	if (in->size_a < 4 && ft_check (in) != 0)
	{
		if (in->a[0] == mov->ma)
		{
			ft_ra(in->a, in->size_a);
			if (in->a[0] > in->a[1])
				ft_sa(in->a, in->size_a);
		}
		else if (in->a[0] == mov->na)
		{
			ft_rra(in->a, in->size_a);
			ft_sa(in->a, in->size_a);
		}
		else
		{
			if (in->a[1] > in->a[2])
				ft_rra(in->a, in->size_a);
			else
				ft_sa(in->a, in->size_a);
		}
	}
}

//function to put the minimum in the top of stack a
void	ft_put_mina(t_st *in, t_opt *mov)
{
	int		i;
	char	cc;

	i = 0;
	while (in->a[i] != mov->na)
		i++;
	if (i < 2)
		cc = 'u';
	else
	{
		i = in->size_a - i;
		cc = 'd';
	}
	while (i != 0)
	{
		if (cc == 'u')
			ft_ra(in->a, in->size_a);
		if (cc == 'd')
			ft_rra(in->a, in->size_a);
		i--;
	}
}
