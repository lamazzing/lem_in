/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:39:16 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/04 14:15:43 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cast_length_unsigned(uintmax_t *n, t_beast *cr)
{
	if (cr->conv == 'O' || cr->conv == 'U')
	{
		*n = (unsigned long)*n;
		return (0);
	}
	if (cr->len[0] == 0 && cr->conv)
		*n = (unsigned int)*n;
	if (cr->len[0] == 'h')
	{
		*n = (unsigned short)*n;
		if (cr->len[1] == 'h')
			*n = (unsigned char)*n;
	}
	if (cr->len[0] == 'l' && cr->len[1] != 'l')
		*n = (unsigned long)*n;
	if (cr->len[0] == 'l' && cr->len[1] == 'l')
		*n = (unsigned long long)*n;
	if (cr->len[0] == 'z')
		*n = (size_t)*n;
	return (0);
}

int		ft_cast_length_signed(intmax_t *n, t_beast *cr)
{
	if (cr->conv == 'D')
	{
		*n = (signed long)*n;
		return (0);
	}
	if (cr->len[0] == 0)
		*n = (int)*n;
	if (cr->len[0] == 'h')
	{
		*n = (short)*n;
		if (cr->len[1] == 'h')
			*n = (char)*n;
	}
	if (cr->len[0] == 'l' && cr->len[1] != 'l')
		*n = (long)*n;
	if (cr->len[0] == 'l' && cr->len[1] == 'l')
		*n = (long long)*n;
	if (cr->len[0] == 'z')
		*n = (long int)*n;
	return (0);
}
