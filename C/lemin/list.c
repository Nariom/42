/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 16:11:44 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/06 18:17:32 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lst	*ft_new(char *s)
{
	t_lst	*lst;

	lst = (t_lst *) malloc(sizeof(*lst));
	if (!lst)
		return ((t_lst *) voiderror());
	lst->name = ft_strdup(s);
	if (!(lst->name))
	{
		free(lst);
		return ((t_lst *) voiderror());
	}
	lst->link = NULL;
	lst->next = NULL;
	return (lst);
}

void	ft_add(t_lst **lst, t_lst *new)
{
	if (lst && *lst && new)
		new->next = *lst;
	if (lst && new)
		*lst = new;
}

void	ft_del(t_lst **lst)
{
	t_lst	*tmp;

	while (lst && *lst)
	{
		ft_strdel(&(*lst)->name);
		if ((*lst)->link)
			ft_del(&(*lst)->link);
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	if (lst)
		*lst = NULL;
}

t_lst	*ft_find(t_lst *lst, char *name)
{
	while (lst && ft_strcmp(lst->name, name) != 0)
		lst = lst->next;
	return (lst);
}

void	ft_print(t_lst *lst)
{
	while (lst)
	{
		ft_putstr(lst->name);
		ft_putstr(" ");
		if (lst->link)
		{
			ft_putstr(" || LINKS || ");
			ft_print(lst->link);
			ft_putstr("\n");
		}
		lst = lst->next;
	}
}
