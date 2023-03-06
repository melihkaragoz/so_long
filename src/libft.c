#include "so_long.h"

char *ft_strdup(char *str)
{
	char *c;
	int i;

	i = 0;
	if (!str)
		return (NULL);
	c = (char *)malloc(ft_strlen(str) + 1);
	if (!c)
		return (NULL);
	while (str[i])
	{
		c[i] = str[i];
		i++;
	}
	c[i] = 0;
	return (c);
}
int	digit_finder(int a) // for ft_itoa function
{
	int	result;

	result = 0;
	if (a == 0)
		return (1);
	else if (a == -2147483648)
		return (11);
	else if (a < 0)
	{
		result++;
		a *= -1;
	}
	while (a > 9)
	{
		a /= 10;
		result++;
	}
	return (++result);
}

void	int_manup(int *a, char *result) // for ft_itoa function
{
	*a *= -1;
	result[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;

	size = digit_finder(n);
	result = malloc(sizeof(char) * size + 1);
	if (!result)
		return (0);
	result[size--] = '\0';
	if (n == 0)
		result[size--] = '0';
	else if (n == -2147483648)
	{
		result[size--] = '8';
		n = -214748364;
	}
	if (n < 0)
		int_manup(&n, result);
	while (n > 0)
	{
		result[size--] = (n % 10) + 48;
		n /= 10;
	}
	return (result);
}
