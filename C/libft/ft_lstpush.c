/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 20:26:15 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/01 20:30:06 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list *top, void const *c, size_t s)
{
	t_list	*elem;

	elem = ft_lstnew(c, s);
	if (elem && top)
		elem->next = top;
	return (elem);
}
