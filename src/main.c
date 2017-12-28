#include "../include/lem_in.h

static int ft_isempty(char *s)
{
	int i;

	i = 0;
	while (s[i] && ft_isspace(s))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

int main(void)
{
	t_map_read *map;
	ft_read(m);

	return(0);
}