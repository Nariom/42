/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 21:53:16 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/15 21:53:17 by rbaudot          ###   ########.fr       */
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
