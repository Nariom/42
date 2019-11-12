/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:00:02 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/18 17:23:02 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert(t_btree **t, void *c, size_t s, int (*cmp)(void *, void *))
{
	t_btree	*node;
	t_btree	*prev;

	if (*t)
	{
		node = *t;
		while (node)
		{
			prev = node;
			node = ((*cmp)(c, node->content) < 0) ? node->left : node->right;
		}
		if ((*cmp)(c, prev->content) < 0)
			prev->left = btree_create_node(c, s);
		else
			prev->right = btree_create_node(c, s);
	}
	else
		*t = btree_create_node(c, s);
}
