/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 06:35:44 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/03/23 16:35:07 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

//principal structure with size
typedef struct s_st
{
	int		*a;
	int		*b;
	char	*str;
	char	**s;
	char	*cmd;
	int		p;
	int		size_a;	
	int		size_b;
}	t_st;

//checker
void	ft_int_bonus(int argn, char **arg);
//static int	*ft_conv_int_1_bonus(char **s, t_st *in)
//static void	ft_free_bonus(long int b, t_st *in)
//static void	ft_double(t_st *in);
void	ft_print(t_st *in, int j);
void	ft_free_bonus_1 (t_st *in);

//ft_utils_bonus_0
void	ft_checker(t_st *in);
void	ft_check_mov(t_st *in, char *arg);
void	ft_cmd_error(t_st *in);
int		ft_strcmp(char *s1, char *s2);
int		ft_check_bonus(t_st *in);

//ft_functions_bonus_1
int		ft_sa(int *i, int sz);
int		ft_sb(int *i, int sz);
int		ft_ss(int *i, int *j, int szi, int szj);
int		ft_pa(t_st *in);
int		ft_pb(t_st *in);

//ft_functions_bonus_2
int		ft_ra(int *i, int sz);
int		ft_rb(int *i, int sz);
int		ft_rr(int *i, int *j, int szi, int szj);

//ft_functions_bonus_3
int		ft_rra(int *i, int sz);
int		ft_rrb(int *i, int sz);
int		ft_rrr(int *i, int *j, int szi, int szj);

//atoi functions with his static
long int	ft_atoi(char *str);

//split functions with his static
char		**ft_split(char *s, char c);
size_t		ft_count(char *s, char c);
int			ft_strlen(char *str);

//gnl
char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
int		ft_strchr(char *s, char c);
char	*ft_line(char *rest, char *buf, int bread);
char	*ft_updrest(char *rest, int bread);
void	*ft_memcpy(void *dest, const void *org, size_t n);
char	*ft_copyrest(char *rest, size_t i);
char	*ft_malloc_1(int bufsz);

//printf
int		ft_printf(const char *s, ...);
size_t	ft_cases(char s, va_list ptr, size_t j);
size_t	ft_putstr(char *r, size_t j);
size_t	ft_putint(int n, size_t j);
char	*ft_itoa(int n);
char	*ft_neg(int n);
char	*ft_pos(long int n);
int		ft_count_printf(long int n);

#endif