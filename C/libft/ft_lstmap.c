/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 21:31:19 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/26 16:53:59 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;

	ret = NULL;
	if (lst)
	{
		ret = ft_lstnew(lst->content, lst->content_size);
		ret = (*f)(ret);
		lst = lst->next;
	}
	tmp = ret;
	while (lst && tmp)
	{
		tmp->next = ft_lstnew(lst->content, lst->content_size);
		tmp->next = (*f)(tmp->next);
		tmp = tmp->next;
		lst = lst->next;
	}
	ret = (tmp) ? ret : tmp;
	return (ret);
}
