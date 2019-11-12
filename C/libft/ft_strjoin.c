/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:05:57 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/25 15:31:28 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*tmp;
	int		len;

	len = 1;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	ret = (char *) malloc((len) * sizeof(*ret));
	if (ret)
	{
		tmp = ret;
		while (s1 && *s1)
				*tmp++ = *s1++;
		while (s2 && *s2)
				*tmp++ = *s2++;
		*tmp = '\0';
	}
	return (ret);
}
