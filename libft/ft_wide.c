/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:56:00 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/04 14:17:04 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_wide3(t_beast *cr, char *a)
{
	if (cr->wc > 65535 && cr->wc < 2097152)
	{
		a = (char *)malloc(5);
		a[0] = ((cr->wc >> 18) | 0xF0);
		a[1] = (((cr->wc % 0x40000) >> 12) | 0x80);
		a[2] = (((cr->wc % 0x1000) >> 6) | 0x80);
		a[3] = ((cr->wc % 0x40) | 0x80);
		a[4] = '\0';
	}
	return (a);
}

static char	*ft_wide2(t_beast *cr, char *a)
{
	if (cr->wc >= 0 && cr->wc < 128)
	{
		a = (char *)malloc(2);
		a[0] = cr->wc;
		a[1] = '\0';
	}
	if (cr->wc > 127 && cr->wc < 2048)
	{
		a = (char *)malloc(3);
		a[0] = ((cr->wc >> 6) | 0xc0);
		a[1] = ((cr->wc % 64) | 0x80);
		a[2] = '\0';
	}
	if (cr->wc > 2047 && cr->wc < 65536)
	{
		a = (char *)malloc(4);
		a[0] = ((cr->wc >> 12) | 0xE0);
		a[1] = (((cr->wc % 4096) >> 6) | 0x80);
		a[2] = ((cr->wc % 0x40) | 0x80);
		a[3] = '\0';
	}
	return (a);
}

char		*ft_wide(t_beast *cr)
{
	char *a;

	a = 0;
	if (MB_CUR_MAX == 1)
	{
		if (cr->wc < 256 && (cr->cret = 1))
		{
			a = (char *)malloc(2);
			a[0] = cr->wc;
			a[1] = '\0';
		}
		if (cr->wc > 255)
		{
			a = (char *)malloc(1);
			a[0] = '\0';
			cr->ret = -1;
		}
	}
	if (MB_CUR_MAX == 4)
	{
		a = ft_wide2(cr, a);
		a = ft_wide3(cr, a);
	}
	return (a);
}

void		ft_wides(t_beast *cr)
{
	int		i;
	int		fi;
	char	*tmp;
	char	*tmpout;

	i = -1;
	fi = 0;
	while (cr->wout[++i] != 0)
	{
		cr->wc = cr->wout[i];
		if (fi == 1)
		{
			tmp = ft_wide(cr);
			tmpout = cr->out;
			cr->out = ft_strjoin(cr->out, tmp);
			free(tmp);
			free(tmpout);
			tmp = NULL;
			tmpout = NULL;
		}
		if (fi == 0 && (fi = 1))
			cr->out = ft_wide(cr);
		if (cr->ret == -1)
			return ;
	}
}
