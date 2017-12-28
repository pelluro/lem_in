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

static t_map_read	*ft_map(void)
{
	t_map_read *map;

	map = (t_map_read*)ft_memalloc(sizeof(t_map_read));
	if (map == NULL)
		return (0);
	map->ants = ft_strnew(1);
	map->links = ft_strnew(1);
	map->room = ft_strnew(1);
	map->nb_ants = 0;
	map->nb_room = 0;
	map->nb_links = 0;
	return (map);
}

int main(void)
{
	t_map_read *map;
	ft_read_map(map);

	return(0);
}