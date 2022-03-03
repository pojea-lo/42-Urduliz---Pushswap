#include "push_swap.h"

static long int	ft_error_atoi_1 (char c);
static long int	ft_error_atoi_2 (long int i);

long int	ft_atoi(char *str)
{
	long int	i;
	long int	n;
	long int	r;

	i = 0;
	r = 0;
	while (str[i] != 00)
	{
		n = ft_error_atoi_1 (str[i]);
		if (n == 2147483648)
			return (2147483648);
		i++;
	}
	i = 0;
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
	i = ft_error_atoi_2 (r *= n);
	if (i == 2147483648)
		return (2147483648);
	return (r);
}

static long int	ft_error_atoi_1 (char c)
{
	if ((c < 48 && c != 43 && c != 45) || c > 57)
	{
		write (1, "Error\n", 6);
		return (2147483648);
	}
	return (0);
}

static long int	ft_error_atoi_2 (long int i)
{
	if (i < -2147483648 || i > 2147483647)
	{
		write (1, "Error\n", 6);
		return (2147483648);
	}
	return (0);
}
