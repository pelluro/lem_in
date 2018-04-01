/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:54:37 by mipham            #+#    #+#             */
/*   Updated: 2018/01/11 14:02:43 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

char	*join_str(char *s1, char *s2, int clean)
{
	char *new_s;

	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1[0] == 0)
	{
		free(new_s);
		free(s1);
		return (ft_strdup(s2));
	}
	ft_strcat(new_s, s1);
	ft_strcat(new_s, "\n");
	ft_strcat(new_s, s2);
	ft_strdel(&s1);
	(clean) ? ft_strdel(&s2) : 0;
	return (new_s);
}

//links that was passed on arguments
void	links(t_map *m, char *line)
{
	if (m->flag == 2)
		m->flag = 3;
	if (m->flag != 3)
		ft_exit(m, 1);
	m->links = join_str(m->links, line, 0);
}

int		room_index(t_map *m, char *room_name, int start)
{
	int index;

	index = (start) ? -1 : 0;
	while (m->rooms[++index] && index < m->nb_rooms)
	{
		if (ft_strcmp(m->rooms[index], room_name) == 0)
			return (index);
	}
	return (index);
}

void	count_ants(t_map *m, char *line)
{
	int		i;
	char	*s;

	i = 0;
	m->flag = 1;
	m->ants_str = join_str(m->ants_str, line, 0);
	if (line[0] == '#')
		return ;
	s = ft_strtrim(line);
	if ((m->ants = ft_atoi(s)) <= 0)
		ft_exit(m, 1);
	while (s[i] != '\n' && s[i] != 0)
	{
		if (!ft_isdigit(s[i]))
			ft_exit(m, 1);
		i++;
	}
	free(s);
}

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
