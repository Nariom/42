/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 15:59:56 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/15 22:00:39 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (s1 && s2)
	{
		while (*s1 && *s2 && *s1 == *s2 && n > 1)
		{
			s1++;
			s2++;
			n--;
		}
		return ((int)(*s1 - *s2));
	}
	if (s1)
		return ((int)*s1);
	if (s2)
		return ((int)(-*s2));
	return (0);
}
