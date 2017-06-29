/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_firestarter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 14:53:00 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/06 04:49:04 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_checkant(int numa, t_path *p, int i, int e)
{
	int f;

	f = p[e].star[i] - p[e].star[e];
	if (f >= numa)
		return (0);
	return (1);
}

int			ft_firestarter(t_ants *a, t_room *r, t_path *p, int e)
{
	int i;
	int n;

	i = e;
	while (i != -1 && !(n = 0))
	{
		if (i != e && ft_checkant(a->numa, p, i, e))
		{
			n = ft_seekroom(p[e].fin[i][1], r);
			r[n].yes = (a->numat - a->numa + 1);
			ft_printf(" L%d-%s", r[n].yes, p[e].fin[i][1]);
			a->numa--;
		}
		if (i == e)
		{
			if (p[e].first)
				ft_putstr(" ");
			n = ft_seekroom(p[e].fin[i][1], r);
			r[n].yes = (a->numat - a->numa + 1);
			ft_printf("L%d-%s", r[n].yes, p[e].fin[i][1]);
			a->numa--;
		}
		i--;
	}
	return (1);
}
