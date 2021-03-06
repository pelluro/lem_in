/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayresult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:53:58 by mipham            #+#    #+#             */
/*   Updated: 2018/04/06 18:45:13 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void	ft_header(t_map *m)
{
	int i;

	i = -1;
	ft_putstr("\n");
	ft_putstr("\t   ");
	while (++i < m->nb_rooms)
	{
		ft_putchar(' ');
		ft_putnbr((i > 9) ? (i % 10) : i);
	}
	ft_putstr("\n\n");
}

void		print_map(t_map *m)
{
	int i;
	int j;

	ft_header(m);
	i = -1;
	while (++i < m->nb_rooms)
	{
		ft_putchar('\t');
		ft_putnbr((i > 9) ? (i % 10) : i);
		ft_putstr("   ");
		j = -1;
		while (++j < m->nb_rooms)
		{
			ft_putnbr(m->tab[i][j]);
			ft_putchar(' ');
		}
		ft_putstr("\t\t");
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("] -  ");
		ft_putendl(m->rooms[i]);
	}
	ft_putstr("\n\n");
}

void		print_ant(int ant, char *room)
{
	ft_putstr(C_CYAN);
	ft_putchar('L');
	ft_putstr(C_BLUE);
	ft_putnbr(ant);
	ft_putstr(C_NONE);
	ft_putchar('-');
	ft_putstr(C_MAGENTA);
	ft_putstr(room);
	ft_putstr(C_NONE);
	ft_putchar(' ');
}

void		result(t_map *m)
{
	int i;

	i = -1;
	ft_putendl(m->ants_str);
	ft_putendl(m->rooms_list);
	ft_putendl(m->links);
	ft_putchar('\n');
	while (++i < m->best_size)
	{
		if (i > 0)
			ft_putchar('-');
		ft_putchar('[');
		ft_putstr(m->rooms[m->path[i]]);
		ft_putchar(']');
	}
	ft_putstr("\n\n");
	print_result(m, 1, 1, 0);
}
