/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 17:05:50 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/01 17:13:36 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	next = *begin_list;
	while (next)
	{
		next = (*begin_list)->next;
		(*begin_list)->next = prev;
		prev = *begin_list;
		*begin_list = (next) ? next : *begin_list;
	}
}
