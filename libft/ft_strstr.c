/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 00:04:23 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/19 18:51:47 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		a;
	char	*stack;
	char	*need;

	stack = (char*)big;
	need = (char*)little;
	i = 0;
	a = 0;
	if (need[a] == '\0')
		return (stack);
	while (stack[i] != '\0')
	{
		while (stack[i + a] == need[a]
				&& stack[i + a] != '\0' && need[a] != '\0')
			a++;
		if (need[a] == '\0')
			return (stack + i);
		a = 0;
		i++;
	}
	return (NULL);
}
