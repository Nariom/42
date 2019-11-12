/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrstrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 18:45:15 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/25 16:53:21 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_ptrstrstr(char **ptr, char *s)
{
	while (ptr && s && *ptr)
	{
		if (ft_strstr(*ptr, s))
			return (ptr);
		ptr++;
	}
	return (NULL);
}
