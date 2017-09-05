/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 04:20:24 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/06 21:02:59 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** reprint the links in order
*/
static int	ft_printlinks(t_ants *a, t_room *r)
{
	int u;
	int w;
	int i;

	i = 0;
	u = 0;
	w = 0;
	while (i < a->rooms)
	{
		while (u < r[i].nl)
		{
			while (ft_strcmp(r[i].lin[u], r[w].name))
				w++;
			if (w > i)
				ft_printf("%s-%s\n", r[i].name, r[i].lin[u]);
			w = 0;
			u++;
		}
		u = 0;
		i++;
	}
	return (0);
}
/*
** reprint the map of the anthill
*/
int			ft_printants(t_ants *a, t_room *r)
{
	int i;

	i = 0;
	ft_printf("%d\n", a->numa);
	while (i < a->rooms)
	{
		if (r[i].ensta == 2)
			ft_printf("##start\n");
		if (r[i].ensta == 3)
			ft_printf("##end\n");
		ft_printf("%s %s %s\n", r[i].name, r[i].x, r[i].y);
		i++;
	}
	i = 0;
	ft_printlinks(a, r);
	ft_printf("\n");
	return (0);
}
