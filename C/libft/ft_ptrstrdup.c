/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 19:31:17 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/25 19:37:22 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_ptrstrdup(char **ptr)
{
	char	**ret;
	char	**tmp;
	int		i;

	if (!ptr)
		return (NULL);
	i = 0;
	tmp = ptr;
	while (tmp[i])
		i++;
	ret = (char **) malloc((i + 1) * sizeof(*ret));
	tmp = ret;
	while (tmp && *ptr)
	{
		*tmp = ft_strdup(*ptr);
		tmp++;
		ptr++;
	}
	if (ret)
		*tmp = NULL;
	return (ret);
}
