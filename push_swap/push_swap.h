#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_st
{
	int		*a;//cadena de enteros originales
	int		*b;//cadena de indices
	char	*c;//cadena de chars
	int		size;//numero de enteros en la cadena
}	t_st;


//funciones del ft_start + sus static
int	*ft_int(int i, char **s);
//int			*ft_conv_int_1 (int argc, char **argv);
//int			*ft_conv_int_2 (char **argv);

//funciones del ft_utils_1.c
void	ft_double(t_st *in);
void	ft_come_on(t_st *in);
int		*ft_put_order(t_st *in);
int		*ft_put_index(t_st *in);

//funciones del atoi + sus static
long int	ft_atoi(char *str);

//funciones del split + sus static
char	**ft_split(char *s, char c);
size_t	ft_count(char *s, char c);
int 	ft_strlen(char *str);


# endif
