/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:54:37 by mipham            #+#    #+#             */
/*   Updated: 2018/01/11 14:02:43 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int             ft_sizetab(int* tab)
{
    int i;

    i = 0;
    while(tab[i]>=0)
    {
        i++;
    }
    return (i);
}

void            ft_copytabint(t_map* m, int* from, int** to)
{
    int i;

    (*to) = (int*)malloc(sizeof(int) * m->nb_rooms);
    i = 0;
    while(i < m->nb_rooms)
    {
        (*to)[i] = from[i];
        i++;
    }
}