/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:01:53 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/01 19:06:28 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_search(t_btree *t, void *c, int (*cmp)(void *, void*))
{
	if (!t)
		return (NULL);
	if ((*cmp)(c, t->content) == 0)
		return (t);
	if ((*cmp)(c, t->content) < 0)
		return (btree_search(t->left, c, cmp));
	else
		return (btree_search(t->right, c, cmp));
}
