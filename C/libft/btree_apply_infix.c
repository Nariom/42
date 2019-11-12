/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:07:20 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/18 17:21:51 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void *, size_t))
{
	if (root)
	{
		btree_apply_infix(root->left, applyf);
		(*applyf)(root->content, root->content_size);
		btree_apply_infix(root->right, applyf);
	}
}
