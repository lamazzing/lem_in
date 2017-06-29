/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_natoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 02:08:33 by lmazzi            #+#    #+#             */
/*   Updated: 2017/05/11 19:43:57 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_natoi(char *str, int num)
{
	int		a;
	int		i;
	int		er;
	char	*tmp;

	i = 0;
	a = 0;
	er = ft_strlen(str);
	while (num--)
	{
		a = i + a;
		i = 0;
		while (!ft_isdigit(str[a]))
		{
			if (a > er)
				break ;
			a++;
		}
		while (ft_isdigit(str[a + i]))
			i++;
	}
	tmp = ft_strsub(str, a, i);
	a = ft_atoi(tmp);
	free(tmp);
	return (a);
}
