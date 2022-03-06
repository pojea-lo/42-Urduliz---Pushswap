#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_st
{
	int		*a;//cadena de enteros originales
	int		*b;//cadena de indices
	char	*str;//cadena de chars
	int		size_a;//numero de enteros en la cadena a
	int		size_b;//numero de enteros en la cadena b
	int		size_c;//numero de enteros de la cadena original
}	t_st;

typedef struct s_opt
{
	int		m;//gurda la posicion del minimo de mov
	int		ma;//maximo valor del stack a
	int		mb;//maximo valor del stack b
	int		na;//minimo valor del stack a
	int		nb;//minimo valor del stack b
	int		*c;//guarda los movimientos ra o rra necesarios
	int		szc;//tamaño de c
	char	cc;//u si es ra y d si es rra
	int		*d;//guarda los movimientos pb necesarios
	int		szd;//tamaño de d
	int		*e;//suma de cadena c + d
	int		sze;
}	t_opt;


//funciones del ft_start + sus static - pasar datos de entrada a int
int	*ft_int(int i, char **s);
//static int	*ft_conv_int_1 (int i, char **s, t_st *in);
//static int	*ft_conv_int_2 (char **s, t_st *in);
//static void	ft_free_1(long int b, int *a);
//static void	ft_free_2(long int b, int *a, char **c, int i);

//funciones del ps_1.c
void	ft_come_on(t_st *in, t_opt *mov);
int		ft_first(t_st *in, t_opt *mov);

//funciones del ft_utils_0.c - ordena hasta 5 argumentos
void	ft_zero (t_st *in, t_opt *mov);
void	ft_three (t_st *in, t_opt *mov);
void	ft_five (t_st *in);//, t_opt *mov);

//funciones del ft_utils_1.c - pasar "a" a indices
void	ft_double(t_st *in);//comprueba duplicidad de datos
int		*ft_transpas(int *a, int *b, int sz);//copia la a en la b
int		*ft_put_order(t_st *in);//ordena la b auxiliar
int		*ft_put_index(t_st *in);//consigue los indices
void	ft_restart (t_st *in);//reinicia el stack b
void	ft_printf(int *a, int saz);//QUITAR ESTA FUNCION!!!

//funciones del ft_utils_2.c
int		ft_check(t_st *in);//comprueba el orden
int		ft_options(t_st *in, t_opt *mov);
int		ft_reas(t_st *in, t_opt *mov);//movimientos necesarios ra
int		ft_minmax(t_st *in, t_opt *mov);//min y max del stack b
int		ft_rebs(t_st *in, t_opt *mov);//movimientos necesarios de rb
int		ft_add(t_st *in, t_opt *mov);//suma ambos movimientos para encontrar el menor
int		ft_min(t_opt *min);//encuentra el minimo movimiento y su posicion

//funciones del ft_utils_3.c
int		ft_reas_mov(t_st *in, t_opt *mov);//movimientos ra y rra
int		ft_rebs_mov(t_st *in, t_opt *mov);//movimientos rb y rrb
int		ft_put_max(t_st *in, t_opt *mov);//en b poner el maximo en la posicion 0
int		ft_pass(t_st *in);//pasamos al a para terminar
int		ft_rrs_mov(t_st *in, t_opt *mov);//movimientos rr y rrr

//funciones del ft_functions_1
int	ft_sa(int *i, int sz);
int	ft_sb(int *i, int sz);
int	ft_ss(int *i, int *j, int szi, int szj);
int ft_pa(t_st *in);
int ft_pb(t_st *in);

//funciones del ft_functions_2
int	ft_ra(int *i, int sz);
int	ft_rr(int *i, int *j,int szi, int szj);
int	ft_rb(int *i, int sz);

//funciones del ft_functions_3
int	ft_rra(int *i, int sz);
int	ft_rrb(int *i, int sz);
int	ft_rrr(int *i, int *j, int szi, int szj);

//funciones del atoi + sus static
int	ft_atoi(char *str);

//funciones del split + sus static
char	**ft_split(char *s, char c);
size_t	ft_count(char *s, char c);
int 	ft_strlen(char *str);


# endif
