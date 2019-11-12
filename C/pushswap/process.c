/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 16:15:12 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/28 22:23:39 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **lst)
{
	t_list	*tmp;

	if (lst && *lst && (*lst)->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = tmp->next;
		tmp->next = *lst;
		*lst = tmp;
	}
}

void	ft_lr(t_list **lst, t_list **last)
{
	t_list	*tmp;

	if (lst && *lst && *last && *last != *lst)
	{
		(*last)->next = *lst;
		tmp = (*lst)->next;
		(*lst)->next = NULL;
		*last = *lst;
		*lst = tmp;
	}
}

void	ft_rr(t_list **lst, t_list **last)
{
	t_list	*tmp;

	if (lst && *lst && *last && *last != *lst)
	{
		(*last)->next = *lst;
		tmp = *lst;
		*lst = *last;
		while (tmp->next != *last)
			tmp = tmp->next;
		tmp->next = NULL;
		*last = tmp;
	}
}
