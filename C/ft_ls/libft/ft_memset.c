/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 10:55:36 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/15 21:56:59 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;

	if (b)
	{
		tmp = (char *)b;
		while (len > 0)
		{
			*tmp = (char)c;
			tmp++;
			len--;
		}
	}
	return (b);
}
