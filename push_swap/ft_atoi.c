#include "push_swap.h"

static void	ft_error_atoi_1 (char c);
static int	ft_error_atoi_2 (long int i);

int	ft_atoi(char *str)
{
	int			i;
	int			n;
	long int	r;

	i = 0;
	n = 1;
	r = 0;
	while (str[i] != 00)
	{
		ft_error_atoi_1 (str[i]);
		i++;
	}
	i = 0;
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
	ft_error_atoi_2 (r *= n);
	return (r *= n);
}

static void	ft_error_atoi_1 (char c)
{
	if ((c < 48 && c != 43 && c != 45) || c > 57)
	{
		write (1, "Error\n", 6);
	//	system ("leaks a.out");
		exit (0);
	}
}

static int	ft_error_atoi_2 (long int i)
{
	if (i < -2147483648 || i > 2147483647)
	{
		write (1, "Error\n", 6);
	//	system ("leaks a.out");
		exit (0);
	}
	return (0);
}
