/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:17:49 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/01 19:17:56 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *, size_t))
{
	if (root)
	{
		(*applyf)(root->content, root->content_size);
		btree_apply_prefix(root->left, applyf);
		btree_apply_prefix(root->right, applyf);
	}
}
