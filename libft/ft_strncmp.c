/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 01:43:07 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/19 18:08:14 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	if (n == 0)
		return (0);
	i = 0;
	while (((unsigned char)s1[i] != '\0') &&
			((unsigned char)s1[i] == (unsigned char)s2[i]) && (n - 1) != 0)
	{
		s1 = s1 + 1;
		s2 = s2 + 1;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
