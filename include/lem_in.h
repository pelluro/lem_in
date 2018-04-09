/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:55:35 by mipham            #+#    #+#             */
/*   Updated: 2018/04/09 17:01:37 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct	s_room
{
	char	*name;
	int		x;
	int		y;
}				t_room;

typedef struct	s_map
{
	t_room		**roommap;
	char		**rooms;
	char		*rooms_list;
	char		*ants_str;
	char		*links;
	int			nb_rooms;
	int			ants;
	int			flag;
	int			*path;
	int			**tab;
	int			*bestpathperroom;
	int			best_size;
	int			good[2];
	int			init_2;
}				t_map;

void			count_ants(t_map *m, char *line);
void			rooms(t_map *m, char *line);
void			links(t_map *m, char *line);

void			add_rooms(t_map *m);
void			create_tab(t_map *m);
void			checkbestsize(t_map *m, int *path, int currentstepscount);
void			solve(t_map *m, int *path, int i);

void			nextprint_result(t_map *m, int nbants, int stepfirst, int lant);
void			print_result(t_map *m, int nbants, int stepfirst, int lant);

char			*join_str(char *s1, char *s2, int clean);
void			free_tab(char **array, t_map *m, int error);
int				room_index(t_map *m, char *room_name, int start);
int				ft_checkcoords(t_map *m, int roomindex);
void			print_ant(int ant, char *room);
int				is_empty(char *s);

void			result(t_map *m);
void			print_map(t_map *m);
void			ft_exit(t_map *m, int error);
int				ft_sizetab(int *tab);
void			ft_copytabint(t_map *m, int *from, int **to);
int				ft_isnewroom(t_map *m, int *path, int roomindex);
int				ft_isuseful(t_map *m, int roomindex, int stepcount);
void			ft_initpath(t_map *m, int **path);
void			ft_maprooms(t_map *m);
#endif
