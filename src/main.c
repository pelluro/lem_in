/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:54:16 by mipham            #+#    #+#             */
/*   Updated: 2018/02/15 14:19:58 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int		is_empty(char *s)
{
	size_t i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}



static t_map	*map_init_2(t_map *m)
{
	int i;
	int j;

	i = -1;
	m->init_2 = 1;
	m->path = (int*)ft_memalloc(sizeof(int) * 1000);
	m->tab = (int**)ft_memalloc(sizeof(int*) * m->q_rooms);
	m->rooms = (char**)ft_memalloc(sizeof(char*) * (m->q_rooms + 1));
	while (++i < m->q_rooms)
	{
		m->path[i] = -1;
		m->rooms[i] = NULL;
		m->tab[i] = (int*)ft_memalloc(sizeof(int) * m->q_rooms);
		j = -1;
		while (m->tab[i][++j])
			m->tab[i][j] = 0;
	}
	m->rooms[i] = NULL;
	m->path[0] = 0;
	return (m);
}

static t_map	*map_init(void)
{
	t_map *m;

	m = (t_map*)ft_memalloc(sizeof(t_map));
	m->links = ft_strnew(1);
	m->ants_str = ft_strnew(1);
	m->rooms_list = ft_strnew(1);
	m->q_rooms = 0;
	m->ants = 0;
	m->started = 0;
	m->curr_room = 0;
	m->p_ind = 0;
	m->init_2 = 0;
	m->good[0] = 0;
	m->good[1] = 0;
	m->rooms = NULL;
	m->tab = NULL;
	m->path = NULL;
	return (m);
}

static void		read_map(t_map *m)
{
	char *line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (m->ants == 0)
			count_ants(m, line);
		else if (line && (ft_strchr(line, '-') || m->started == 3))
			links(m, line);
		else if ((m->started == 1 || m->started == 2) && !is_empty(line))
			rooms(m, line);
		else
			ft_exit(m, 1);
		ft_strdel(&line);
	}
	if (!m->ants || !m->links[0])
	{
		ft_exit(m, 1);
	}
	m = map_init_2(m);
}

int				main(int ac, char **av)
{
	t_map	*m;

	m = map_init();
	read_map(m);
	add_rooms(m);
	if (!m->good[0] || !m->good[1])
		ft_exit(m, 1);
	create_tab(m);
	//show the matrix and connection inside them
	if (ac == 2 && !ft_strcmp(av[1], "-v"))
		print_map(m);
	if (solve(m, 0))
		result(m);
	else
		ft_exit(m, 1);
	ft_exit(m, 0);
	free(m);
	return (0);
}
