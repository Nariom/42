/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 17:33:39 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/16 17:50:05 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_lslst	*ft_lslst_new(char *p, struct stat *s, char *e, char *c)
{
	t_lslst	*list;

	list = (t_lslst *)malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->p = ft_strsub(p, 0, ft_strlen(p));
	if (!(list->p))
	{
		free(list);
		return (NULL);
	}
	list->s = s;
	list->e = e;
	list->c = c;
	list->u = NULL;
	list->g = NULL;
	list->next = NULL;
	return (list);
}

void	ft_lslst_addtop(t_lslst **list, t_lslst *new)
{
	if (list && new)
	{
		new->next = *list;
		*list = new;
	}
}

void	ft_lslst_del(t_lslst **list)
{
	t_lslst	*tmp;

	while (list && *list)
	{
		if ((*list)->c)
			ft_strdel(&((*list)->c));
		if ((*list)->p)
			ft_strdel(&((*list)->p));
		if ((*list)->s)
			free((*list)->s);
		if ((*list)->e)
			ft_strdel(&((*list)->e));
		if ((*list)->u)
			ft_strdel(&((*list)->u));
		if ((*list)->g)
			ft_strdel(&((*list)->g));
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	if (list)
		*list = NULL;
}

int		ft_lslst_merge(t_lslst **l1, t_lslst *l2, t_ls *parsed)
{
	t_lslst	*new;

	while (l1 && l2)
	{
		if (l2->p[0] != '.' || parsed->flag[2])
		{
			new = ft_lslst_new(l2->p, l2->s, l2->e, l2->c);
			if (!new)
				return (ft_ls_error(1));
			ft_ls_sort(l1, new, parsed);
		}
		l2 = l2->next;
	}
	return (0);
}
