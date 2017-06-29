/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 05:02:11 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/06 05:06:52 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define SIZE 5000
# include "libft.h"

typedef struct	s_ants
{
	int			fi;
	int			of;
	int			se;
	int			th;
	int			end;
	int			numa;
	int			numat;
	int			rooms;
	char		*line;
	int			pts;
	int			ptf;
	int			maxp;
	int			lastp;
}				t_ants;

typedef struct	s_room
{
	char		*name;
	char		*x;
	char		*y;
	int			ensta;
	char		*lin[100];
	int			nl;
	int			path;
	int			dis;
	int			yes;
	int			end;
	int			start;
}				t_room;

typedef struct	s_path
{
	char		***fin;
	int			nst;
	int			star[50];
	int			sco;
	int			a;
	int			b;
	int			max;
	int			first;
	int			ok;
	int			end;
	int			numa;
}				t_path;

int				ft_comment(t_ants *a);
int				ft_rooms(t_ants *a, t_room *r);
int				ft_links(t_ants *a, t_room *r);
int				ft_apply_ants(int nur, t_room *r, char **dup, int i);
int				ft_algo(t_ants *a, t_room *r, t_path *p);
int				ft_pathfinder(t_ants *a, t_room *r, t_path *p, int i);
char			***ft_createtab(t_ants *a, int po);
int				ft_bestpath(t_ants *a, t_room *r, t_path *p);
int				ft_antgen(t_ants *a, t_room *r, t_path *p, int e);
int				ft_firestarter(t_ants *a, t_room *r, t_path *p, int e);
int				ft_seekroom(char *one, t_room *r);
int				ft_printants(t_ants *a, t_room *r);
#endif
