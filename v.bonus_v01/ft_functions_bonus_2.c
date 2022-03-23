/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 07:27:50 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/23 11:01:36 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_ra(int *i, int sz)
{
	int	j;
	int	k;

	if (sz < 2)
		return (0);
	j = 0;
	k = i[j];
	while (++j < sz)
		i[j - 1] = i[j];
	i[j - 1] = k;
	return (0);
}

int	ft_rb(int *i, int sz)
{
	int	j;
	int	k;

	if (sz < 2)
		return (0);
	j = 0;
	k = i[j];
	while (++j < sz)
	{
		i[j - 1] = i[j];
	}
	i[j - 1] = k;
	return (0);
}

int	ft_rr(int *i, int *j, int szi, int szj)
{
	int	k;
	int	l;

	l = 0;
	if (szi > 1)
	{
		k = i[l];
		while (++l < szi)
			i[l - 1] = i[l];
		i[l - 1] = k;
	}
	if (szj > 1)
	{
		l = 0;
		k = j[l];
		while (++l < szj)
			j[l - 1] = j[l];
		j[l - 1] = k;
	}
	return (0);
}
