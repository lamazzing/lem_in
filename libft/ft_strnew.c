/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:37:58 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/20 23:56:25 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*tab;

	tab = (char*)malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = '\0';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
