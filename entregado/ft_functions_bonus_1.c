/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_bonus_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 07:31:23 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/24 07:31:27 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_sa(int *i, int sz)
{
	int	k;

	if (sz < 2)
		return (0);
	k = i[0];
	i[0] = i[1];
	i[1] = k;
	return (0);
}

int	ft_sb(int *i, int sz)
{
	int	k;

	if (sz < 2)
		return (0);
	k = i[0];
	i[0] = i[1];
	i[1] = k;
	return (0);
}

int	ft_ss(int *i, int *j, int szi, int szj)
{
	int	k;

	if (szi < 2 || szj < 2)
		return (0);
	k = i[0];
	i[0] = i[1];
	i[1] = k;
	k = j[0];
	j[0] = j[1];
	j[1] = k;
	return (0);
}

int	ft_pa(t_st *in)
{
	int	k;

	if (in->size_b == 0)
	{
		return (0);
	}
	k = 0;
	while (k < in->size_a && in->size_a != 0)
	{
		in->a[in->size_a - k] = in->a[in->size_a - 1 - k];
		k++;
	}
	in->a[0] = in->b[0];
	k = 1;
	while (k < in->size_b)
	{
		in->b[k - 1] = in->b[k];
		k++;
	}
	in->size_a++;
	in->size_b--;
	return (0);
}

int	ft_pb(t_st *in)
{
	int	k;

	if (in->size_a == 0)
		return (0);
	k = 0;
	while (k < in->size_b && in->size_b != 0)
	{
		in->b[in->size_b - k] = in->b[in->size_b - 1 - k];
		k++;
	}
	in->b[0] = in->a[0];
	k = 1;
	while (k < in->size_a)
	{
		in->a[k - 1] = in->a[k];
		k++;
	}
	in->size_b++;
	in->size_a--;
	return (0);
}
