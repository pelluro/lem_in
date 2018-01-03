/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayresult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:53:58 by mipham            #+#    #+#             */
/*   Updated: 2018/01/03 15:54:00 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by pelluro on 31/12/17.
//
#include "../include/libft/libft.h"
#include "../include/lem_in.h"

static void	header(t_map *m)
{
	int i;
	
	i = -1;
	ft_putstr("\n\n");
	ft_putstr("\t   ");
	while (++i < m->q_rooms)
	{
		ft_putchar(' ');
		ft_putnbr((i > 9) ? (i % 10) : i);
	}
	ft_putstr("\n\n");
}

void		print_matrix(t_map *m)
{
	int i;
	int j;
	
	header(m);
	i = -1;
	while (++i < m->q_rooms)
	{
		ft_putchar('\t');
		ft_putnbr((i > 9) ? (i % 10) : i);
		ft_putstr("   ");
		j = -1;
		while (++j < m->q_rooms)
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

static void	print_ant(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

static void	print_result(t_map *m, int n)
{
	int ants;
	
	if (n == (m->p_ind + m->ants + 1))
		return ;
	ants = m->ants + 1;
	while (--ants > 0)
	{
		if (n - ants > 0 && (n - ants) <= m->p_ind)
			print_ant(ants, m->rooms[m->path[n - ants]]);
	}
	ft_putchar('\n');
	print_result(m, ++n);
}

void		result(t_map *m)
{
	int i;
	
	i = -1;
	ft_putendl(m->ants_str);
	ft_putendl(m->rooms_list);
	ft_putendl(m->links);
	ft_putchar('\n');
	while (++i <= m->p_ind)
	{
		ft_putchar('[');
		ft_putnbr(m->path[i]);
		ft_putchar(']');
		if (i != m->p_ind)
			ft_putchar('-');
	}
	ft_putstr("\n\n");
	print_result(m, 2);
}
