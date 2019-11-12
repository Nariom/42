/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 17:49:58 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/01 19:24:49 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_create_node(void const *content, size_t content_size)
{
	t_btree	*tree;

	tree = (t_btree *) malloc(sizeof(*tree));
	tree->content = (void *) malloc(content_size * sizeof(*(tree->content)));
	tree->content = ft_memcpy(tree->content, content, content_size);
	tree->content_size = content_size;
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}
