/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 07:23:41 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/09 07:23:43 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int	ft_error_atoi_1(char *str);
static long int	ft_error_atoi_2(long int i);

long int	ft_atoi(char *str)
{
	long int	i;
	long int	n;
	long int	r;

	r = 0;
	if (ft_error_atoi_1 (str) == 2147483648)
		return (2147483648);
	i = 0;
	n = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		r = (str[i] - '0') + (r * 10);
		i++;
	}
	r *= n;
	if (ft_error_atoi_2(r) == 2147483648)
		return (2147483648);
	return (r);
}

static long int	ft_error_atoi_1(char *str)
{
	long int	i;

	i = 0;
	while (str[i] != 00)
	{
		if ((str[i] < 48 && str[i] != 43 && str[i] != 45) || str[i] > 57)
			return (2147483648);
		if ((str[i] == '-' || str[i] == '+') && str[i + 1] == 00) //error por si te meten un - o + solo
			return (2147483648);
		i++;
	}
	return (0);
}

static long int	ft_error_atoi_2(long int i)
{
	if (i < -2147483648 || i > 2147483647)
		return (2147483648);
	return (0);
}
