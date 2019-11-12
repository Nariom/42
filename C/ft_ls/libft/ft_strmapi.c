/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:41:12 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/15 22:00:14 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	res = NULL;
	if (s && f)
	{
		i = 0;
		res = (char *)malloc((ft_strlen(s) + 1) * sizeof(*res));
		if (res == NULL)
			return (res);
		while (s[i])
		{
			res[i] = (*f)(i, s[i]);
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
