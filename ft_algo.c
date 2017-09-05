/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 02:06:06 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/06 21:28:34 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Switching links
*/

static int	ft_switch(t_room *r, int l, int i)
{
	char *tmp;
	char *tmps;

	tmp = ft_strdup(r[i].lin[l]);
	tmps = ft_strdup(r[i].lin[l + 1]);
	free(r[i].lin[l + 1]);
	free(r[i].lin[l]);
	r[i].lin[l + 1] = tmp;
	r[i].lin[l] = tmps;
	return (1);
}

/*
** Links are reordered from shortest paths to longest
*/

static void	ft_orderlink(t_ants *a, t_room *r, int i, int l)
{
	int n;
	int ns;

	i = 0;
	l = 0;
	n = 0;
	ns = 0;
	while (i < a->rooms && !(l = 0))
	{
		while (r[i].nl > (l + 1) && r[i].nl > 1)
		{
			while (ft_strcmp(r[i].lin[l], r[n].name))
				n++;
			while (ft_strcmp(r[i].lin[l + 1], r[ns].name))
				ns++;
			if (r[ns].dis < r[n].dis && ft_switch(r, l, i))
				l = -1;
			n = 0;
			ns = 0;
			l++;
		}
		i++;
	}
}

/*
** Recursive function to determine minimum distance for each room by going to each link
** Only the minimum distance r[n].dis from start is recorded for each room
*/

static int	ft_back(t_ants *a, t_room *r, int i, int l)
{
	int n;

	n = 0;
	if (r[i].nl > l && r[i].ensta != 3)
	{
		while (ft_strcmp(r[i].lin[l], r[n].name))
			n++;
		if ((r[i].dis + 1) < r[n].dis)
		{
			r[n].dis = r[i].dis + 1;
			ft_back(a, r, n, 0);
		}
		if ((r[i].dis + 1) >= r[n].dis)
			ft_back(a, r, i, l + 1);
	}
	return (1);
}

/*
** Find start and end room and maximum number of unique paths (a->maxp)
** 2 stands for start, 3 stands for end
** i is equal to 1 if I check only for start, to 2 if I check for end, 3 if I check both
*/
static int	ft_checkensta(t_room *r, t_ants *a, int i, int f)
{
	if (i == 1 || i == 3)
	{
		while (r[f].ensta != 2 && f <= a->rooms)
			f++;
		if (r[f].ensta == 2 && (a->pts = r[f].nl))
			r[f].dis = 0;
		else
			return (-1);
		if (i == 3)
			f = 0;
	}
	if (i == 2 || i == 3)
	{
		while (r[f].ensta != 3 && f <= a->rooms)
			f++;
		if (r[f].ensta == 3 && (a->ptf = r[f].nl))
			a->maxp = (a->pts >= a->ptf) ? a->ptf : a->pts;
		else
			return (-1);
	}
	return (f);
}
/*
** Structure of the algorithm
** ft_back defines minimum distance for each room
** ft_orderlink reorders links between rooms
** ft_pathfinder finds fastest path
*/
int			ft_algo(t_ants *a, t_room *r, t_path *p)
{
	int i;
	int l;
	int end;

	i = 0;
	l = 0;
	end = 0;
	if (p)
		end = 0;
	if ((i = ft_checkensta(r, a, 3, 0)) == -1)
		return (-1);
	if (ft_checkensta(r, a, 2, i + 1) != -1)
		return (-1);
	i = ft_checkensta(r, a, 1, 0);
	if (ft_checkensta(r, a, 1, i + 1) != -1)
		return (-1);
	end = ft_back(a, r, i, l);
	ft_orderlink(a, r, i, l);
	i = ft_checkensta(r, a, 2, 0);
	if (r[i].dis == a->rooms + 1)
		return (-1);
	ft_pathfinder(a, r, p, i);
	return (0);
}
