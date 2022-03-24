/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 07:25:46 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/24 07:30:44 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//printf the stacks
void	ft_print(t_st *in, int j)
{
	int	i;

	i = -1;
	if (j == 1)
	{
		ft_printf ("\n** Stack A **********************\n\n");
		while (++i < (in->size_a - 1))
			ft_printf ("%d - ", in->a[i]);
		ft_printf ("%d\n\n", in->a[i]);
	}
	else if (j == 2)
	{
		ft_printf ("\n** Stack A-B ********************\n\n");
		while (++i < (in->size_a - 1))
			ft_printf ("%d - ", in->a[i]);
		ft_printf ("%d\n\n", in->a[i]);
		i = -1;
		while (++i < (in->size_b - 1))
			ft_printf ("%d - ", in->b[i]);
		ft_printf ("%d\n\n", in->b[i]);
	}
	ft_exit (in);
}

void	ft_exit(t_st *in)
{
	if (ft_check_bonus(in) == 1)
	{
		ft_printf ("****************** Put command **\n\n");
		if (in->cmd != NULL)
			free (in->cmd);
	}
	else
	{
		ft_free_bonus_1 (in);
		exit (1);
	}
	ft_checker (in);
}

void	ft_free_bonus_1(t_st *in)
{
	free (in->a);
	if (in->b != NULL)
		free (in->b);
	if (in->cmd != NULL)
		free (in->cmd);
}
