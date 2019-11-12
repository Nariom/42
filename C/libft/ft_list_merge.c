/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 16:30:46 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/01 17:14:19 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_merge(t_list **begin_list1, t_list **begin_list2)
{
	t_list	*list1;

	list1 = ft_list_last(*begin_list1);
	if (list1)
		list1->next = *begin_list2;
	else
		*begin_list1 = *begin_list2;
}
