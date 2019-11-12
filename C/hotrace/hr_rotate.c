/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 11:47:01 by jquilez           #+#    #+#             */
/*   Updated: 2013/12/15 19:27:43 by jquilez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void		btree_rotate_rr(t_btree **tree, t_btree *parent)
{
	t_btree		*node;
	t_btree		*child_node;

	node = *tree;
	child_node = node->right;
	node->right = child_node->left;
	child_node->left = node;
	if (!parent)
		*tree = child_node;
	else
	{
		if (parent->right == node)
			parent->right = child_node;
		else
			parent->left = child_node;
	}
	node->hgt = ft_max_hgt(node->left, node->right);
	child_node->hgt = ft_max_hgt(child_node->left, child_node->right);
}

static void		btree_rotate_ll(t_btree **tree, t_btree *parent)
{
	t_btree		*node;
	t_btree		*child_node;

	node = *tree;
	child_node = node->left;
	node->left = child_node->right;
	child_node->right = node;
	if (!parent)
		*tree = child_node;
	else
	{
		if (parent->right == node)
			parent->right = child_node;
		else
			parent->left = child_node;
	}
	node->hgt = ft_max_hgt(node->left, node->right);
	child_node->hgt = ft_max_hgt(child_node->left, child_node->right);
}

static void		btree_rotate_lr(t_btree **tree, t_btree *parent)
{
	t_btree		*node;
	t_btree		*child_node;
	t_btree		*child;

	node = *tree;
	child_node = node->left;
	child = child_node->right;
	node->left = child->right;
	child_node->right = child->left;
	child->left = child_node;
	child->right = node;
	if (!parent)
		*tree = child;
	else
	{
		if (parent->right == node)
			parent->right = child;
		else
			parent->left = child;
	}
	node->hgt = ft_max_hgt(node->left, node->right);
	child_node->hgt = ft_max_hgt(child_node->left, child_node->right);
	child->hgt = ft_max_hgt(child->left, child->right);
}

static void		btree_rotate_rl(t_btree **tree, t_btree *parent)
{
	t_btree		*node;
	t_btree		*child_node;
	t_btree		*child;

	node = *tree;
	child_node = node->right;
	child = child_node->left;
	child_node->left = child->right;
	node->right = child->left;
	child->right = child_node;
	child->left = node;
	if (!parent)
		*tree = child;
	else
	{
		if (parent->right == node)
			parent->right = child;
		else
			parent->left = child;
	}
	node->hgt = ft_max_hgt(node->left, node->right);
	child_node->hgt = ft_max_hgt(child_node->left, child_node->right);
	child->hgt = ft_max_hgt(child->left, child->right);
}

void			btree_rotate(t_btree **tree, t_btree *parent)
{
	int			i;

	i = ((*tree)->left) ? (*tree)->left->hgt + 1 : 0;
	i = ((*tree)->right) ? i - (*tree)->right->hgt - 1 : i;
	if (i > 0)
	{
		i = ((*tree)->left->left) ? (*tree)->left->left->hgt + 1 : 0;
		i = ((*tree)->left->right) ? i - (*tree)->left->right->hgt - 1 : i;
		if (i > 0)
			btree_rotate_ll(tree, parent);
		else
			btree_rotate_lr(tree, parent);
	}
	else
	{
		i = ((*tree)->right->left) ? (*tree)->right->left->hgt + 1 : 0;
		i = ((*tree)->right->right) ? i - (*tree)->right->right->hgt - 1 : i;
		if (i > 0)
			btree_rotate_rl(tree, parent);
		else
			btree_rotate_rr(tree, parent);
	}
}
