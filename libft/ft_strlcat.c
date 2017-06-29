/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:03:53 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/18 02:05:30 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*s1;
	const char	*s2;
	size_t		n;
	size_t		leng;

	s1 = dst;
	s2 = src;
	n = size;
	while (n-- != 0 && *s1 != '\0')
		s1++;
	leng = s1 - dst;
	n = size - leng;
	if (n == 0)
		return (leng + ft_strlen(s2));
	while (*s2 != '\0')
	{
		if (n != 1)
		{
			*s1++ = *s2;
			n--;
		}
		s2++;
	}
	*s1 = '\0';
	return (leng + (s2 - src));
}
