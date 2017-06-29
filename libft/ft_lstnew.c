/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:06:32 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/20 22:32:43 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*a;

	a = (t_list *)malloc(sizeof(*a));
	if (!a)
		return (NULL);
	if (content == NULL)
	{
		a->content_size = 0;
		a->content = NULL;
	}
	else
	{
		if ((a->content = malloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(a->content, content, content_size);
		a->content_size = content_size;
	}
	a->next = NULL;
	return (a);
}
