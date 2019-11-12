/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:42:35 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/27 18:01:15 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	tot;
	int		i;

	tot = 0;
	if (dst && src)
	{
		len = ft_strlen(dst);
		tot = len + ft_strlen(src);
		if (size < len + 1)
			return (size + ft_strlen(src));
		size = size - len - 1;
		i = 0;
		while (size > 0 && src[i])
		{
			dst[len] = src[i];
			len++;
			i++;
			size--;
		}
		dst[len] = '\0';
	}
	return (tot);
}
