/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antgen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:59:55 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/06 05:07:34 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_seekroom(char *one, t_room *r)
{
	int n;

	n = 0;
	while (ft_strcmp(one, r[n].name))
		n++;
	return (n);
}

static int	ft_march(t_room *r, t_path *p, int n, int e)
{
	int s;

	if (p[e].first)
		ft_putstr(" ");
	s = n;
	ft_printf("L%d-%s", r[n].yes, p[e].fin[p[e].a][p[e].b + 1]);
	n = ft_seekroom(p[e].fin[p[e].a][p[e].b + 1], r);
	r[n].yes = r[s].yes;
	r[s].yes = 0;
	return (1);
}

static int	ft_antforward(t_room *r, t_path *p, int e, int numa)
{
	int n;

	p[e].a = e;
	p[e].b = 0;
	p[e].numa = numa;
	n = 0;
	while (p[e].a != -1)
	{
		p[e].star[p[e].a] = ft_ptrlen(p[e].fin[p[e].a]) - 1;
		p[e].b = p[e].star[p[e].a] - 1;
		while (p[e].b != 0)
		{
			n = ft_seekroom(p[e].fin[p[e].a][p[e].b], r);
			if (r[n].yes)
			{
				ft_march(r, p, n, e);
				p[e].first = 1;
			}
			p[e].b--;
		}
		p[e].a--;
	}
	return (1);
}

int			ft_antgen(t_ants *a, t_room *r, t_path *p, int e)
{
	int i;

	i = 0;
	while (i < p[e].sco)
	{
		p[e].first = 0;
		ft_antforward(r, p, e, a->numa);
		if (a->numa)
			ft_firestarter(a, r, p, e);
		ft_putstr("\n");
		i++;
	}
	return (1);
}
