#include "push_swap.h"

void	ft_double (int *a)
{
	int	i;
	int	j;
	int	k;

	j = sizeof (*a); 
	printf ("%d\n", j);
	k = sizeof (a[0]); 
	printf ("%d\n", k);
	i = j / k;
}
