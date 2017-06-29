/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:23:03 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/20 23:58:23 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*tab;

	if (s)
	{
		tab = (char*)malloc(sizeof(char) * (len + 1));
		if (!tab)
			return (NULL);
		i = 0;
		while (len)
		{
			tab[i] = s[start];
			i++;
			start++;
			len--;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
