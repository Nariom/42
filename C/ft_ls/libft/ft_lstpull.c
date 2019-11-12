/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 20:26:19 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/15 21:54:24 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpull(t_list **top)
{
	t_list	*elem;
	void	*ret;

	ret = NULL;
	if (top && *top)
	{
		elem = *top;
		*top = (*top)->next;
		if (elem->content)
		{
			ret = (void *)malloc(elem->content_size * sizeof(*ret));
			if (ret)
				ret = ft_memcpy(ret, elem->content, elem->content_size);
			free(elem->content);
		}
		free(elem);
	}
	return (ret);
}
