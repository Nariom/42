/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 17:59:18 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/30 18:00:05 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	ft_ptrstrdel(char ***ptr)
{
	char	**tmp;

	tmp = (ptr) ? *ptr : NULL;
	while (tmp && *tmp)
	{
		ft_strdel(tmp);
		tmp++;
	}
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
