/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 15:51:14 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/28 22:06:12 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_new(int i)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (new)
	{
		new->i = i;
		new->next = NULL;
	}
	return (new);
}

void	ft_del(t_list **lst)
{
	if (*lst)
	{
		if ((*lst)->next)
			ft_del(&((*lst)->next));
		free (*lst);
		*lst = NULL;
	}
}

void	ft_push(t_list **lst, t_list *new)
{
	if (lst && *lst && new)
		new->next = *lst;
	if (lst && new)
		*lst = new;
}

t_list	*ft_pull(t_list **lst)
{
	t_list	*ret;

	ret = NULL;
	if (lst && *lst)
	{
		ret = *lst;
		*lst = (*lst)->next;
		ret->next = NULL;
	}
	return (ret);
}

t_list	*ft_last(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
