/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:20:04 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/27 18:10:10 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (n > 0)
		{
			if (*((unsigned char *) (s + i)) == (unsigned char) c)
			{
				return ((void *) (s + i));
			}
			i++;
			n--;
		}
	}
	return (NULL);
}
