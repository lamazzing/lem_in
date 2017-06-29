/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:36:11 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/16 23:48:16 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*out;

	len = 0;
	while (s1[len] != '\0')
		len++;
	len++;
	out = (char*)malloc(sizeof(*out) * len);
	if (out == NULL)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		out[len] = s1[len];
		len++;
	}
	out[len] = '\0';
	return (out);
}
