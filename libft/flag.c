/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:25:59 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/04 14:15:24 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		binary_flag(t_beast *cr, t_flag *fl)
{
	int		i;

	ft_set_and_free(fl, 1);
	i = 0;
	if (cr->conv == 'p')
		fl->ha = 1;
	while (cr->flag[i] != '\0')
	{
		if (cr->prec[0] == '.')
			fl->pr = 1;
		if (cr->flag[i] == '+')
			fl->pl = 1;
		if (cr->flag[i] == '-')
			fl->min = 1;
		if (cr->flag[i] == ' ')
			fl->sp = 1;
		if (cr->flag[i] == '0')
			fl->ze = 1;
		if (cr->flag[i] == '#')
			fl->ha = 1;
		i++;
	}
}

static void		ft_easyflags(t_flag *fl, t_beast *cr, char *tmp)
{
	if (fl->pl == 1 && (cr->conv == 'd' || cr->conv == 'i' ||
				cr->conv == 'D') && cr->out[0] != '-' && (tmp = cr->out)
			&& (cr->out = ft_strjoin("+", cr->out)))
		free(tmp);
	if (fl->sp == 1 && fl->pl == 0 && cr->out[0] != '-' &&
			(cr->conv == 'd' || cr->conv == 'i' || cr->conv == 'D'))
	{
		tmp = cr->out;
		cr->out = ft_strjoin(" ", cr->out);
		free(tmp);
	}
	if (fl->ha == 1 && (((cr->conv == 'o' || cr->conv == 'O') &&
		cr->out[0] != '0') || ((cr->conv == 'x' || cr->conv == 'X') &&
		!(cr->zero)) || cr->conv == 'p'))
	{
		tmp = cr->out;
		if (cr->conv == 'x' || cr->conv == 'p')
			cr->out = ft_strjoin("0x", cr->out);
		if (cr->conv == 'X')
			cr->out = ft_strjoin("0X", cr->out);
		if (cr->conv == 'o' || cr->conv == 'O')
			cr->out = ft_strjoin("0", cr->out);
		free(tmp);
	}
}

static size_t	ft_check_s(t_beast *cr, size_t i)
{
	if (cr->conv == 'S' && i)
	{
		while (0x80 == (cr->out[i] & 0xC0))
			i--;
	}
	return (i);
}

static void		ft_precision(size_t i, char *tmp, t_beast *cr, int prec)
{
	char *ptmp;

	if ((cr->conv == 's' || cr->conv == 'S') && (tmp = cr->out) &&
			((i = prec) != -1) &&
			(cr->out = ft_strlen(cr->out) > i ? ft_strsub(cr->out, 0,
			(i = ft_check_s(cr, i))) : ft_strdup(cr->out)))
		free(tmp);
	if (!(i = 0) && cr->out[0] == '-' && cr->conv != 's' && cr->conv != 'S')
		i = 1;
	if (cr->conv != 's' && cr->conv != 'S' && cr->conv != 'c' && cr->conv != 'C'
			&& cr->conv != '%' && (prec = prec - ft_strlen(cr->out + i)) > 0)
	{
		prec = prec + i;
		ptmp = malloc(prec + 1);
		ptmp[prec] = 0;
		while (--prec != -1)
			ptmp[prec] = 48;
		tmp = cr->out;
		cr->out = ft_strjoin(ptmp, cr->out + i);
		if (i)
			cr->out[0] = '-';
		free(tmp);
		free(ptmp);
	}
}

char			*flag(t_beast *cr)
{
	size_t	i;
	char	*tmp;
	int		prec;
	t_flag	fl[1];

	binary_flag(cr, fl);
	i = 0;
	prec = 0;
	tmp = NULL;
	if (cr->out == NULL && (cr->out = malloc(1)))
		cr->out[0] = cr->sent[cr->pos++];
	if (cr->prec[i++] == '.' && cr->zeroc != 1)
	{
		if (cr->zero == 1)
			cr->out[0] = '\0';
		while (cr->prec[i] == '0')
			i++;
		if (cr->prec[i] != '\0')
			prec = ft_atoi(cr->prec + i);
		ft_precision(i, tmp, cr, prec);
	}
	i = -1;
	ft_easyflags(fl, cr, tmp);
	ft_width(cr, fl);
	return (0);
}
