/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bestpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 16:48:08 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/06 04:43:00 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** compute total length of each solution (if two paths the two lengths are added)
*/

static void	ft_countpath(t_ants *a, t_path *p, t_room *r)
{
	int i;
	int u;

	i = 0;
	u = 0;
	while (i < a->lastp)
	{
		while (u <= i)
		{
			p[i].nst += ft_ptrlen(p[i].fin[u]);
			p[i].fin[u][ft_ptrlen(p[i].fin[u])] = r[p[i].end].name;
			u++;
		}
		u = 0;
		i++;
	}
}

/*
** smallest number of turns (score) for a specific number of ants is the choosen solution
** # of turns = (total length of the paths + number of ants - (# of paths + 1)) / (# of paths + 1)
** add 1 turn in the division has a rest
*/
static int	ft_score(t_ants *a, t_path *p)
{
	int i;
	int u;

	i = 0;
	u = 0;
	while (i < a->lastp)
	{
		p[i].sco = (p[i].nst + a->numa - (i + 1)) / (i + 1);
		if ((p[i].nst + a->numa - (i + 1)) % (i + 1))
			p[i].sco++;
		i++;
	}
	i = 1;
	while ((u + i) < a->lastp)
	{
		if (p[u + i].sco < p[u].sco)
		{
			u = u + i;
			i = 0;
		}
		i++;
	}
	return (u);
}
/*
** Choose bestpath depending on number of ants in function ft_score
*/
int			ft_bestpath(t_ants *a, t_room *r, t_path *p)
{
	int i;
	int u;
	int e;

	i = 0;
	u = 0;
	ft_countpath(a, p, r);
	e = ft_score(a, p);
	a->numat = a->numa;
	ft_antgen(a, r, p, e);
	return (1);
}
