/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crop_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 13:40:16 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/04 14:16:34 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_crop3(char *def, t_beast *cr, int i)
{
	if ((def[i] == 'i' || def[i] == 'd' || def[i] == 's' || def[i] == 'S' ||
				def[i] == 'D' || def[i] == 'p' || def[i] == 'o' ||
				def[i] == 'O' || def[i] == 'u' || def[i] == 'U' ||
				def[i] == 'x' || def[i] == 'X' || def[i] == 'c' ||
				def[i] == 'C') && (cr->conv = def[i]))
		i++;
	cr->pos = cr->pos + i;
}

static void	ft_crop2(char *def, t_beast *cr, int i, int a)
{
	if ((cr->prec = (char*)malloc(a + 1)) &&
			!(cr->prec[a + 1] = 0) && (a))
		cr->prec = ft_strncpy(cr->prec, &def[i], a);
	i += a;
	if (!(a = 0) && (def[i] == 'h' || def[i] == 'l' ||
				def[i] == 'j' || def[i] == 'z'))
		a++;
	if ((def[i] == 'h' && def[i + 1] == 'h') ||
			(def[i] == 'l' && def[i + 1] == 'l'))
		a++;
	cr->len = (char*)malloc(a + 1);
	cr->len[a + 1] = 0;
	if (a)
		cr->len = ft_strncpy(cr->len, &def[i], a);
	i += a;
	if (def[i] == '%')
	{
		cr->conv = '%';
		cr->out = malloc(2);
		cr->out[0] = '%';
		cr->out[1] = 0;
		i++;
	}
	ft_crop3(def, cr, i);
}

void		ft_crop(char *def, t_beast *cr)
{
	int i;
	int a;

	i = 0;
	a = 0;
	cr->conv = 0;
	cr->zero = 0;
	cr->zeroc = 0;
	cr->null = 0;
	while (def[i] == '#' || def[i] == '0' || def[i] == '-' || def[i] == '+' ||
			def[i] == ' ')
		i++;
	cr->flag = (char*)malloc(i + 1);
	if (!(cr->flag[i] = 0) && i)
		cr->flag = ft_strncpy(cr->flag, def, i);
	while (def[i + a] >= '0' && def[i + a] <= '9')
		a++;
	if ((cr->wid = (char*)malloc(a + 1)) &&
			!(cr->wid[a + 1] = 0) && (a))
		cr->wid = ft_strncpy(cr->wid, &def[i], a);
	i += a;
	if (!(a = 0) && def[i] == '.')
		while ((def[i + a] >= '0' && def[i + a] <= '9') || def[i + a] == '.')
			a++;
	ft_crop2(def, cr, i, a);
}
