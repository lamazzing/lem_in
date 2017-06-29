/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:30:52 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/20 23:15:58 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		size;
	char	*tab;

	i = 0;
	if (s && f)
	{
		size = ft_strlen((char*)s);
		tab = (char*)malloc(sizeof(char) * (size + 1));
		if (!tab)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			tab[i] = f(s[i]);
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
