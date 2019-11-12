/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:45:44 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/15 22:00:59 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		while (i < n && s1[i] && s2[i])
		{
			if ((int)(s1[i] - s2[i]) != 0)
				return (0);
			i = i + 1;
		}
		if (i == n || (i != n && s1[i] == s2[i]))
			return (1);
		return (0);
	}
	if (s1 || s2)
		return (0);
	return (1);
}
