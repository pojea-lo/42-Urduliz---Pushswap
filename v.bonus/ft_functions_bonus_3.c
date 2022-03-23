/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 07:29:51 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/23 11:01:57 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra(int *i, int sz)
{
	int	j;
	int	k;

	if (sz < 2)
		return (0);
	j = 0;
	k = i[sz - 1];
	while (++j < sz)
		i[sz - j] = i[sz - j - 1];
	i[0] = k;
	return (0);
}

int	ft_rrb(int *i, int sz)
{
	int	j;
	int	k;

	if (sz < 2)
		return (0);
	j = 0;
	k = i[sz - 1];
	while (++j < sz)
		i[sz - j] = i[sz - j - 1];
	i[0] = k;
	return (0);
}

int	ft_rrr(int *i, int *j, int szi, int szj)
{
	int	k;
	int	l;

	l = 0;
	if (szi > 1)
	{
		k = i[szi - 1];
		while (++l < szi)
			i[szi - l] = i[szi - l -1];
		i[0] = k;
	}
	if (szj > 1)
	{
		l = 0;
		k = j[szj - 1];
		while (++l < szj)
			j[szj - l] = j[szj - l -1];
		j[0] = k;
	}
	return (0);
}
