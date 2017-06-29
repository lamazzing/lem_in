/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:34:34 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/05 19:42:16 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**tab_implem(char const *s, char **tab, char c, int i)
{
	int ireal;
	int tabi;

	tabi = 0;
	while (s[i] != '\0')
	{
		ireal = 0;
		while (s[i] == c)
			i++;
		while (s[i + ireal] != c && s[i + ireal] != '\0')
			ireal++;
		tab[tabi] = (char*)malloc(sizeof(char) * (ireal + 1));
		if (!tab)
			return (NULL);
		tabi++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (tab);
}

static char	**ft_finaltab(char **tab, int tabi, int countwo)
{
	if (tabi == countwo)
	{
		tab[tabi] = NULL;
		return (tab);
	}
	else if ((tabi + 1) == countwo)
	{
		tab[++tabi] = NULL;
		return (tab);
	}
	return (tab);
}

static char	**tab_creation(char const *s, char **tab, char c, int countwo)
{
	int i;
	int tabi;
	int a;

	i = 0;
	tabi = 0;
	tab = tab_implem(s, tab, c, i);
	while (s[i] != '\0')
	{
		a = 0;
		while (s[i] != c && s[i] != '\0')
		{
			tab[tabi][a] = s[i];
			i++;
			a++;
			if (s[i] == c)
			{
				tab[tabi][a] = '\0';
				tabi++;
			}
		}
		if (s[i] != '\0')
			i++;
	}
	return (ft_finaltab(tab, tabi, countwo));
}

static int	word_counter(char const *s, char c)
{
	int countwo;
	int i;

	i = 0;
	countwo = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			countwo++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (countwo);
}

char		**ft_strsplit(char const *s, char c)
{
	int		countwo;
	char	**tab;

	if (s)
	{
		countwo = word_counter(s, c);
		tab = (char**)malloc(sizeof(char*) * (countwo + 1));
		if (!tab)
			return (NULL);
		if (countwo == 0)
		{
			*tab = NULL;
			return (tab);
		}
		return (tab_creation(s, tab, c, countwo));
	}
	return (NULL);
}
