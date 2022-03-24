#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_st
{
	int		*a;//cadena de enteros originales
	int		*b;//cadena de indices
	char	*str;//cadena de chars
	char	**s;//cadena de cadenas del split
	int		p;//marca la posicion de la cadena del split
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
	int		*c;//guarda los movimientos ra necesarios
	int		szc;//tamaño de c, que es el mismo que d y e
	char	cc;//u si es ra y d si es rra
	int		*d;//guarda los movimientos rb necesarios
	int		szd;//tamaño de d
	char	*mv;//cadena que guarda si se ha de hacer rb (u) o rrb (d)
	int		*e;//suma de cadena c + d
	int		sze;
}	t_opt;

typedef struct	s_num
{
	int		i;
	int		j;
	int		k;
}	t_num;

//funciones del push_swap + sus static - pasa datos de entrada a int
int			*ft_int(int i, char **s);
//static int	*ft_conv_int_1 (char **s, t_st *in);//datos entre ""
//static int	*ft_conv_int_2 (int i, char **s, t_st *in);//datos sin ""
//static void	ft_free(long int b, t_st *in);//libera si hay error

//funciones del ps_1.c
void		ft_come_on(t_st *in, t_opt *mov);//arranca el push_swap
int			ft_first(t_st *in, t_opt *mov);//arranca ps para mas de 10
int			ft_options(t_st *in, t_opt *mov);//segundo paso del ps para mas de 10

//funciones del ft_utils_0.c - pasar "a" a indices
void		ft_double(t_st *in);//comprueba duplicidad de datos
int			*ft_put_order(t_st *in);//ordena la b auxiliar
//int	*ft_transpas(int *a, int *b, int sz);//copia la a en la b
int			*ft_put_index(t_st *in);//consigue los indices
void		ft_restart (t_st *in);//reinicia el stack b

//funciones del ft_utils_1.c - el checker mio y ordena hasta 10 argumentos
int			ft_check(t_st *in);//comprueba el orden
void		ft_zero (t_st *in, t_opt *mov);//push_swap para <11 numeros
void		ft_three (t_st *in, t_opt *mov);//ordena 3 numeros
void		ft_put_mina(t_st *in, t_opt *mov);//en a poner el minimo en la posicion 0

//funciones del ft_utils_2.c - continuacion del ft_ut_1
void		ft_five (t_st *in, t_opt *mov);//ordena el resto
int			ft_five_top (t_st *in, t_opt *mov, t_num *fv);//funcion aux del five
int			ft_five_return (int mv, t_st *in, t_opt *mov);//marca si u o d
void		ft_five_mov (t_st *in, t_opt *mov, t_num *fv);//hace los movimientos de five

//funciones del ft_utils_3.c - ordena mas de 10 arguentos
void		ft_minmax(t_st *in, t_opt *mov);//min y max del stack b
void		ft_reas(t_st *in, t_opt *mov);//movimientos necesarios ra
void		ft_add(t_st *in, t_opt *mov);//suma ambos movimientos para encontrar el menor
void		ft_min(t_st *in, t_opt *min);//encuentra el minimo movimiento y su posicion

//funciones del ft_utils_4.c - ordena mas de 10 arguentos
void		ft_rebs(t_st *in, t_opt *mov);//movimientos necesarios de rb
int			ft_rebs_tops(t_st *in, t_opt *mov, t_num *rb);//subfuncion de rebs para los extremos mb y nb
void		ft_rebs_1(t_st *in, t_opt *mov, t_num *rb);//subfuncion de rebs
char		*ft_mallocc(t_opt *mov);//maloc con su proteccion

//funciones del ft_utils_5.c - continuacion del ft_ut_3
void		ft_reas_mov(t_st *in, t_opt *mov);//movimientos ra y rra
void		ft_rebs_mov(t_st *in, t_opt *mov);//movimientos rb y rrb
void		ft_put_max(t_st *in, t_opt *mov);//en b poner el mximo en la posicion 0
void		ft_pass(t_st *in);//pasamos al a para terminar
void		ft_rrs_mov(t_st *in, t_opt *mov);//movimientos rr previos a ra o rb para ahorrar

//funciones del ft_functions_1
int			ft_sa(int *i, int sz);
int			ft_sb(int *i, int sz);
int			ft_ss(int *i, int *j, int szi, int szj);
int 		ft_pa(t_st *in);//cuenta movimientos pa necesarios para cada caso
int 		ft_pb(t_st *in);//cuenta movimientos pb necesarios para cada caso

//funciones del ft_functions_2
int			ft_ra(int *i, int sz);
int			ft_rb(int *i, int sz);
int			ft_rr(int *i, int *j, int szi, int szj);

//funciones del ft_functions_3
int			ft_rra(int *i, int sz);
int			ft_rrb(int *i, int sz);
int			ft_rrr(int *i, int *j, int szi, int szj);

//funciones del atoi + sus static
long int	ft_atoi(char *str);

//funciones del split + sus static
char		**ft_split(char *s, char c);
size_t		ft_count(char *s, char c);
int 		ft_strlen(char *str);

#endif
