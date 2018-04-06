/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:54:07 by mipham            #+#    #+#             */
/*   Updated: 2018/04/04 15:16:21 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void	ft_free_rommap(t_room **roommap)
{
	int i;

	i = 0;
	while (roommap[i])
	{
		free(roommap[i]);
		i++;
	}
	free(roommap);
}

void		ft_exit(t_map *m, int error)
{
	int i;

	free(m->links);
	free(m->ants_str);
	free(m->rooms_list);
	if (m->roommap)
		ft_free_rommap(m->roommap);
	if (m->init_2)
	{
		free(m->path);
		if (m->rooms)
			free_tab(m->rooms, m, 0);
		i = -1;
		while (++i < m->nb_rooms)
			free(m->tab[i]);
		free(m->tab);
		free(m->bestpathperroom);
	}
	free(m);
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}

void		free_tab(char **array, t_map *m, int error)
{
	int i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	if (error)
		ft_exit(m, 1);
	array = NULL;
}
