/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:34:35 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/16 17:35:07 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function continuation of rr movements
void	ft_rres_mov_aux(t_st *in, t_opt *mov)
{
	ft_rr(in->a, in->b, in->size_a, in->size_b);
	mov->c[mov->m]--;
	mov->d[mov->m]--;
}

//function continuation of rrr movements
void	ft_rrres_mov_aux(t_st *in, t_opt *mov)
{
	ft_rrr(in->a, in->b, in->size_a, in->size_b);
	mov->c[mov->m]--;
	mov->d[mov->m]--;
}
