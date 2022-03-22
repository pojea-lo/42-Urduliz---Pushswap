/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 06:35:44 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/16 17:36:42 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

//principal structure with size
typedef struct s_st
{
	int		*a;
	int		*b;
	char	*str;
	char	**s;
	int		p;
	int		size_a;	
	int		size_b;
	int		size_c;
}	t_st;

//structure for movements of the algorithmic
typedef struct s_opt
{
	int		m;
	int		ma;
	int		mb;
	int		na;
	int		nb;
	int		*c;
	int		szc;
	char	cc;
	int		*d;
	int		szd;
	char	*mv;
	int		*e;
	int		sze;
}	t_opt;

//auxiliar structure for counters
typedef struct s_num
{
	int		i;
	int		j;
	int		k;
}	t_num;

//push_swap functions with his static - converts input data to int
int			*ft_int(int i, char **s);

//ps_1.c
void		ft_come_on(t_st *in, t_opt *mov);
int			ft_first(t_st *in, t_opt *mov);
int			ft_options(t_st *in, t_opt *mov);

//ft_utils_0.c - ndex to the stack a
void		ft_double(t_st *in);
int			*ft_put_order(t_st *in);
int			*ft_put_index(t_st *in);
void		ft_restart(t_st *in);

//ft_utils_1.c - the checker and algorithm up to 10 numbers
int			ft_check(t_st *in);
void		ft_zero(t_st *in, t_opt *mov);
void		ft_three(t_st *in, t_opt *mov);
void		ft_put_mina(t_st *in, t_opt *mov);

//ft_utils_2.c - clgorithm ontinuation up to 10 numbers
void		ft_five(t_st *in, t_opt *mov);
int			ft_five_top(t_st *in, t_opt *mov, t_num *fv);
int			ft_five_return(int mv, t_st *in, t_opt *mov);
void		ft_five_mov(t_st *in, t_opt *mov, t_num *fv);

//ft_utils_3.c - algorithm for more than 10 numbers
void		ft_minmax(t_st *in, t_opt *mov);
void		ft_reas(t_st *in, t_opt *mov);
void		ft_add(t_st *in, t_opt *mov);
void		ft_min(t_opt *min);

//ft_utils_4.c - algorithm continuation for more than 10 numbers
void		ft_rebs(t_st *in, t_opt *mov);
int			ft_rebs_tops(t_st *in, t_opt *mov, t_num *rb);
void		ft_rebs_1(t_st *in, t_opt *mov, t_num *rb);
char		*ft_mallocc(t_opt *mov);
void		ft_pass(t_st *in);

//ft_utils_5.c - algorithm continuation for more than 10 numbers
void		ft_reas_mov(t_st *in, t_opt *mov);
void		ft_rebs_mov(t_st *in, t_opt *mov);
void		ft_put_max(t_st *in, t_opt *mov);
void		ft_rres_mov(t_st *in, t_opt *mov);
void		ft_rrres_mov(t_st *in, t_opt *mov);

//ft_utils_6.c - algorithm continuation for more than 10 numbers
void		ft_rres_mov_aux(t_st *in, t_opt *mov);
void		ft_rrres_mov_aux(t_st *in, t_opt *mov);

//ft_functions_1
int			ft_sa(int *i, int sz);
int			ft_sb(int *i, int sz);
int			ft_ss(int *i, int *j, int szi, int szj);
int			ft_pa(t_st *in);//cuenta movimientos pa necesarios para cada caso
int			ft_pb(t_st *in);//cuenta movimientos pb necesarios para cada caso

//ft_functions_2
int			ft_ra(int *i, int sz);
int			ft_rb(int *i, int sz);
int			ft_rr(int *i, int *j, int szi, int szj);

//ft_functions_3
int			ft_rra(int *i, int sz);
int			ft_rrb(int *i, int sz);
int			ft_rrr(int *i, int *j, int szi, int szj);

//atoi functions with his static
long int	ft_atoi(char *str);

//split functions with his static
char		**ft_split(char *s, char c);
size_t		ft_count(char *s, char c);
int			ft_strlen(char *str);

//checker
int	*ft_int_bonus(int i, char **s);
//static int	*ft_conv_int_1_bonus(char **s, t_st *in)
//static void	ft_free_bonus(long int b, t_st *in)
void	ft_printf(int *a, int sza);



#endif
