/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 04:24:46 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/06 19:49:27 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_double(t_room *r, int i, char *link)
{
	int f;

	f = 0;
	while (f < r[i].nl)
	{
		if (!ft_strcmp(link, r[i].lin[f]))
			return (1);
		f++;
	}
	return (0);
}

static int	ft_apply_second(int nur, t_room *r, char **dup, int i)
{
	r[i].lin[r[i].nl] = dup[0];
	r[i].dis = nur;
	r[i].yes = 0;
	r[i].nl++;
	return (1);
}

static int	ft_apply_first(int nur, t_room *r, char **dup, int i)
{
	r[i].lin[r[i].nl] = dup[1];
	r[i].dis = nur;
	r[i].yes = 0;
	r[i].nl++;
	return (1);
}

int			ft_apply_ants(int nur, t_room *r, char **dup, int i)
{
	int	er;
	int one;
	int two;
	int du;

	one = -1;
	two = -1;
	er = 0;
	du = 0;
	while (i < (nur - 1))
	{
		if (!ft_strcmp(dup[0], r[i].name) && !(du += ft_double(r, i, dup[1]))
				&& ++er)
			one = i;
		if (!ft_strcmp(dup[1], r[i].name) && !(du += ft_double(r, i, dup[0]))
				&& ++er)
			two = i;
		i++;
	}
	du = (!ft_strcmp(dup[1], dup[0])) ? 100 : du;
	if (er == 2 && one >= 0 && two >= 0 && ft_apply_first(nur, r, dup, one)
			&& ft_apply_second(nur, r, dup, two))
		return (er);
	return (du);
}
