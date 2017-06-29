/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 00:02:00 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/19 19:11:14 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;
	char	*stack;
	char	*need;

	stack = (char*)haystack;
	need = (char*)needle;
	i = 0;
	a = 0;
	if (need[a] == '\0')
		return (stack);
	while (stack[i] != '\0' && i < len)
	{
		while (stack[i + a] == need[a]
				&& stack[i + a] != '\0' && need[a] != '\0' && (i + a) < len)
			a++;
		if (need[a] == '\0')
			return (stack + i);
		i++;
		a = 0;
	}
	return (NULL);
}
