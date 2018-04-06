/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addroom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:04:45 by mipham            #+#    #+#             */
/*   Updated: 2018/04/06 18:08:31 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void	check_start_end(t_map *m, char **r, int end)
{
	if (end)
	{
		m->rooms[m->nb_rooms - 1] = ft_strdup(r[0]);
		(m->good[1])++;
		return ;
	}
	m->rooms[0] = ft_strdup(r[0]);
	(m->good[0])++;
}

static void	is_good(t_map *m, char **line, char **r, int end)
{
	if (++(m->good[end]) > 1)
	{
		free_tab(r, m, 0);
		free_tab(line, m, 1);
	}
}

static void	is_valid(t_map *m, int i, char **r)
{
	int r_index;

	r_index = room_index(m, r[0], 0);
	if (r_index > 0 && i != r_index)
	{
		free_tab(r, m, 0);
		ft_exit(m, 1);
	}
	m->rooms[i] = ft_strdup(r[0]);
}

void		add_rooms(t_map *m)
{
	int		i;
	int		j;
	char	**line;
	char	**r;

	i = -1;
	j = 1;
	line = ft_strsplit(m->rooms_list, '\n');
	while (line[++i] && j < m->nb_rooms)
	{
		r = ft_strsplit(line[i], ' ');
		if (!ft_strcmp("##start", line[i]))
			is_good(m, line, r, 0);
		else if (!ft_strcmp("##end", line[i]))
			is_good(m, line, r, 1);
		else if (m->good[0] == 1 && line[i][0] != '#')
			check_start_end(m, r, 0);
		else if (m->good[1] == 1 && line[i][0] != '#')
			check_start_end(m, r, 1);
		else if (line[i][0] != '#')
			is_valid(m, j++, r);
		free_tab(r, m, 0);
	}
	free_tab(line, m, 0);
}
