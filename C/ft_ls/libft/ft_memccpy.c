/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:24:12 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/15 21:55:16 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (s1 && s2)
	{
		i = 0;
		str1 = (unsigned char *)s1;
		str2 = (unsigned char *)s2;
		while (i < n)
		{
			str1[i] = str2[i];
			if (str2[i] == (unsigned char)c)
				return (s1 + i + 1);
			i++;
		}
	}
	return (NULL);
}
