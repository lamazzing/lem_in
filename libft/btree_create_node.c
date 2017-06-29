/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 01:16:06 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/21 15:52:47 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *a;

	a = (t_btree *)malloc(sizeof(t_btree));
	if (!a)
		return (NULL);
	a->item = item;
	a->left = 0;
	a->right = 0;
	return (a);
}
