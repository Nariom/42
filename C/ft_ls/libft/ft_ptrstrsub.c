/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrstrsub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 21:53:48 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/15 21:57:32 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_ptrstrsub(char **ptr, int start, int len)
{
	char	**ret;
	int		i;

	ret = (ptr) ? (char **)malloc((len + 1) * sizeof(ret)) : NULL;
	i = 0;
	while (ret && ptr && ptr[start] && i < len)
		ret[i++] = ft_strdup(ptr[start++]);
	if (ret)
		ret[i] = NULL;
	return (ret);
}
