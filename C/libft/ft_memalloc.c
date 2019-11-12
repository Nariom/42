/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:38:51 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/27 18:19:33 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;

	res = (void *) malloc(size * sizeof(*res));
	if (res == NULL)
		return (res);
	while (size > 0)
	{
		*((char *) (res + size - 1)) = 0;
		size--;
	}
	return (res);
}
