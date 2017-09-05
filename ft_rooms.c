/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 20:40:36 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/06 20:43:30 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Checking room names
*/
static int	ft_rightroom(t_ants *a, t_room *r, char **dup)
{
	size_t i;

	i = 0;
	if (ft_ptrlen(dup) == 3 && ft_isdigits(dup[1]) &&
			ft_isdigits(dup[2]) && ft_comment(a) == 0 && (a->end = -1)
			&& dup[0][0] != 'L' && (a->end = 1) &&
			(r[a->rooms].name = dup[0]))
	{
		r[a->rooms].x = dup[1];
		r[a->rooms].y = dup[2];
		a->rooms++;
		while (i < ft_strlen(dup[0]))
		{
			if (dup[0][i] == '-')
				a->end = -1;
			i++;
		}
	}
	return (1);
}

/*
** Parsing rooms, code 2 stands for start, 3 for end
*/
int			ft_rooms(t_ants *a, t_room *r)
{
	char	**dup;

	while (a->end == 1 && a->of >= 1)
	{
		a->of = get_next_line(0, &a->line);
		while (ft_comment(a) == 1)
			a->of = get_next_line(0, &a->line);
		if (a->of >= 1 && ft_comment(a) != 0 &&
				(r[a->rooms].ensta = (ft_comment(a) == 2) ? 2 : 3))
			a->of = get_next_line(0, &a->line);
		dup = (a->of >= 1) ? ft_whitespaces(a->line) : 0;
		if (dup && (ft_ptrlen(dup) != 3 || !ft_isdigits(dup[1]) ||
					!ft_isdigits(dup[2])) && ft_comment(a) != 1)
		{
			if (a->rooms == 0 || ft_comment(a) != 0 || (r[a->rooms].ensta &&
						r[a->rooms].name == NULL))
				a->end = -1;
			return (1);
		}
		ft_rightroom(a, r, dup);
	}
	return (1);
}

static int	ft_checkt(char *line)
{
	size_t	i;
	int		ko;

	i = 0;
	ko = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] == '-')
			ko++;
		i++;
	}
	if (ko == 1)
		return (0);
	else
		return (1);
}
/*
** Parsing links
*/
int			ft_links(t_ants *a, t_room *r)
{
	int		i;
	int		er;
	char	**dup;

	while (a->end == 1 && (i = -1))
	{
		while (a->of == 1 && ft_comment(a) != 0)
			a->of = get_next_line(0, &a->line);
		if (ft_checkt(a->line))
			return (1);
		dup = ft_strsplit(a->line, '-');
		if (ft_ptrlen(dup) != 2)
			return (1);
		if (ft_ptrlen(dup) == 2 && !(er = 0))
		{
			dup[0] = ft_strtrim(dup[0]);
			dup[1] = ft_strtrim(dup[1]);
			er = ft_apply_ants(a->rooms + 1, r, dup, 0);
			if (er != 2)
				return (1);
		}
		if ((a->of = get_next_line(0, &a->line)) != 1)
			return (1);
	}
	return (1);
}
