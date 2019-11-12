/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:16:17 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/27 17:56:29 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*res;

	res = NULL;
	if (s1)
	{
		len = ft_strlen(s1);
		res = (char *) malloc((len + 1) * sizeof(*res));
		if (res)
			res = ft_strcpy(res, s1);
		else
			errno = ENOMEM;
	}
	return (res);
}
