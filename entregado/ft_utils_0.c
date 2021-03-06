/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:13:35 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/09 10:13:38 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_transpas(int *a, int *b, int sz);

//check duplicity
void	ft_double(t_st *in)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < in->size_a)
	{
		j = i + 1;
		while (j < in->size_a)
		{
			if (in->a[i] == in->a[j])
			{
				write (1, "Error\n", 6);
				free (in->a);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

//put in order the auxiliar stack b
int	*ft_put_order(t_st *in)
{
	int	i;
	int	j;
	int	k;

	in->b = ft_transpas (in->a, in->b, in->size_c);
	i = 0;
	while (i < in->size_c)
	{
		j = 0;
		while (j < in->size_c)
		{
			if (in->b[i] < in->b[j])
			{
				k = in->b[j];
				in->b[j] = in->b[i];
				in->b[i] = k;
			}
			j++;
		}
		i++;
	}
	i = -1;
	return (in->b);
}

//make a copy of one stack to other
static int	*ft_transpas(int *a, int *b, int sz)
{
	int	i;

	b = (int *) malloc (sizeof (int) * sz);
	if (b == NULL)
	{	
		free (a);
		exit (0);
	}
	i = -1;
	while (++i < sz)
		b[i] = a[i];
	return (b);
}

//put index in the auxiliar stack b
int	*ft_put_index(t_st *in)
{
	int	i;
	int	j;
	int	*c;

	c = (int *) malloc(sizeof(int) * in->size_c);
	if (c == NULL)
		exit (0);
	i = 0;
	while (i < in->size_c)
	{
		j = 0;
		while (j < in->size_c)
		{
			if (in->a[i] == in->b[j])
			{
				c[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free (in->a);
	return (c);
}

//make reset the auxiliar stack b
void	ft_restart(t_st *in)
{
	free (in->b);
	in->size_b = 0;
	in->b = (int *) malloc (sizeof (int) * in->size_c);
	if (in->b == NULL)
	{
		free (in->a);
		exit (0);
	}
}
