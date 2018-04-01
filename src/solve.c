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

int				ft_isuseful(t_map *m, int roomindex, int stepcount)
{
	if (m->bestpathperroom[roomindex] == -1 ||
        stepcount < m->bestpathperroom[roomindex])
	{
		m->bestpathperroom[roomindex] = stepcount;
		return (1);
	}
	return (0);
}

int             ft_isnewroom(t_map *m, int* path, int roomindex)
{
    int i;

    i = 0;
    while(i < m->nb_rooms)
    {
        if(path[i] == roomindex)
            return (0);
        i++;
    }
    return (1);
}

void    checkbestsize(t_map *m, int* path, int currentstepscount)
{
    if (m->best_size == -1 || currentstepscount < m->best_size)
    {
        m->best_size = currentstepscount;
        ft_copytabint(m, path, &(m->path));
        free(path);
    }
}

void			solve(t_map *m, int* path, int currentroomindex)
{
	int i;
	int currentstepscount;
    int* pathnext;

	i = -1;
	currentstepscount = ft_sizetab(path);
	if (m->best_size > -1 && currentstepscount >= m->best_size)
		return;
	while (++i < m->nb_rooms)
	{
		if (m->tab[currentroomindex][i] && ft_isnewroom(m, path, i)
            && ft_isuseful(m, i, currentstepscount))
		{
            if (i == m->nb_rooms - 1)
            {
                path[currentstepscount++] = i;
                checkbestsize(m, path, currentstepscount);
                return;
            }
            pathnext = NULL;
            ft_copytabint(m, path, &pathnext);
            pathnext[currentstepscount] = i;
            solve(m, pathnext, i);
		}
	}
}