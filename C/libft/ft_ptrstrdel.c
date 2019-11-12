/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrstrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 16:53:07 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/26 17:05:20 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ptrstrdel(char ***ptr)
{
	char	**tmp;

	tmp = (ptr) ? *ptr : NULL;
	while (tmp && *tmp)
	{
		ft_strdel(tmp);
		tmp++;
	}
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
