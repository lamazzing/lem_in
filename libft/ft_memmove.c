/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:48:53 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/21 04:44:42 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst1;
	char	*src1;

	dst1 = (char*)dst;
	src1 = (char*)src;
	i = 0;
	if (src > dst)
	{
		while (i < len)
		{
			*(dst1 + i) = *(src1 + i);
			i++;
		}
	}
	else if (src < dst)
	{
		while ((int)--len >= 0)
			*(dst1 + len) = *(src1 + len);
	}
	return (dst);
}
