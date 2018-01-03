/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:54:07 by mipham            #+#    #+#             */
/*   Updated: 2018/01/03 15:54:09 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by pelluro on 31/12/17.
//
#include "../include/libft/libft.h"
#include "../include/lem_in.h"

void	exit_func(t_map *m, int error)
{
	int i;
	
	free(m->links);
	free(m->ants_str);
	free(m->rooms_list);
	if (m->init_2)
	{
		free(m->path);
		free_array(m->rooms, m, 0);
		i = -1;
		while (++i < m->q_rooms)
			free(m->tab[i]);
		free(m->tab);
	}
	free(m);
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}

void	free_array(char **array, t_map *m, int error)
{
	int i;
	
	i = 0;
	while (array[i])
		(array[i]) ? free(array[i++]) : 0;
	free(array);
	if (error)
		exit_func(m, 1);
	array = NULL;
}

