/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/30 19:36:07 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/01 17:18:20 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	int		i;

	i = 1;
	list = NULL;
	while (i < ac)
	{
		if (list)
			ft_list_push_back(&list, av[i], ft_strlen(av[i]));
		else
			list = ft_lstnew(av[i], ft_strlen(av[i]));
		i++;
	}
	return (list);
}
