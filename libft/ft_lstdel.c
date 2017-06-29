/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:37:11 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/20 20:33:37 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*nextl;

	if (*alst && del)
	{
		list = *alst;
		while (list)
		{
			nextl = list->next;
			del(list->content, list->content_size);
			free(list);
			list = nextl;
		}
		*alst = NULL;
	}
}
