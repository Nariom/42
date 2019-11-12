/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 16:08:02 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/01 16:11:17 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	int				error;

	i = 1;
	error = 0;
	if (nbr == 0)
		return (NULL);
	while (i < nbr && error == 0)
	{
		error = (begin_list->next) ? 0 : 1;
		begin_list = (begin_list->next) ? begin_list->next : begin_list;
		i++;
	}
	begin_list = (error) ? NULL : begin_list;
	return (begin_list);
}
