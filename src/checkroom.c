/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkroom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:53:41 by mipham            #+#    #+#             */
/*   Updated: 2018/01/11 12:43:37 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
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
				free_array(r, m, 1);
		}
	}
	else
		free_array(r, m, 1);
}

static void		validate_room(t_map *m, char *line)
{
	char **r;

	r = ft_strsplit(line, ' ');
	if (r[0][0] == 'L' || r[3] != NULL)
		free_array(r, m, 1);
	is_number(r, m, r[1]);
	is_number(r, m, r[2]);
	free_array(r, m, 0);
}

void			rooms(t_map *m, char *line)
{
	m->started = 2;
	m->rooms_list = join_str(m->rooms_list, line, 0);
	if (line[0] == '#')
		return ;
	validate_room(m, line);
	m->q_rooms++;
}


