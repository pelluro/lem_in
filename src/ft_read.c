
#include "../include/lem_in.h"

void	ft_read_map( t_map_read *m)
{
	char *str;
	while (get_next_line(1, &str) > 0)
	{
		if (m->nb_ants == 0)
			count_ants();
		else if (ft_strchr(str, '-') != 0)
			ft_get_links(m, &str);
		else if()
			ft_get_room(m, &str);
		else
			ft_exit();
	}
	if (!m->nb_ants || !m->nb_links)
		ft_exit();
}

void	count_ants(t_map_read *m, char *s)
{
	int		i;
	char	*line;

	i = 0;
	m->ants = ft_strjoin(m->ants, s);
	if (s[0] == '#')
		return ;
	line = ft_strtrim(s);
	if (m->nb_ants = ft_atoi(line) <= 0)
		ft_exit();
	while (line[i] != '\n' && line[i] != 0)
	{
		if (!ft_isdigit(line[i++]))
			ft_exit();
	}
}