/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitespaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:41:24 by lmazzi            #+#    #+#             */
/*   Updated: 2017/06/06 04:30:57 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**tab_implem(char const *s, char **tab, int i)
{
	int ireal;
	int tabi;

	tabi = 0;
	while (s[i] != '\0')
	{
		ireal = 0;
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		while (s[i + ireal] != ' ' && s[i + ireal] != '\t' &&
				s[i + ireal] != '\0')
			ireal++;
		tab[tabi] = (char*)malloc(sizeof(char) * (ireal + 1));
		if (!tab)
			return (NULL);
		tabi++;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
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

static char	**tab_creation(char const *s, char **tab, int countwo)
{
	int i;
	int tabi;
	int a;

	i = 0;
	tabi = 0;
	tab = tab_implem(s, tab, i);
	while (s[i] != '\0')
	{
		a = 0;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		{
			tab[tabi][a] = s[i];
			i++;
			a++;
			if (s[i] == ' ' || s[i] == '\t')
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

static int	word_counter(char const *s)
{
	int countwo;
	int i;

	i = 0;
	countwo = 0;
	while (s[i] != '\0')
	{
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		{
			countwo++;
			while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (countwo);
}

char		**ft_whitespaces(char const *s)
{
	int		countwo;
	char	**tab;

	if (s)
	{
		countwo = word_counter(s);
		tab = (char**)malloc(sizeof(char*) * (countwo + 1));
		if (!tab)
			return (NULL);
		if (countwo == 0)
		{
			*tab = NULL;
			return (tab);
		}
		return (tab_creation(s, tab, countwo));
	}
	return (NULL);
}
