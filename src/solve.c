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

static int	is_last_room(t_map *m, int* path, int i)
{
	if (m->tab[i][m->nb_rooms - 1])
	{
		path[++(m->p_ind)] = i;
		path[++(m->p_ind)] = m->nb_rooms - 1;
		return (1);
	}
	return (0);
}

static void	erase_elem(t_map *m, int i)
{
	m->tab[m->curr_room][i] = 0;
	m->tab[i][m->curr_room] = 0;
}

static int	find_door(t_map *m, int r_index, int d_index)
{
	while (d_index < m->nb_rooms)
	{
		if (m->tab[r_index][d_index] == 1)
			return (d_index);
		d_index++;
	}
	return (0);
}



static int	is_in_path(int* path, int r_index)
{
	int i;
	
	i = -1;
	while (path[++i] != -1)
	{
		if (path[i] == r_index)
			return (1);
	}
	return (0);
};

int				ft_isuseful(t_map *m, int roomindex, int stepcount)
{
	if (m->bestpathperroom[roomindex] == -1 || stepcount < m->bestpathperroom[roomindex])
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

void            printtab(t_map* m, int *tab)
{
    int i;

    i = 0;
    while(i < m->nb_rooms && tab[i]>=0)
    {
        if(i > 0)
            printf(", %d", tab[i]);
        else
            printf("%d",tab[i]);
        i++;
    }
    printf("\n");
}

void			solve(t_map *m, int* path, int currentroomindex)
{
	int* pathnext;
	int i;
	int currentstepscount;

	i = 0;
	pathnext = NULL;
	currentstepscount = ft_sizetab(path);
	if (m->best_size > -1 && currentstepscount >= m->best_size)
		return;

	while(i < m->nb_rooms)
	{
		if(m->tab[currentroomindex][i] && ft_isnewroom(m, path, i) && ft_isuseful(m, i, currentstepscount))
		{
			// On arrive à la derniere room
			if(i == m->nb_rooms - 1)
			{
				path[currentstepscount++] = i;
                if (m->best_size == -1 || currentstepscount < m->best_size)
				{
				    m->best_size = currentstepscount;
					ft_copytabint(m, path, &(m->path));
					free(path);
				}
                return;
			}
			// Sinon
			else {
			    ft_copytabint(m, path, &pathnext);
                pathnext[currentstepscount] = i;
                solve(m, pathnext, i);
			}
		}
		i++;
	}

}