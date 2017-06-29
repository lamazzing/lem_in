/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 03:31:18 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/21 16:03:50 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *))
{
	t_btree *a;

	a = *root;
	if (!(*root))
		*root = btree_create_node(item);
	else
	{
		if (cmpf(a->item, item) > 0)
			btree_insert_data(&a->left, item, cmpf);
		else if (cmpf(a->item, item) <= 0)
			btree_insert_data(&a->right, item, cmpf);
	}
}
