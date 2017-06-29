/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:32:01 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/04 14:16:06 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	basecounter(int counter, uintmax_t nb, uintmax_t base)
{
	while (nb > (base - 1))
	{
		nb = (nb / base);
		counter++;
	}
	return (counter);
}

static int	negcounter(int counter, intmax_t nb, intmax_t base)
{
	while (nb > (base - 1))
	{
		nb = (nb / base);
		counter++;
	}
	return (counter);
}

char		*ft_itoa_base_unsigned(uintmax_t n, int base, t_beast *cr)
{
	int		size;
	char	*tab;

	size = 1;
	if (!n)
		cr->zero = 1;
	if (cr->len[0] != 'j' && cr->conv != 'p')
		ft_cast_length_unsigned(&n, cr);
	size = basecounter(size, n, base);
	tab = (char*)malloc(sizeof(char) * (size + 1));
	tab[size] = '\0';
	while (size != 0)
	{
		if ((n % base) < 10)
			tab[--size] = (n % base) + 48;
		if ((n % base) >= 10 && cr->conv != 'X')
			tab[--size] = (n % base) + 87;
		if ((n % base) >= 10 && cr->conv == 'X')
			tab[--size] = (n % base) + 55;
		n /= base;
	}
	return (tab);
}

intmax_t	ft_itoa_base_signed2(intmax_t n, t_beast *cr, int *lim, int *neg)
{
	if (cr->len[0] != 'j')
		ft_cast_length_signed(&n, cr);
	if (n == (-9223372036854775807 - 1) && n++)
		*lim = 1;
	if (n < 0 && (*neg = 1))
		n = n * -1;
	return (n);
}

char		*ft_itoa_base_signed(intmax_t n, int base, t_beast *cr)
{
	int		size;
	int		neg;
	int		lim;
	char	*tab;

	if (!n)
		cr->zero = 1;
	size = 1;
	neg = 0;
	lim = 0;
	base = (intmax_t)base;
	n = ft_itoa_base_signed2(n, cr, &lim, &neg);
	size = negcounter(size, n, base);
	tab = (char*)malloc(sizeof(char) * (size + 1 + neg));
	if (neg)
		tab[0] = '-';
	tab[size + neg] = '\0';
	while (size)
	{
		size--;
		tab[size + neg] = (n % base) + 48 + lim;
		lim = 0;
		n /= base;
	}
	return (tab);
}
