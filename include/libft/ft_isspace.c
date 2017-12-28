
#include "libft.h"

int		ft_isspace(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\v')
			return (1);
		i++;
	}
	return (0);
}