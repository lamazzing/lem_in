/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_path_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 04:50:06 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/06 04:55:00 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
** creation of tab to save the different paths solutions
*/
char	***ft_createtab(t_ants *a, int po)
{
	char	***dup;
	int		i;
	int		u;

	i = 0;
	u = 0;
	dup = malloc(sizeof(char**) * (po + 2));
	while (u <= (po + 1))
	{
		dup[u] = 0;
		u++;
	}
	u = 0;
	while (i <= po)
	{
		dup[i] = malloc(sizeof(char*) * (a->rooms + 1));
		while (u <= a->rooms)
		{
			dup[i][u] = 0;
			u++;
		}
		i++;
	}
	return (dup);
}
