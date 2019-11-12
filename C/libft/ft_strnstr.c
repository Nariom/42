/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:55:15 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/30 20:43:08 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;
	size_t	j;

	if (!*s2)
		return ((char *) s1);
	i = 0;
	while (*s1 && i < n)
	{
		str1 = (char *) s1;
		str2 = (char *) s2;
		j = i;
		while (*str1 && *str2 && *str1 == *str2 && j < n)
		{
			str1++;
			str2++;
			j++;
		}
		if (!*str2 || i == n)
			return ((char *) s1);
		s1++;
		i++;
	}
	return (NULL);
}
