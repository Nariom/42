/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 15:57:43 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/01 17:19:17 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*rev;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	rev = ft_strnew(len + 1);
	if (!rev)
		return (NULL);
	rev[len] = '\0';
	while (str && len > 0)
	{
		rev[len - 1] = *str;
		len--;
		str++;
	}
	return (rev);
}
