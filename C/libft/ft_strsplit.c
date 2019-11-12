/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:30:58 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/09 19:53:18 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbs(char const *s, char c)
{
	int	ret;

	ret = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		ret = (*s) ? ret + 1 : ret;
		while (*s && *s != c)
			s++;
	}
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		k;

	ret = (s) ? (char **) malloc((ft_nbs(s, c) + 1) * sizeof(*ret)) : NULL;
	i = 0;
	k = 0;
	while (ret && s[i])
	{
		j = i;
		while (s[j] && s[j] != c)
			j++;
		ret[k] = (i != j) ? ft_strsub(s, i, j - i) : NULL;
		k = (i != j) ? k + 1 : k;
		i = (i != j) ? j : i + 1;
	}
	if (ret)
		ret[k] = NULL;
	return (ret);
}
