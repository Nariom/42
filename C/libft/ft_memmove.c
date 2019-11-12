/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:33:56 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/25 18:06:00 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	if (s1 && s2)
	{
		if (s1 <= s2)
			return (ft_memcpy(s1, s2, n));
		else
		{
			while (n > 0)
			{
				*((char *) (s1 + n - 1)) = *((char *) (s2 + n - 1));
				n--;
			}
		}
	}
	return (s1);
}
