/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:55:25 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/28 16:29:12 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list *begin_list, void const *content,
		size_t content_size)
{
	t_list *tmp;

	tmp = begin_list;
	if (tmp)
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = ft_lstnew(content, content_size);
	}
}
