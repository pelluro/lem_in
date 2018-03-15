
#include "libft.h"

int		ft_is_sorted(int *tab, int size)
{
	int		i;

	i = 0;
	while (i + 1 < size)
	{
		if (tab[i] >= tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
