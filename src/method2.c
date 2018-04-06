/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:54:37 by mipham            #+#    #+#             */
/*   Updated: 2018/04/06 19:13:07 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		is_empty(char *s)
{
	size_t i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

int		ft_sizetab(int *tab)
{
	int i;

	i = 0;
	while (tab[i] >= 0)
	{
		i++;
	}
	return (i);
}

void	ft_copytabint(t_map *m, int *from, int **to)
{
	int i;

	(*to) = (int*)malloc(sizeof(int) * m->nb_rooms);
	i = 0;
	while (i < m->nb_rooms)
	{
		(*to)[i] = from[i];
		i++;
	}
}

void	nextprint_result(t_map *m, int nbants, int stepfirst, int lant)
{
	if (stepfirst < m->best_size - 1)
		stepfirst++;
	if (stepfirst == m->best_size - 1)
		lant++;
	if (lant > m->ants)
		return ;
	if (nbants < m->ants)
		print_result(m, nbants + 1, stepfirst, lant);
	else
		print_result(m, nbants, stepfirst, lant);
}

void	print_result(t_map *m, int nbants, int stepfirst, int lant)
{
	int i;
	int step;
	int f;

	i = 0;
	f = 1;
	step = stepfirst;
	while (++i <= nbants)
	{
		if (i >= lant)
		{
			if (f)
				f = 0;
			else
			{
				ft_putstr(" ");
				step--;
			}
			print_ant(i, m->rooms[m->path[step]]);
		}
	}
	ft_putchar('\n');
	nextprint_result(m, nbants, stepfirst, lant);
}
