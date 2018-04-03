/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:54:16 by mipham            #+#    #+#             */
/*   Updated: 2018/04/03 11:56:01 by mipham           ###   ########.fr       */
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
	m->tab = (int**)ft_memalloc(sizeof(int*) * m->nb_rooms);
	m->rooms = (char**)ft_memalloc(sizeof(char*) * (m->nb_rooms + 1));
    m->bestpathperroom  = (int*)ft_memalloc(sizeof(int*) * m->nb_rooms);

	while (++i < m->nb_rooms)
	{
		m->bestpathperroom[i] = -1;
		m->rooms[i] = NULL;
        m->tab[i] = (int*)ft_memalloc(sizeof(int) * m->nb_rooms);
		j = -1;
		while (m->tab[i][++j])
			m->tab[i][j] = 0;
	}
	m->rooms[i] = NULL;
    return (m);
}

static t_map	*map_init(void)
{
	t_map *m;

	m = (t_map*)ft_memalloc(sizeof(t_map));
	m->links = ft_strnew(1);
	m->ants_str = ft_strnew(1);
	m->rooms_list = ft_strnew(1);
	m->nb_rooms = 0;
	m->ants = 0;
	m->flag = 0;
	m->best_size = -1;
	m->init_2 = 0;
	m->good[0] = 0;
	m->good[1] = 0;
	m->rooms = NULL;
	m->tab = NULL;
	m->path = NULL;
	m->bestpathperroom = NULL;
	m->roommap = NULL;
	return (m);
}


static void		read_map(t_map *m)
{
	char *line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (m->ants == 0)
			count_ants(m, line);
		else if (line && (ft_strchr(line, '-') || m->flag == 3))
			links(m, line);
		else if ((m->flag == 1 || m->flag == 2) && !is_empty(line))
			rooms(m, line);
		else
			ft_exit(m, 1);
		free(line);
		line = NULL;
	}
	ft_maprooms(m);
	if (!m->ants || !m->links[0] || !ft_checkcoords(m, 0))
		ft_exit(m, 1);
	m = map_init_2(m);
}

void            ft_initpath(t_map* m, int **path)
{
    int i;

    i = 0;
    (*path) = (int*)malloc(sizeof(int) * (m->nb_rooms));
    while(i < m->nb_rooms)
	{
        (*path)[i] = -1;
        i++;
    }
}

int				main(int ac, char **av)
{
	t_map	*m;
	int     *path;

//	freopen("/mnt/c/Users/pellu/lem_in/maps/big","r",stdin);
	m = map_init();
	read_map(m);
	add_rooms(m);
	if (!m->good[0] || !m->good[1])
		ft_exit(m, 1);
	create_tab(m);
	ft_initpath(m, &path);
	path[0] = 0;
	if (ac == 2 && !ft_strcmp(av[1], "-v"))
		print_map(m);
	solve(m, path, 0);
	if (m->best_size > -1)
	{
		result(m);
		ft_exit(m, 0);
	}
	else
		ft_exit(m, 1);
	return (0);
}
