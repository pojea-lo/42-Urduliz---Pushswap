#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_st
{
	int		*a;
	char	*c;
}	t_st;


//funciones del ft_start + sus static
int	*ft_int (int i, char **s);
//int			*ft_conv_int_1 (int argc, char **argv);
//int			*ft_conv_int_2 (char **argv);


//funciones del atoi + sus static
int	ft_atoi (char *str);

//funciones del split + sus static
char	**ft_split (char *s, char c);
int 	ft_strlen (char *str);


# endif
