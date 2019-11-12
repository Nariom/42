/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_btree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 20:13:29 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/15 19:23:58 by jquilez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static t_btree	*btree_create(char *key, char *val)
{
	t_btree		*tree;

	tree = (t_btree *) malloc(sizeof(*tree));
	if (!tree || !key)
		return (NULL);
	tree->key = ft_strnew(ft_strlen(key));
	if (!tree->key)
		return (NULL);
	tree->key = ft_strcpy(tree->key, key);
	if (val)
	{
		tree->val = ft_strnew(ft_strlen(val));
		if (!tree->val)
			return (NULL);
		tree->val = ft_strcpy(tree->val, val);
	}
	else
		tree->val = NULL;
	tree->hgt = 0;
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}

int				ft_max_hgt(t_btree *left, t_btree *right)
{
	if (left && (!right || left->hgt >= right->hgt))
		return (left->hgt + 1);
	if (right)
		return (right->hgt + 1);
	return (0);
}

void			btree_ins(t_btree **tree, t_btree *parent, char *key, char *val)
{
	int			dif;

	if (*tree)
	{
		if (ft_strcmp(key, (*tree)->key) > 0)
			btree_ins(&((*tree)->right), *tree, key, val);
		if (ft_strcmp(key, (*tree)->key) < 0)
			btree_ins(&((*tree)->left), *tree, key, val);
		(*tree)->hgt = ft_max_hgt((*tree)->left, (*tree)->right);
		if (ft_strcmp(key, (*tree)->key) == 0)
		{
			ft_putstr("hotrace: ");
			ft_putstr(key);
			ft_putendl(": key already defined");
		}
		dif = ((*tree)->left) ? (*tree)->left->hgt + 1 : 0;
		dif = ((*tree)->right) ? dif - (*tree)->right->hgt - 1 : dif;
		if (dif == 2 || dif == -2)
			btree_rotate(tree, parent);
	}
	else
		*tree = btree_create(key, val);
}

char			*btree_search(t_btree *t, char *key)
{
	if (!t)
		return (NULL);
	if (ft_strcmp(key, t->key) == 0)
		return (t->val);
	if (ft_strcmp(key, t->key) < 0)
		return (btree_search(t->left, key));
	return (btree_search(t->right, key));
}
