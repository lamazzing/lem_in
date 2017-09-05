/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 04:59:22 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/06 21:42:10 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_set(t_ants *a)
{
	a->fi = 0;
	a->se = 0;
	a->th = 0;
	a->numa = 0;
	a->end = 1;
	a->of = 1;
	a->rooms = 0;
}

/*
** Parsing commands, in this case start-end
*/
int			ft_comment(t_ants *a)
{
	if (a->line[0] == '#' && a->line[1] != '#')
		return (1);
	if (a->line[0] == '#' && a->line[1] == '#')
	{
		if (!ft_strcmp(a->line, "##start"))
			return (2);
		if (!ft_strcmp(a->line, "##end"))
			return (3);
		return (1);
	}
	return (0);
}

/*
** Parsing number of ants
*/
static int	ft_num(t_ants *a)
{
	size_t	i;

	i = 0;
	a->of = get_next_line(0, &a->line);
	if (a->of < 1 && (a->end = -1))
		return (1);
	while (a->of == 1 && ft_comment(a) == 1)
		a->of = get_next_line(0, &a->line);
	while (a->line[i] == ' ' || a->line[i] == '\t')
		i++;
	if (ft_isdigit(a->line[i]))
	{
		while (ft_isdigit(a->line[i]))
			i++;
		a->numa = ft_natoi(a->line, 1);
		if (a->numa <= 0)
			a->end = -1;
	}
	while (a->line[i] == ' ' || a->line[i] == '\t')
		i++;
	if (i != ft_strlen(a->line) || a->numa == 0)
		a->end = -1;
	return (1);
}

/*
** Parsing the file by steps to avoid doing unecessary calculations
** and stop as soon as there's an error.
** ft_algo: algorithm for set of best paths
** ft_printants: prints anthill map
** ft_bestpath: chooses best path depending on the number of ants and prints the turns
*/

int			main(void)
{
	t_ants	a[1];
	t_room	r[SIZE];
	t_path	p[50];

	ft_set(a);
	if (a->fi == 0 && ft_num(a))
		a->fi = (a->end == 1) ? 1 : 0;
	if (a->end != -1 && a->fi == 1 && ft_rooms(a, r))
		a->se = (a->end == 1) ? 1 : 0;
	if (a->end != -1 && a->se == 1 && ft_links(a, r))
		a->th = (a->end == 1) ? 1 : 0;
	if (a->end == -1)
	{
		ft_printf("ERROR\n");
		return (-1);
	}
	if (a->th == 1)
	{
		if (ft_algo(a, r, p) == -1 && ft_printf("ERROR\n"))
			return (-1);
		ft_printants(a, r);
		ft_bestpath(a, r, p);
	}
	return (0);
}
