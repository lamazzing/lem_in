/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:51:10 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/20 23:15:31 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*tab;
	size_t			size;

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
			tab[i] = f(i, s[i]);
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
