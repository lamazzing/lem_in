/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 22:53:29 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/20 23:19:14 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_createint(int n, int counter, int lim, int neg)
{
	char	*tab;
	int		nb;
	int		mod;

	tab = (char*)malloc(sizeof(char) * (counter + lim + neg + 1));
	if (!tab)
		return (NULL);
	nb = n;
	tab[counter + lim + neg] = '\0';
	while (counter)
	{
		counter--;
		mod = (nb % 10);
		tab[counter + lim + neg] = (mod + 48);
		nb = (nb / 10);
	}
	if (lim)
		tab[counter + neg] = '2';
	if (neg)
		tab[counter] = '-';
	return (tab);
}

static int	fcounter(int counter, int nb)
{
	while (nb > 9)
	{
		nb = (nb / 10);
		counter++;
	}
	return (counter);
}

char		*ft_itoa(int n)
{
	int counter;
	int neg;
	int lim;

	lim = 0;
	neg = 0;
	counter = 1;
	if (n == -2147483648)
	{
		neg = 1;
		lim = 1;
		n = 147483648;
	}
	if (n < 0)
	{
		neg = 1;
		n = n * -1;
	}
	return (ft_createint(n, fcounter(counter, n), lim, neg));
}
