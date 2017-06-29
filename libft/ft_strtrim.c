/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:19:17 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/20 20:24:00 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		countend(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	char	*tab;
	int		start;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(1));
	tab = (char*)malloc(sizeof(char) * (countend(s) - i + 2));
	if (!tab)
		return (NULL);
	start = i;
	i = 0;
	while (start != countend(s))
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = s[start];
	tab[i + 1] = '\0';
	return (tab);
}
