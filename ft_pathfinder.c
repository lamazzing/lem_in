/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 05:22:38 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/06 21:29:18 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_endpath(int po, t_room *r, t_path *p, int n)
{
	p[po].a = (r[n].ensta == 3) ? p[po].a + 1 : p[po].a;
	p[po].b = (r[n].ensta == 3) ? 0 : (p[po].b + 1);
	return (1);
}

static int	ft_littlepath(int po, t_room *r, t_path *p, int i)
{
	if (r[i].ensta == 2 && ++p[po].max)
		i = p[po].end;
	r[i].path = (r[i].ensta == 3 || r[i].ensta == 2) ? 0 : 1;
	return (i);
}

static int	ft_everypath(int po, t_room *r, t_path *p, int i)
{
	int n;
	int l;

	l = 0;
	n = 0;
	if (r[i].ensta == 2 && po == p[po].max)
		return (1);
	i = ft_littlepath(po, r, p, i);
	while (r[i].nl > l)
	{
		while (ft_strcmp(r[i].lin[l], r[n].name))
			n++;
		if (r[n].path != 1 && r[n].ensta != 3 && ft_everypath(po, r, p, n) == 1
				&& (p[po].fin[p[po].a][p[po].b] = r[n].name) &&
				ft_endpath(po, r, p, i))
			return (1);
		if (r[n].ensta == 2)
			--p[po].max;
		l++;
		n = 0;
	}
	r[i].path = 0;
	return (0);
}

static int	ft_whitepath(t_ants *a, t_room *r)
{
	int i;

	i = 0;
	while (i < a->rooms)
	{
		r[i].path = 0;
		i++;
	}
	return (1);
}

int			ft_pathfinder(t_ants *a, t_room *r, t_path *p, int i)
{
	int	l;
	int	po;

	l = 0;
	po = 0;
	while (po < a->maxp)
	{
		p[po].a = 0;
		p[po].b = 0;
		p[po].max = 0;
		p[po].end = i;
		p[po].fin = ft_createtab(a, po);
		if (ft_everypath(po, r, p, i) != 1)
		{
			a->lastp = po;
			return (1);
		}
		ft_whitepath(a, r);
		po++;
	}
	a->lastp = po;
	return (1);
}
