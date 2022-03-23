/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:31:24 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/16 17:12:32 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function that find the max and the min of stack a and b
void	ft_minmax(t_st *in, t_opt *mov)
{
	int	i;

	i = 1;
	mov->ma = in->a[0];
	mov->na = in->a[0];
	while (i < in->size_a)
	{
		if (mov->ma < in->a[i])
			mov->ma = in->a[i];
		if (mov->na > in->a[i])
			mov->na = in->a[i];
		i++;
	}
	i = 1;
	mov->mb = in->b[0];
	mov->nb = in->b[0];
	while (i < in->size_b)
	{
		if (mov->mb < in->b[i])
			mov->mb = in->b[i];
		if (mov->nb > in->b[i])
			mov->nb = in->b[i];
		i++;
	}
}

//function that counts the necessary ra or rra movements
void	ft_reas(t_st *in, t_opt *mov)
{
	t_num	rm;

	rm.i = -1;
	while (++rm.i <= (in->size_a / 2))
		mov->c[rm.i] = rm.i;
	mov->szc = rm.i;
	rm.j = -1;
	if ((in->size_a % 2) == 0)
	{
		while (++rm.j < (in->size_a / 2) - 1)
		{
			mov->c[rm.i + rm.j] = (rm.i - (rm.j + 2));
			mov->szc++;
		}
	}
	else
	{		
		while (++rm.j < (in->size_a / 2))
		{
			mov->c[rm.i + rm.j] = (rm.i - (rm.j + 1));
			mov->szc++;
		}
	}
}

//function that adds the strings c and d
void	ft_add(t_st *in, t_opt *mov)
{
	int	i;

	i = -1;
	mov->sze = mov->szc;
	mov->e = (int *) malloc (sizeof (int) * mov->sze);
	if (mov->e == NULL)
	{
		free(in->a);
		free(in->b);
		free(mov->c);
		free(mov->d);
		exit(0);
	}
	while (++i < mov->sze)
		mov->e[i] = mov->c[i] + mov->d[i];
}

//function that find the minimum movement and his position
void	ft_min(t_opt *mov)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	mov->m = 0;
	while (i < mov->sze)
	{
		if (mov->e[j] > mov->e[i])
		{
			mov->m = i;
			j = i;
		}
		++i;
	}
}
