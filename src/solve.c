/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:54:43 by mipham            #+#    #+#             */
/*   Updated: 2018/01/03 15:54:45 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	is_last_room(t_map *m, int i)
{
	if (m->tab[i][m->q_rooms - 1])
	{
		m->path[++(m->p_ind)] = i;
		m->path[++(m->p_ind)] = m->q_rooms - 1;
		return (1);
	}
	return (0);
}

static void	erase_element(t_map *m, int i, int path)
{
	m->tab[m->curr_room][i] = 0;
	m->tab[i][m->curr_room] = 0;
	if (path)
	{
		m->path[m->p_ind] = -1;
		m->p_ind--;
	}
}

static int	find_door(t_map *m, int r_index, int d_index)
{
	while (d_index < m->q_rooms)
	{
		if (m->tab[r_index][++d_index] == 1)
			return (d_index);
	}
	return (0);
}

static int	is_in_path(t_map *m, int r_index)
{
	int i;
	
	i = -1;
	while (m->path[++i] != -1)
	{
		if (m->path[i] == r_index)
			return (1);
	}
	return (0);
}

int			solution(t_map *m, int i)
{
	if (m->tab[0][m->q_rooms - 1])
	{
		m->path[++(m->p_ind)] = m->q_rooms - 1;
		return (1);
	}
	while ((i = find_door(m, m->curr_room, i)))
	{
		if (is_last_room(m, i))
			return (1);
		else if (is_in_path(m, i))
			erase_element(m, i, 0);
	}
	if ((m->curr_room = find_door(m, m->curr_room, 0)) == 0)
	{
		if (m->p_ind == 0 || m->curr_room == 0)
			return (0);
		m->curr_room = m->path[m->p_ind - 1];
		erase_element(m, m->path[m->p_ind], 1);
		if (solution(m, 0))
			return (1);
	}
	m->path[++(m->p_ind)] = m->curr_room;
	if (solution(m, 0))
		return (1);
	return (0);
}
