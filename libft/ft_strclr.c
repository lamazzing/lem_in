/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:51:07 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/20 19:06:09 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			s[i] = '\0';
			i++;
		}
	}
}
