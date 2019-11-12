/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:44:23 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/25 14:08:18 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	char	*res;

	res = NULL;
	if (s && f)
	{
		tmp = (char *) malloc((ft_strlen(s) + 1) * sizeof(*tmp));
		if (tmp == NULL)
			return (tmp);
		res = tmp;
		while (*s)
		{
			*tmp++ = (*f)(*s++);
		}
		*tmp = '\0';
	}
	return (res);
}
