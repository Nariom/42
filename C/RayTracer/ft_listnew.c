/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 11:08:04 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/27 11:01:52 by glinford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_lst			*ft_listnew(int opt)
{
	t_lst		*list;

	list = (t_lst *)malloc(sizeof(t_lst));
	if (!list)
		return (NULL);
	list->sphere = (opt == 1) ? (t_sphere *)malloc(sizeof(t_sphere)) : NULL;
	if (opt == 1 && !list->sphere)
		return (NULL);
	list->plane = (opt == 2) ? (t_plane *)malloc(sizeof(t_plane)) : NULL;
	if (opt == 2 && !list->plane)
		return (NULL);
	list->quad = (opt == 4) ? (t_quad *)malloc(sizeof(t_quad)) : NULL;
	if (opt == 4 && !list->quad)
		return (NULL);
	list->next = NULL;
	return (list);
}

t_llst			*ft_llistnew(void)
{
	t_llst		*list;

	list = (t_llst *)malloc(sizeof(t_llst));
	if (!list)
		return (NULL);
	list->next = NULL;
	return (list);
}
