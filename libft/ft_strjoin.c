/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:36:47 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/30 23:03:52 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	l;
	char			*tab;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	tab = (char*)malloc(sizeof(char) * (l + 1));
	if (!tab)
		return (NULL);
	i = 0;
	a = 0;
	while (s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		tab[i + a] = s2[a];
		a++;
	}
	tab[i + a] = '\0';
	return (tab);
}
