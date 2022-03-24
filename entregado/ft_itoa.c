/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:55:10 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/24 07:37:02 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_itoa(int n)
{
	if (n < 0)
		return (ft_neg (n));
	else
		return (ft_pos(n));
}

char	*ft_neg(int n)
{
	char	*r;
	int		i;
	char	c;

	i = ft_count_printf(n);
	r = (char *)malloc (sizeof (char) * (ft_count_printf(n) + 1));
	if (r == NULL)
		return (NULL);
	r[i] = '\0';
	i--;
	if (n == -2147483648)
	{
		r[i] = '8';
		n = -214748364;
		i--;
	}
	n = -n;
	while (i >= 0)
	{
		c = (n % 10) + '0';
		r[i--] = c;
		n = n / 10;
	}
	r[0] = '-';
	return (r);
}

char	*ft_pos(long int n)
{
	char	*r;
	int		i;
	char	c;

	i = ft_count_printf(n);
	r = (char *)malloc (sizeof (char) * (ft_count_printf(n) + 1));
	if (r == NULL)
		return (NULL);
	r[i] = '\0';
	i--;
	while (i >= 0)
	{
		c = (n % 10) + '0';
		r[i--] = c;
		n = n / 10;
	}
	return (r);
}

int	ft_count_printf(long int n)
{
	int	c;

	c = 0;
	if (n == 0)
	{
		c = 1;
		return (c);
	}
	if (n < 0)
		c++;
	while (n != 0)
	{
		c++;
		n = n / 10;
	}
	return (c);
}
