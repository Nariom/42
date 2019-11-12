/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 16:36:21 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/01 16:39:56 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data, size_t size)
{
	t_list	*list;

	list = ft_list_last(*begin_list);
	if (list)
		list->next = ft_lstnew(data, size);
	else
		*begin_list = ft_lstnew(data, size);
}
