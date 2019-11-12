/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:24:35 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/15 22:02:10 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		while (i >= 0)
		{
			if (s[i] == (char)c)
				return ((char *)(s + i));
			i--;
		}
	}
	return (NULL);
}
