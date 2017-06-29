/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 11:43:53 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/04 14:15:00 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_converter2(va_list argn, t_beast *cr)
{
	if (cr->conv == 'c' && cr->len[0] != 'l')
	{
		cr->out = malloc(2);
		cr->out[0] = va_arg(argn, int);
		if (!(cr->out[1] = 0) && cr->out[0] == 0)
			cr->zeroc = 1;
	}
	if ((cr->conv == 's' && cr->len[0] == 'l') || cr->conv == 'S')
	{
		cr->wout = va_arg(argn, wchar_t*);
		if (cr->wout == NULL && (cr->out = "(null)"))
		{
			cr->null = 1;
			cr->out = ft_strdup(cr->out);
		}
		if (cr->null == 0)
			ft_wides(cr);
	}
	if ((cr->conv == 'c' && cr->len[0] == 'l') || cr->conv == 'C')
	{
		cr->wc = va_arg(argn, wchar_t);
		if (cr->wc == 0)
			cr->zeroc = 1;
		cr->out = ft_wide(cr);
	}
}

static void	ft_converter(va_list argn, t_beast *cr)
{
	if (cr->conv == 'i' || cr->conv == 'd' || cr->conv == 'D')
		cr->out = ft_itoa_base_signed(va_arg(argn, intmax_t), 10, cr);
	if (cr->conv == 'o' || cr->conv == 'O')
		cr->out = ft_itoa_base_unsigned(va_arg(argn, uintmax_t), 8, cr);
	if (cr->conv == 'u' || cr->conv == 'U')
		cr->out = ft_itoa_base_unsigned(va_arg(argn, uintmax_t), 10, cr);
	if (cr->conv == 'x' || cr->conv == 'X')
		cr->out = ft_itoa_base_unsigned(va_arg(argn, uintmax_t), 16, cr);
	if (cr->conv == 's' && cr->len[0] != 'l')
	{
		cr->out = va_arg(argn, char*);
		if (cr->out == NULL && (cr->out = "(null)"))
			cr->null = 1;
		cr->out = ft_strdup(cr->out);
	}
	if (cr->conv == 'p')
		cr->out = ft_itoa_base_unsigned(va_arg(argn, uintmax_t), 16, cr);
	ft_converter2(argn, cr);
}

static int	ft_free(t_beast *cr)
{
	free(cr->flag);
	free(cr->wid);
	free(cr->prec);
	free(cr->len);
	cr->flag = NULL;
	cr->wid = NULL;
	cr->prec = NULL;
	cr->len = NULL;
	if (cr->out)
	{
		free(cr->out);
		cr->out = NULL;
	}
	return (1);
}

static int	ft_output(t_beast *cr, int i, char *in, va_list argn)
{
	ft_crop(&in[cr->pos], cr);
	if (cr->conv)
		ft_converter(argn, cr);
	if (cr->ret == -1)
	{
		ft_free(cr);
		return (cr->ret);
	}
	if (cr->out || ft_isdigit(cr->wid[0]))
	{
		flag(cr);
		ft_putstr(cr->out);
		if (cr->zeroc && (i = i + 1))
			write(1, "\0", 1);
		i += ft_strlen(cr->out);
	}
	ft_free(cr);
	return (i);
}

int			ft_printf(char *in, ...)
{
	va_list	argn;
	t_beast	cr[1];
	int		i;

	va_start(argn, in);
	cr->pos = 0;
	cr->sent = in;
	i = 0;
	cr->out = NULL;
	cr->ret = 0;
	while (in[cr->pos] != '\0')
	{
		while (in[cr->pos] != '%' && in[cr->pos] != '\0' && ++cr->ret)
			write(1, &in[cr->pos++], 1);
		if (in[cr->pos] == '%' && (cr->pos = cr->pos + 1))
		{
			i = ft_output(cr, i, in, argn);
			if (cr->ret == -1)
				return (cr->ret);
		}
	}
	va_end(argn);
	return (cr->ret + i);
}
