/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 11:04:08 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/01 14:35:16 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_lst			*ft_listadd(t_lst *list, t_lst *add)
{
	t_lst		*tmp;

	tmp = list;
	if (!list)
		return (add);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = add;
	return (list);
}

t_llst			*ft_llistadd(t_llst *list, t_llst *add)
{
	t_llst		*tmp;

	tmp = list;
	if (!list)
		return (add);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = add;
	return (list);
}
