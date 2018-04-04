/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkroom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:53:41 by mipham            #+#    #+#             */
/*   Updated: 2018/04/04 16:46:01 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		is_number(char **r, t_map *m, char *s)
{
	int i;

	i = 0;
	if (s[0] == '-' || ft_isdigit(s[0]))
	{
		while (s[++i])
		{
			if (!ft_isdigit(s[i]))
				free_tab(r, m, 1);
		}
	}
	else
		free_tab(r, m, 1);
}

static void		validate_room(t_map *m, char *line, int makestructroomindex)
{
	char **r;

	r = ft_strsplit(line, ' ');
	if (r[0][0] == 'L' || r[3] != NULL)
		free_tab(r, m, 1);
	is_number(r, m, r[1]);
	is_number(r, m, r[2]);
	if (makestructroomindex >= 0)
	{
		m->roommap[makestructroomindex] = (t_room *) malloc(sizeof(t_room));
		m->roommap[makestructroomindex]->name = r[0];
		m->roommap[makestructroomindex]->x = ft_atoi(r[1]);
		m->roommap[makestructroomindex]->y = ft_atoi(r[2]);
	}
	free_tab(r, m, 0);
}

int     ft_checkcoords(t_map* m, int roomindex)
{
    int i;

    i = roomindex+1;
    if (roomindex >= m->nb_rooms)
        return (1);
    while (i < m->nb_rooms)
    {
        if (m->roommap[i]->x == m->roommap[roomindex]->x &&
				m->roommap[i]->y == m->roommap[roomindex]->y)
            return (0);
        i++;
    }
    return (ft_checkcoords(m, roomindex + 1));
}


void			rooms(t_map *m, char *line)
{
	m->flag = 2;
	m->rooms_list = join_str(m->rooms_list, line, 0);
	if (line[0] == '#')
		return ;
	validate_room(m, line, - 1);
	m->nb_rooms++;
}

void		ft_maprooms(t_map *m)
{
	int		i;
	int		j;
	char	**roomstab;

	i = 0;
	j = -1;
	roomstab = ft_strsplit(m->rooms_list, '\n');
	if (!roomstab[0])
	{
		free (roomstab);
		return ;
	}
//	free(m->rooms_list);
	m->roommap = (t_room**)ft_memalloc(sizeof(t_room*) * (m->nb_rooms + 1));
	while (++j < m->nb_rooms)
	{
		while (roomstab[i][0] == '#')
		{
			free(roomstab[i]);
			i++;
		}
		validate_room(m, roomstab[i], j);
		free(roomstab[i]);
		i++;
	}
	free_tab(roomstab, m, 0);
	m->roommap[j] = NULL;
}
