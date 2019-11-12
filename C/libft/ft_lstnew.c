/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:32:25 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/26 14:07:57 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *) malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->next = NULL;
	if (content)
	{
		list->content = ft_memalloc(content_size);
		if (!list->content)
			return (NULL);
		list->content = ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
		return (list);
	}
	list->content = NULL;
	list->content_size = 0;
	return (list);
}
