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
