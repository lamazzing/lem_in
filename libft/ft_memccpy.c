/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:00:18 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/18 05:49:15 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dst1;

	i = 0;
	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	while (n)
	{
		dst1[i] = src1[i];
		if (src1[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
