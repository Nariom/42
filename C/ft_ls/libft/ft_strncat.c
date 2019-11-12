/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:13:32 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/27 18:00:03 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	if (s1 && s2)
	{
		i = 0;
		len = ft_strlen(s1);
		while (s2[i] && i < n)
		{
			s1[len] = s2[i];
			i++;
			len++;
		}
		s1[len] = '\0';
	}
	return (s1);
}
