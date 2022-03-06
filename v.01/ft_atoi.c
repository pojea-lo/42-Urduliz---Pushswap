#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	r;

	i = 0;
	r = 0;
	n = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		r = (str[i] - '0') + (r * 10);
		i++;
	}
	return (r * n);
}
