/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:47:10 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/25 14:56:51 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	ret = NULL;
	if (s)
	{
		ret = (char *) malloc((len + 1) * sizeof(*ret));
		if (ret)
		{
			ret[len] = '\0';
			while (len > 0)
			{
				ret[len - 1] = s[len + start - 1];
				len--;
			}
		}
	}
	return (ret);
}
