/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 16:11:44 by rbaudot           #+#    #+#             */
/*   Updated: 2014/02/07 18:37:48 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

t_lst	*ft_new(char *s)
{
	t_lst	*lst;

	lst = (t_lst *) malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->s = ft_strdup(s);
	if (!(lst->s))
	{
		free(lst);
		return (NULL);
	}
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

void	ft_add(t_lst **lst, t_lst *new)
{
	if (lst && *lst && new)
	{
		(*lst)->prev = new;
		new->next = *lst;
	}
	if (lst && new)
		*lst = new;
}

void	ft_del(t_lst **lst)
{
	t_lst	*tmp;

	while (lst && *lst)
	{
		ft_strdel(&(*lst)->s);
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	if (lst)
		*lst = NULL;
}

void	ft_histdown(int *i, t_lst **l, char **s, char **r)
{
	t_lst	*t;
	int		j;

	ft_strdel(s);
	if (i[4] == 1)
		*s = ft_strdup(*r);
	else
	{
		t = *l;
		j = 0;
		while (++j < i[4] - 1)
			t = t->next;
		*s = ft_strdup(t->s);
	}
	tputs(tgetstr("dl", NULL), 1, ft_outc);
	ft_move(i, 0);
	ft_putstr("$> ");
	ft_putstr(*s);
	i[0] = ft_strlen(*s) + 3;
	i[1] = i[0];
	i[4]--;
}

void	ft_histup(int *i, t_lst **l, char **s, char **r)
{
	t_lst	*t;
	int		j;

	if (i[4] == 0)
		*r = ft_strdup(*s);
	ft_strdel(s);
	t = *l;
	j = 0;
	while (++j < i[4] + 1)
		t = t->next;
	*s = ft_strdup(t->s);
	tputs(tgetstr("dl", NULL), 1, ft_outc);
	ft_move(i, 0);
	ft_putstr("$> ");
	ft_putstr(*s);
	i[0] = ft_strlen(*s) + 3;
	i[1] = i[0];
	i[4]++;
}
