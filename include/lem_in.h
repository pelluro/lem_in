/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:55:35 by mipham            #+#    #+#             */
/*   Updated: 2018/03/23 13:41:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_room
{
    char*       name;
    int         x;
    int         y;
}               t_room;

typedef struct	s_map
{
    t_room      **roommap;      // array of rooms
	char		**rooms;		// array of room names
	char		*rooms_list;	// list of rooms that was passed at the beginning
	char		*ants_str;		// list of ants that was passed at the beginning
	char		*links;			// list of links that was passed at the beginning
	int			nb_rooms;		// quantity of rooms
	int			ants;			// quantity of ants
	int			flag;		// a part of validation
	int			*path;			// path
	int			**tab;			// edge table
	int 		*bestpathperroom;
	int			best_size;		// when path found, best path size found
	int			good[2];		// a part of validation
	int			init_2;			// a part of validation
}				t_map;

void			count_ants(t_map *m, char *line);
void			rooms(t_map *m, char *line);
void			links(t_map *m, char *line);

void			add_rooms(t_map *m);
void			create_tab(t_map *m);
void 			checkbestsize(t_map *m, int* path, int currentstepscount);
void			solve(t_map *m, int* path, int i);

void            nextprint_result(t_map *m, int nbants, int stepfirst, int lant);
void	        print_result(t_map *m, int nbants, int stepfirst, int lant);

char			*join_str(char *s1, char *s2, int clean);
void			free_tab(char **array, t_map *m, int error);
int				room_index(t_map *m, char *room_name, int start);
int             ft_checkcoords(t_map* m, int roomindex);
int				is_empty(char *s);
void			print_ant(int ant, char *room);

void			result(t_map *m);
void			print_map(t_map *m);
void			ft_exit(t_map *m, int error);
int             ft_sizetab(int* tab);
void            ft_copytabint(t_map *m, int* from, int** to);
int             ft_isnewroom(t_map *m, int* path, int roomindex);
int             ft_isuseful(t_map *m, int roomindex, int stepcount);
void            ft_initpath(t_map *m, int** path);
void            ft_maprooms(t_map *m);
#endif
