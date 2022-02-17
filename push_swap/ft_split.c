#include "push_swap.h"

static size_t	ft_count(char *s, char c);
static char		*ft_copy(char *s, int i, int j);
static char		**ft_malloc(char *s, char c);

char	**ft_split(char *s, char c)
{
	char	**r;
	int		i;
	int		j;
	int		l;

	i = 0;
	l = 0;
	if (s == NULL)
		return (NULL);
	r = ft_malloc (s, c);
	while (s[i] != '\0' && r != NULL)
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] != c && i < ft_strlen(s))
				i++;
			r[l++] = ft_copy(s, i, j);
		}
		else
			i++;
	}
	if (r != NULL)
		r[l] = NULL;
	return (r);
}

static char	*ft_copy(char *s, int i, int j)
{
	char	*p;
	char	*r;
	int		m;

	m = 0;
	p = (char *)malloc (sizeof(char) * (((i - 1) - j) + 2));
	if (p == NULL)
		return (NULL);
	while (j <= (i - 1))
		p[m++] = (char)s[j++];
	p[m] = '\0';
	return (p);
}

static size_t	ft_count(char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i + 1] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_malloc(char *s, char c)
{
	char	**r;

	r = (char **)malloc (sizeof(char *) * (ft_count(s, c) + 1));
	if (r == NULL)
		r = NULL;
	return (r);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

