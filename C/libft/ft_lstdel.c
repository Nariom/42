/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 21:01:14 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/25 21:22:28 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (*alst)
	{
		while (*alst)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			tmp = (*alst)->next;
			free(*alst);
			*alst = tmp;
		}
		*alst = NULL;
	}
}
