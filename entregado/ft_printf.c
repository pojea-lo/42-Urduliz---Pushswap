/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:46:22 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/24 07:36:39 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_printf(const char *s, ...)
{
	size_t		i;
	size_t		j;
	va_list		ptr;

	i = 0;
	j = 0;
	va_start (ptr, s);
	while (s[i] != '\0')
	{	
		if (s[i] == '%' && s[i])
		{
			i++;
			j = ft_cases (s[i], ptr, j);
			i++;
		}
		else
		{
			write (1, &s[i], 1);
			i++;
			j++;
		}
	}
	va_end (ptr);
	return (j);
}

size_t	ft_cases(char s, va_list ptr, size_t j)
{
	if (s == 's')
		j = ft_putstr (va_arg (ptr, char *), j);
	else if (s == 'd')
		j = ft_putint (va_arg (ptr, int), j);
	else if (s == '%')
	{
		write (1, "%", 1);
		j = j + 1;
	}
	else
		write (1, "ERROR", 5);
	return (j);
}

size_t	ft_putstr(char *r, size_t j)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen (r);
	if (r == NULL)
	{
		write (1, "(null)", 6);
		j = j + 6;
		return (j);
	}
	while (i < l)
	{
		write (1, &r[i], 1);
		i++;
		j++;
	}
	return (j);
}

size_t	ft_putint(int n, size_t j)
{
	int		i;
	char	*r;

	i = 0;
	r = ft_itoa (n);
	while (i < ft_strlen (r))
	{
		write (1, &r[i], 1);
		i++;
		j = j + 1;
	}
	free (r);
	return (j);
}
