/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:43:56 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/15 22:03:26 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*str1;
	char	*str2;

	if (s1 && s2)
	{
		if (!*s2)
			return ((char *)s1);
		while (*s1)
		{
			str1 = (char *)s1;
			str2 = (char *)s2;
			while (*str1 == *str2 && *str1 && *str2)
			{
				str1++;
				str2++;
			}
			if (!*str2)
			{
				return ((char *)s1);
			}
			s1++;
		}
	}
	return (NULL);
}
