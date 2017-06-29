/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:01:42 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/04 14:16:48 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_set_and_free(t_flag *fl, int a)
{
	if (a == 1)
	{
		fl->pl = 0;
		fl->min = 0;
		fl->sp = 0;
		fl->ze = 0;
		fl->ha = 0;
		fl->pr = 0;
	}
}

static void	ft_widthmin(t_beast *cr, t_flag *fl, char *wtmp)
{
	char *tmp;

	if (fl->min == 1 && (tmp = cr->out))
	{
		cr->out = ft_strjoin(cr->out, wtmp);
		free(tmp);
		tmp = NULL;
	}
	if (fl->min == 0)
	{
		if (fl->ze == 1 && fl->pr == 0 && (cr->out[0] == '-' ||
					cr->out[0] == '+' || fl->ha == 1 || fl->sp == 1))
		{
			wtmp[0] = cr->out[0];
			if (fl->ha == 1 && (cr->conv == 'x' || cr->conv == 'X' ||
						cr->conv == 'p') && (wtmp[1] = cr->out[1]))
				cr->out[1] = 48;
			cr->out[0] = 48;
		}
		tmp = cr->out;
		cr->out = ft_strjoin(wtmp, cr->out);
		free(tmp);
	}
	free(wtmp);
}

void		ft_width(t_beast *cr, t_flag *fl)
{
	int		wi;
	int		i;
	char	*wtmp;

	i = 0;
	wi = 0;
	wi = ft_atoi(cr->wid);
	if ((wi = ((wi - cr->zeroc) - (ft_strlen(cr->out)))) > 0)
	{
		wtmp = (malloc(wi + 1));
		wtmp[wi] = 0;
		if (fl->ze == 0 || (fl->pr == 1 && cr->conv != 'c' && cr->conv != 'S'
					&& cr->conv != 's' && cr->conv != '%' && cr->conv != 0)
				|| fl->min == 1)
			while (--wi != -1)
				wtmp[wi] = ' ';
		if (fl->ze == 1 && (fl->pr == 0 || cr->conv == 'c' || cr->conv == 's'
					|| cr->conv == 'S' || cr->conv == '%' || cr->conv == 0) &&
				fl->min == 0)
			while (--wi != -1)
				wtmp[wi] = 48;
		ft_widthmin(cr, fl, wtmp);
	}
}
