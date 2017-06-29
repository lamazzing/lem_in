/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 23:30:58 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/20 23:54:18 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;
	char	c1;

	c1 = (char)c;
	if (c == '\0')
	{
		s1 = (char*)s + ft_strlen(s);
		return (s1);
	}
	i = 0;
	if (s[i] == '\0')
		return (NULL);
	while (s[i] != c1 && s[i] != '\0')
	{
		i++;
		if (s[i] == '\0' && c1 != '\0')
			return (NULL);
	}
	s1 = (char*)s + i;
	return (s1);
}
