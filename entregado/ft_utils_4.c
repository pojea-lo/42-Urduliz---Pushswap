/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:32:02 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/09 16:38:39 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function that counts the necessary rb or rrb movements
void	ft_rebs(t_st *in, t_opt *mov)
{
	t_num	rb;

	mov->mv = ft_mallocc (mov);
	rb.i = -1;
	mov->szd = 0;
	while (++rb.i < (in->size_a))
	{
		rb.k = -1;
		ft_minmax (in, mov);
		mov->mv[rb.i] = 'u';
		ft_rebs_tops(in, mov, &rb);
		rb.j = -1;
		ft_rebs_1(in, mov, &rb);
		rb.j = 0;
		if (rb.k == -1 && in->a[rb.i] > in->b[0] && \
		in->a[rb.i] < in->b[in->size_b - 1])
		{
			mov->mv[rb.i] = 'u';
			rb.k = 0;
		}
		mov->d[rb.i] = rb.k;
		mov->szd++;
	}
	mov->mv[rb.i] = 00;
	rb.i = mov->szd;
}

//continuation of the function ft_rebs to the tops
int	ft_rebs_tops(t_st *in, t_opt *mov, t_num *rb)
{
	if (in->a[rb->i] < mov->nb || in->a[rb->i] > mov->mb)
	{
		if ((in->a[rb->i] < mov->nb && in->b[0] == mov->mb) || \
		(in->a[rb->i] > mov->mb && in->b[0] == mov->mb))
			return (rb->k = 0);
		else if ((in->a[rb->i] < mov->nb && in->b[0] == mov->nb) || \
		(in->a[rb->i] > mov->mb && in->b[0] == mov->nb))
			return (rb->k = 1);
		rb->j = 0;
		while (++rb->j < in->size_b - 1)
		{
			if (in->b[rb->j] == mov->nb && in->b[rb->j + 1] == mov->mb)
			{
				if (rb->j <= in->size_b / 2)
					return (rb->k = rb->j + 1);
				if (rb->j > in->size_b / 2)
				{
					mov->mv[rb->i] = 'd';
					return (rb->k = in->size_b - (rb->j + 1));
				}
			}
		}
	}
	return (rb->k);
}

//continuation of the function ft_rebs
void	ft_rebs_1(t_st *in, t_opt *mov, t_num *rb)
{
	if (rb->k == -1)
	{
		while (++rb->j < in->size_b - 1)
		{
			if (in->a[rb->i] == in->b[rb->j] - 1 && \
			in->a[rb->i] == in->b[rb->j + 1] + 1)
			{
				rb->k = in->size_b - (rb->j + 1);
				if (rb->j < in->size_b / 2)
					rb->k = rb->j + 1;
				if (rb->j >= in->size_b / 2)
					mov->mv[rb->i] = 'd';
				break ;
			}
			if (in->a[rb->i] < in->b[rb->j] && in->a[rb->i] > in->b[rb->j + 1])
			{
				rb->k = in->size_b - (rb->j + 1);
				if (rb->j <= in->size_b / 2)
					rb->k = rb->j + 1;
				if (rb->j > in->size_b / 2)
					mov->mv[rb->i] = 'd';
			}
		}
	}
}

char	*ft_mallocc(t_opt *mov)
{
	mov->mv = (char *) malloc(sizeof (char) * (mov->szc + 1));
	if (mov->mv == NULL)
		return (0);
	return (mov->mv);
}
